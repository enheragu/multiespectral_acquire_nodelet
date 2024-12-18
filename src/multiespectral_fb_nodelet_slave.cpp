

#include <filesystem>
#include <ros/ros.h>

#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <std_srvs/Trigger.h>

#include "camera_adapter.h"
#include "FlirAdapter.h"

std::string IMAGE_PATH;

namespace multiespectral_fb
{
    class MultiespectralAcquireS : public nodelet::Nodelet, public MultiespectralAcquireT<FlirAdapter>
    {
    protected:
        int current_frame_rate = 0;

    public:
        MultiespectralAcquireS() : MultiespectralAcquireT("") {}

        virtual void onInit()
        {
            ros::NodeHandle &nh = getNodeHandle();
            ros::NodeHandle &private_nh = getPrivateNodeHandle();

            private_nh.param<std::string>("dataset_output_path", IMAGE_PATH, "./");
            private_nh.param<int>("frame_rate", current_frame_rate, 10);

            std::string path = IMAGE_PATH + std::string("/") + this->getType() + std::string("/");
            std::filesystem::create_directories(path);
            ROS_INFO_STREAM("[MultiespectralAcquireS::onInit] Images from " << MultiespectralAcquireT::getName() << " will be stored in path: " << path);
            MultiespectralAcquireT::setImagPath(path);

            bool result = init(current_frame_rate);

            ros::ServiceServer service = nh.advertiseService("multiespectral_slave_trigger_service", &MultiespectralAcquireS::triggerCallback, this);
        }

        bool init(int frame_rate)
        {
            current_frame_rate = frame_rate;
            bool result = MultiespectralAcquireT::init(frame_rate);
            // result = result && setAsSlave();

            // ROS_FATAL_STREAM_COND(!result, "[MultiespectralAcquireS::init] Could not configure " << MultiespectralAcquireT::getName() << " camera as slave.");
            // ROS_INFO_STREAM_COND(result, "[MultiespectralAcquireS::init] Initialized " << MultiespectralAcquireT::getName() << " camera as slave.");

            result = result && beginAcquisition();

            return result;
        }

        bool execute()
        {
            bool result = false;
            ROS_INFO_STREAM("[MultiespectralAcquireS::execute] Aqcuire image.");

            cv::Mat curr_image;
            result = this->grabStoreImage(curr_image);
            ros::spinOnce();
            
            return result;
        }

        bool triggerCallback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res)
        {
            ROS_INFO("[MultiespectralAcquireS::triggerCallback] Trigger received");
            bool ret = this->execute();
            res.success = ret;
            res.message = "Triggered successfully. Image captured: " + std::to_string(ret);
            // Aquí puedes implementar la lógica de tu función de trigger
            return true;
        }
    }; // End class MultiespectralAcquireS

PLUGINLIB_EXPORT_CLASS(multiespectral_fb::MultiespectralAcquireS, nodelet::Nodelet)
} // namespace multiespectral_fb
