# Simple ROS node

Really simple ROS example node named *simple_ros_node* with two executables : 

## emitter : 
Emits simple text messages to a rostopic named "*emitter_textmessage*"  at a frequency of 1Hz, message containt the text msg_ID_**\#of the message**.
## reciever : 
Sets up a callback on the "*emitter_textmessage*"  rostopic, prints messages recieved to roscon sole.

## Build :
The project is meant to be run on ROS-melodic and should be built with catkin.

