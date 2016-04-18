#include "ros/ros.h"
#include "std_msgs/UInt32.h"

#include <sstream>
#include "fizzbuzz.h"

unsigned int resp = 0;

void buzz_Callback(const std_msgs::UInt32::ConstPtr& msg)
{
  //ROS_INFO("<fizz> got response '%d'", msg->data);
  resp = msg->data;
}


/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "fizz");
  ros::NodeHandle n;

  ros::Publisher  fizz_pub = n.advertise<std_msgs::UInt32>("fizz_msg", 1000);
  ros::Subscriber buzz_sub = n.subscribe("buzz_msg", 1000, buzz_Callback);


  ros::Rate loop_rate(2);


//  int count = 1;
  std_msgs::UInt32 count;
  count.data = 1;

  // fizz to keep saying "1" until it hears a reply from buzz
  do {
    if(ros::ok()) {
      fizz_pub.publish(count);
      //ROS_INFO("<fizz> says %d", count.data);
      fizzbuzz(count.data);
      ros::spinOnce();
      loop_rate.sleep();
    }
    else break; // if ros not ok
  } while(resp != count.data+1);

  // send the next number, wait for the reply, repeat
  while(ros::ok()) {
    count.data = count.data + 2;
    fizz_pub.publish(count);  
    fizzbuzz(count.data);
    //ROS_INFO("<fizz> says %d", count.data);  
    ros::spinOnce();
    loop_rate.sleep();
    while(ros::ok() && resp != count.data+1) {
      ////ROS_INFO("<fizz> waiting for %d", count.data+1);
      ros::spinOnce();
      loop_rate.sleep();
    }
  }

  return 0;
}
