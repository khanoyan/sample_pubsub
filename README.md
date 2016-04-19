# sample_pubsub
Sample code and configuration to get easily started with creating ROS pubsub nodes

Make sure ROS is properly installed on your machine by follow these instructions:

http://gcc-robotics.github.io/robot-motion-planning-labs/lab0-setting-up/

**A. Create Catkin workspace in your home directory:**
 
  $ mkdir -p ~/catkin_ws/src
  

**B. Initialize the workspace:**
 
  $ cd ~/catkin_ws/src
  $ catkin_init_workspace
  $ cd ~/catkin_ws
  $ catkin_make

**C. Load the proper environment:**

  $ source devel/setup.bash


**D. Verify that your workspace is in ROS's path:**

  $ echo $ROS_PACKAGE_PATH

  *YOU SHOULD SEE: /home/YOUR_USER_NAME/catkin_ws/src:/opt/ros/indigo/share:/opt/ros/indigo/stacks*


**E. Clone the sample code from GitHub**

  $ cd ~/catkin_ws/src
  $ git clone https://github.com/khanoyan/sample_pubsub.git


**F. Build the code. Note that there's currently a bug that requires running
   catkin_make TWICE. The first time it'll throw an error. Second time it'll
   work. This has to do with dependencies not being properly configured.**
   
  $ cd ~/catkin_ws
  $ catkin_make
  $ catkin_make
