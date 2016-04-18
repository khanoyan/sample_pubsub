#include "ros/ros.h"
//#include "std_msgs/String.h"
//#include "std_msgs/Float64.h"
#include <sample_pubsub/mymsg.h>

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker2");
  ros::NodeHandle n;


  ros::Publisher chatter1_pub = n.advertise<sample_pubsub::mymsg>("my_msg", 1000);

  ros::Rate loop_rate(10);


  int count = 0;
  while (ros::ok())
  {


    sample_pubsub::mymsg msg;

    std::stringstream ss;
    ss << "john";
    msg.first_name = ss.str();
    ss.str("");
    ss << "doe";
    msg.last_name = ss.str();

    // ROS_INFO("%s", msg.data.c_str());

    msg.age = count;
    msg.score = count*4;
    chatter1_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
