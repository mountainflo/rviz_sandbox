# Evaluation of RVIZ

### 1. Introduction

RVIZ is a visualization tool that comes with ROS. In ROS you have topics (topics are named buses) to share data. You can select topics in RVIZ which you want to listen to. All future messages published over the selected topics will be displayed.  


### 2. Display types

RVIZ can display different display types. The major types are:

* Pose (as arrow or axes)
* Polygon
* Marker (Arrow, Cube, Sphere, Cylinder, ...)
* LIDAR
* color-camera data
* depth-camera data
* ...

### 3. Advantages of using RVIZ

**3.1 Tf package**

The *tf package* lets the user keep track of multiple coordinate frames over time and their relationship to each other. It supports easy transformation from one coordinate frame to an other. 

With tf you can go back in time. For example if you want to go to the pose the car had two seconds ago. This is possible because each pose in tf is identifiable by a timestamp and a id.

**3.2 Rosbag**

With *rosbag* you can record data which is published over ROS. At a later time the data can be played back. This is a useful debugging feature especially if you have not the possibility to view the data in realtime.

**3.3 URDF**

*URDF* is a XML format representing a robot model. You're able to create your own robot which can be displayed in RVIZ.


### 4. Conclusion

With RVIZ from ROS you get a stable and secure visualization tool developed by a large active community. With a reasonable amount of time you can create a visualization that fits your needs. But you will always need ROS to use RVIZ. Keep in mind if you haven´t used ROS on your system before, RVIZ together with ROS needs a lot of space.

As an alternative solution to RVIZ a visualization tool can be developed by yourself. With a self developed tool you are more flexible and independent. For C++ you can use the Qt library.