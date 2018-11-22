#include "ros/ros.h"
//#include <geometry_msgs/PointStamped.h>
//#include <geometry_msgs/Point.h>
#include <visualization_msgs/Marker.h>
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "rviz_publisher"); //node name

  ros::NodeHandle n;

  ros::Publisher rviz_pub = n.advertise<visualization_msgs::Marker>("marker_publisher", 100); //topic name

  ros::Rate loop_rate(1); // run with 10 Hz


  ROS_INFO("marker_publisher started.");

  int count = 0;
  while (ros::ok())
  {

    visualization_msgs::Marker marker;
    marker.header.frame_id = "odom";
    marker.header.stamp = ros::Time(); // 0 -> always displayed marker
    marker.id = count;

    marker.type = visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;

    marker.pose.position.x = count; //move x position over time
    marker.pose.position.y = 1;
    marker.pose.position.z = 1;

    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;
    marker.color.a = 1.0;

    ROS_INFO("published messages: x:%f, y:%f, z:%f", marker.pose.position.x, marker.pose.position.y, marker.pose.position.z);
    rviz_pub.publish(marker);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}