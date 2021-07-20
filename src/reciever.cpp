#include "ros/ros.h"
#include "std_msgs/String.h"

// Message recieved callback
void text_msg_callback(const std_msgs::String::ConstPtr& msg)
{
    // Print callback to rosconsole
    ROS_INFO("Recieved: [%s]", msg->data.c_str());
}

/*
  Recieves text messages on the "emitter_textmessage" topic
*/
int main(int argc, char **argv)
{

    // Initialize the ROS node
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    ROS_INFO("Listener Node Online");

    // Subscribe to the emitter topic, setup callback
    ros::Subscriber sub = n.subscribe("emitter_textmessage", 1000, text_msg_callback);

    // Wait for callbacks
    ros::spin();

    return 0;
}