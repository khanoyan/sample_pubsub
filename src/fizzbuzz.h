void fizzbuzz(unsigned int num) {
  if(num%3==0 && num%5==0) {
  	ROS_INFO("Fizzbuzz! [%d]", num);
  }
  else if(num%3==0) {
  	ROS_INFO("Fizz! [%d]", num);
  }
  else if(num%5==0) {
  	ROS_INFO("Buzz! [%d]", num);
  }
  else {
  	ROS_INFO("%d", num);
  }
}