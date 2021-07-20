#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

/*
  Emits dummy messages to the "emitter_textmessage" topic
*/
int main(int argc, char **argv)
{

  // Initialize the ROS node
  ros::init(argc, argv, "emitter");
  ros::NodeHandle n;

  // advertise the topic
  ros::Publisher text_pub = n.advertise<std_msgs::String>("emitter_textmessage", 1000);

  // set main loop to a rate of 1Hz
  float rate = 1;
  ros::Rate loop_rate(rate);

  // Main Loop
  int count = 0;
  while (ros::ok())
  {
    
    std_msgs::String msg;

    // construct the text messages
    std::stringstream ss;
    ss << "msg_ID_" << count;
    msg.data = ss.str();

    // print out what we send to rosconsole
    ROS_INFO("%s", msg.data.c_str());

    // publish to the topic
    text_pub.publish(msg);

    // here for good practice (it is good practice according to the
    // ROS wiki) but useless in this executable as we don't have any callbacks
    ros::spinOnce();

    // sleep to ensure loop rate 1Hz
    loop_rate.sleep();

    ++count;
  }


  return 0;
}