
#ifndef BASLER_CAMERA_ADAPTER_H
#define BASLER_CAMERA_ADAPTER_H

#include <iostream>
#include <opencv2/core.hpp>

class BaslerAdapter
{
public:
    std::string getName();
    std::string getType();
    bool initCamera(int frame_rate);
    bool beginAcquisition();
    bool endAcquisition();
    bool setAsMaster();
    bool setAsSlave();
    bool acquireImage(cv::Mat& image);
    bool closeCamera();
};


#endif //BASLER_CAMERA_ADAPTER_H