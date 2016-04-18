#include "ros/ros.h"
#include "std_msgs/UInt32.h"
#include "fizzbuzz.h"

unsigned int resp = 0;

void fizz_Callback(const std_msgs::UInt32::ConstPtr& msg)
{
  //ROS_INFO("<buzz> got response '%d'", msg->data);
  resp = msg->data;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "buzz");
  ros::NodeHandle n;

  unsigned int exp_resp = 1;
  std_msgs::UInt32 count;

  ros::Publisher  buzz_pub = n.advertise<std_msgs::UInt32>("buzz_msg", 1000);
  ros::Subscriber fizz_sub = n.subscribe("fizz_msg", 1000, fizz_Callback);

  ros::Rate loop_rate(10);

  //  wait until we get first message from Fizz
  while(resp == 0 && ros::ok()) {
    ros::spinOnce();    
    loop_rate.sleep();
  }

  // send and print reply
  // wait for fizz to reply back
  while(ros::ok()) {
    if(resp ==  exp_resp) {
      //ROS_INFO("<buzz> says %d", exp_resp+1);
      count.data = exp_resp+1;
      buzz_pub.publish(count);
      fizzbuzz(count.data);
      exp_resp += 2;
    }
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}

