# rviz_sandbox

### Description

Sandbox for rviz where publisher, urdf and tf-functions will be tested.


### Prerequisites

* installed ROS
* copy this package into your catkin_workspace


### Getting this thing running

Build and start the simulation:

```
cd ~/catkin_ws
catkin_make
roslaunch rviz_sandbox odom_publisher.launch
```

The "odom_publisher.launch"-file does:

* start rviz with urdf model
* start odometry_publisher
* start cone_publisher