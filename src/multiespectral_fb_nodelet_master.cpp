#include <signal.h>
#include <memory>
#include <filesystem>

#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <std_srvs/Trigger.h>
#include <multiespectral_fb/MultiespectralAcquisitionAction.h>
#include "camera_adapter.h"
#include "BaslerAdapter.h"

std::string IMAGE_PATH;

namespace multiespectral_fb
{
    class MultiespectralAcquireM : public nodelet::Nodelet, public MultiespectralAcquireT<BaslerAdapter>
    {
    protected:
        ros::NodeHandle nh_;
        actionlib::SimpleActionServer<multiespectral_fb::MultiespectralAcquisitionAction> as_;
        std::string action_name_;
        multiespectral_fb::MultiespectralAcquisitionFeedback feedback_;
        int current_frame_rate = 0;
        ros::ServiceClient client;

    public:
        MultiespectralAcquireM() : MultiespectralAcquireT(""),
                                  as_(nh_, "MultiespectralAcquireM", boost::bind(&MultiespectralAcquireM::executeCB, this, _1), false),
                                  client(nh_.serviceClient<std_srvs::Trigger>("multiespectral_slave_trigger_service")) {}

        virtual void onInit()
        {
            nh_ = getNodeHandle();
            ros::NodeHandle private_nh = getPrivateNodeHandle();
            
            private_nh.param<std::string>("dataset_output_path", IMAGE_PATH, "./");
            private_nh.param<int>("frame_rate", current_frame_rate, 10);

            std::string path = IMAGE_PATH + std::string("/") + this->getType() + std::string("/");
            std::filesystem::create_directories(path);
            MultiespectralAcquireT::setImagPath(path);

            ROS_INFO_STREAM("[MultiespectralAcquireM::onInit] Images from " << MultiespectralAcquireT::getName() << " will be stored in path: " << path);
            
            bool result = init(current_frame_rate);

            if (result)
            {
                as_.start();
            }
        }

        bool init(int frame_rate)
        {
            current_frame_rate = frame_rate;
            bool result = MultiespectralAcquireT::init(frame_rate);
            // result = result && setAsMaster();

            // ROS_FATAL_STREAM_COND(!result, "[MultiespectralAcquireM::init] Could not configure " << MultiespectralAcquireT::getName() << " camera as master.");
            // ROS_INFO_STREAM_COND(result, "[MultiespectralAcquireM::init] Initialized " << MultiespectralAcquireT::getName() << " camera as master.");
            
            result = result && beginAcquisition();

            return result;
        }

        void executeCB(const multiespectral_fb::MultiespectralAcquisitionGoalConstPtr &goal)
        {
            feedback_.images_acquired = 0;
            feedback_.storage_path = "";
            ROS_INFO_STREAM("[MultiespectralAcquireM::executeCB] Start image acquisition loop. " << std::string(goal->store ? "S" : "Not s") << "toring images. Frame rate is " << std::to_string(current_frame_rate));

            if (goal->store)
            {
                feedback_.storage_path = img_path;
                ROS_INFO_STREAM("[MultiespectralAcquireM::executeCB] Storing images to " << img_path);
            }

            bool result = true;
            
            ros::Rate loop_rate(current_frame_rate);
            while (ros::ok())
            {
                cv::Mat curr_image;
                result = this->grabStoreImage(curr_image, goal->store);
                if (result)
                {
                    feedback_.images_acquired = feedback_.images_acquired + 1;
                    if (!curr_image.empty())
                    {
                        feedback_.images_acquired = feedback_.images_acquired + 1;
                    }
                    as_.publishFeedback(feedback_);
                }

                std_srvs::Trigger srv;
                if (client.call(srv))
                {
                    ROS_INFO("Trigger Response: %s", srv.response.message.c_str());
                }
                else
                {
                    ROS_ERROR("Failed to call service multiespectral_slave_trigger_service");
                }

                if (as_.isPreemptRequested() || !ros::ok())
                {
                    ROS_INFO("%s: Preempted", action_name_.c_str());
                    as_.setPreempted();
                    break;
                }
                
                loop_rate.sleep();
            }
        }
    }; // End class MultiespectralAcquireM


PLUGINLIB_EXPORT_CLASS(multiespectral_fb::MultiespectralAcquireM, nodelet::Nodelet)
} // namespace multiespectral_fb
