# Evaluation of RVIZ

### 1. Introduction

RVIZ is a visualization tool that comes with ROS (Robot Operating System). In ROS you have topics (topics are named buses) to share data. You can select topics in RVIZ which you want to listen to. All future messages which are published over the selected topics will be displayed.  


### 2. Display types

RVIZ can display different display types. The major types are:

* Pose (as arrow or axes)
* Polygon
* Marker (Arrow, Cube, Sphere, Cylinder, ...)
* LIDAR
* color-camera data
* depth-camera data
* ...

For detailed description of the display types see: [http://wiki.ros.org/rviz/DisplayTypes](http://wiki.ros.org/rviz/DisplayTypes)

### 3. Advantages of using RVIZ

**3.1 Tf package**

The *tf package* lets the user keep track of multiple coordinate frames over time and their relationship to each other. It supports easy transformations from one coordinate frame to an other. 

With tf you can go back in time. For example if you want to go to the pose the car had two seconds ago. This is possible because each pose in tf is identifiable by a timestamp and a id.

**3.2 Rosbag**

With *rosbag* you can record the data which is published over ROS. Rosbag creates a compact .bag-file. At a later time the file can be played back. This is a useful debugging feature especially if you have not the possibility to view the data in realtime.

**3.3 URDF**

*URDF* is a XML format representing a robot model. You're able to create your own robot which can be displayed in RVIZ.

### 4. Challenge

Our autonomous system does not use ROS. All the data from the sensors is stored in a .csv-file. To create ROS-messages and -topics from csv at a later time you have two options:

* parse the csv-data and publish the messages over ROS while recording a rosbag. This solution needs a lot of time to create a rosbag file with the correct time stamps.
* rosbag has its own API. There you can find different write-functions to create a message in a bag file ([write-functions in rosbag C++ API](http://docs.ros.org/api/rosbag_storage/html/c++/classrosbag_1_1Bag.html#adc59dfc07b3c9a3f0dc26fdbcdc81786)). Besides the API there is not much documentation about writing rosbag files by yourself.

Example .rosbag file

```
2352 4f53 4241 4720 5632 2e30 0a45 0000
0010 0000 0063 6875 6e6b 5f63 6f75 6e74
3d01 0000 000f 0000 0063 6f6e 6e5f 636f
756e 743d 0400 0000 1200 0000 696e 6465
785f 706f 733d 98d6 0b00 0000 0000 0400
0000 6f70 3d03 bb0f 0000 2020 2020 2020
2020 2020 2020 2020 2020 2020 2020 2020
2020 2020 2020 2020 2020 2020 2020 2020
```
In the latest version of ROS the rosbag files are stored in the rosbag format version 2.0. A detailed description can be found here: [http://wiki.ros.org/Bags/Format/2.0](http://wiki.ros.org/Bags/Format/2.0)

### 5. Conclusion

With RVIZ from ROS you get a stable and secure visualization tool developed by a large active community. With a reasonable amount of time you can create a visualization that fits your needs. But you will always need ROS to use RVIZ. Keep in mind if you haven´t used ROS on your system before, RVIZ together with ROS needs a lot of space. The biggest challenge will be the convertion from the .csv-file to ROS-messages and providing the correct timestamps for the messages.

As an alternative solution to RVIZ a visualization tool can be developed by yourself. With a self developed tool you are more flexible and independent. For C++ you can use the Qt library.