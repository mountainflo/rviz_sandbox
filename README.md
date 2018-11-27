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
roslaunch rviz_sandbox circle_track_with_cones.launch
```

The "circle_track_with_cones.launch"-file does:

* start rviz with urdf model
* start odometry_publisher (drive a circle with the car)
* start cone_publisher (publish blue and yellow cones)