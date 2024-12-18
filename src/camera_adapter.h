
#ifndef CAMERA_ADAPTER_H
#define CAMERA_ADAPTER_H

#include <mutex>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "ros/ros.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>


template <typename CameraType>
class MultiespectralAcquireT : public CameraType
{
protected:
    std::string img_path = "";
    std::mutex camera_mutex; // Avoid deinitialization while grabbing image
    
    ros::NodeHandle nh_;
    image_transport::Publisher image_pub_;
public:
    std::string getTimeTag();
    MultiespectralAcquireT(std::string img_path);
    ~MultiespectralAcquireT(void);
    bool init(int frame_rate);
    bool grabStoreImage(cv::Mat& image, bool store = true);
    bool changeFrameRate(int frame_rate);
    
    // see function definition
    void dummyCallback(const sensor_msgs::ImageConstPtr& msg);

    void setImagPath(std::string path)
    {
        img_path = path;
    }
};

template <typename CameraType> 
std::string MultiespectralAcquireT<CameraType>::getTimeTag() {
    auto now = std::chrono::system_clock::now();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::time_t timeNow = std::chrono::system_clock::to_time_t(now);
    
    std::tm* tmNow = std::localtime(&timeNow);

    std::ostringstream oss;
    oss << std::put_time(tmNow, "%y-%m-%d_%H-%M-%S_") << std::setw(3) << std::setfill('0') << millis.count();

    return oss.str();
}

template <typename CameraType> 
bool MultiespectralAcquireT<CameraType>::init(int frame_rate)
{
    bool result = this->initCamera(frame_rate);
    ROS_FATAL_STREAM_COND(!result, "[MultiespectralAcquireT] Could not initialize " << this->getName() << " camera.");
    return result;
}

template <typename CameraType> 
bool MultiespectralAcquireT<CameraType>::changeFrameRate(int frame_rate)
{
    ROS_INFO_STREAM("[MultiespectralAcquireT::changeFrameRate] Closing camera to setup new frame rate to: " << frame_rate);
    bool result = this->closeCamera();
    result = result & this->init(frame_rate);
    return result;
}


template <typename CameraType> 
MultiespectralAcquireT<CameraType>::MultiespectralAcquireT(std::string img_path) : img_path(img_path)
{
    image_transport::ImageTransport it(nh_);
    image_pub_ = it.advertise(this->getType()+"_image", 1);
}

template <typename CameraType> 
MultiespectralAcquireT<CameraType>::~MultiespectralAcquireT(void)
{   
    const std::scoped_lock<std::mutex> lock(camera_mutex);
    bool result = this->closeCamera();
    ROS_FATAL_STREAM_COND(!result, "[MultiespectralAcquireT] Could not finish correctly " << this->getName() << " camera.");
    ROS_INFO_STREAM_COND(result, "[MultiespectralAcquireT] Correctly finished " << this->getName() << " camera.");
}

template <typename CameraType> 
bool MultiespectralAcquireT<CameraType>::grabStoreImage(cv::Mat& curr_image, bool store)
{

    const std::scoped_lock<std::mutex> lock(camera_mutex);
    bool result =  this->acquireImage(curr_image);
    if (result && !curr_image.empty() && store) 
    {
        std::ostringstream filename;
        filename << img_path << "/" << getTimeTag() << ".png";
        cv::imwrite(filename.str().c_str(), curr_image);
    } 
    
    // Convert to a sensor_msgs::Image message detecting encoding
    if (result && !curr_image.empty())
    {
        std::string encoding;
        if (curr_image.type() == CV_8UC3) {
            encoding = "bgr8";
        } else if (curr_image.type() == CV_8UC1) {
            encoding = "mono8";
        } else {
            std::cerr << "Unsupported image type: " << curr_image.type() << std::endl;
            return false;
        }
        sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), encoding, curr_image).toImageMsg();
        image_pub_.publish(msg);
        ros::spinOnce(); // without explicit spinOnce, the LWIR image is as black (rgb is ok...). The info stream also works?¿
        //ROS_INFO_STREAM("Published image with encoding: " << encoding);
    }

    ROS_ERROR_STREAM_COND(!result, "[MultiespectralAcquireT::grabStoreImage] Could not acquire image from " << this->getName() << " camera.");
    ROS_ERROR_STREAM_COND(curr_image.empty(), "[MultiespectralAcquireT::grabStoreImage] Image is empty for " << this->getName() << " camera.");
    return result;
}



#endif //CAMERA_ADAPTER_H