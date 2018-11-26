#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <visualization_msgs/Marker.h>
#include <sstream>



int main(int argc, char** argv){
  ros::init(argc, argv, "cone_publisher");

  ros::NodeHandle n;
  ros::Publisher cone_pub = n.advertise<visualization_msgs::Marker>("cone_publisher", 50);
  tf::TransformListener listener;

  double x_left_cone = 5.0;
  double y_left_cone = -5.0;
  double x_right_cone = 2.0;
  double y_rigth_cone = 2.0;

  ros::Time current_time;
  current_time = ros::Time::now();

  int max_amount_cones = 20;

  ros::Rate rate(1.0);
  int count = 0;
  while (n.ok()){

    if (count > max_amount_cones) {
      count = 0;
    }

    ros::spinOnce(); // check for incoming messages

    /*tf::StampedTransform transform;
    try{

      //listener.waitForTransform("/base_link", "/odom", ros::Time(0), ros::Duration(10.0) );

      listener.lookupTransform("base_link", "base_link",  
                                ros::Time(0), transform);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }*/

    //------------------------------------------------------------
    //publish left cone
    
    current_time = ros::Time::now();

    visualization_msgs::Marker marker;
    marker.header.frame_id = "base_link";
    marker.header.stamp = current_time;
    marker.id = count;

    marker.type = visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;

    //ROS_INFO("transform.getOrigin().x() = %f", transform.getOrigin().x());
    //ROS_INFO("transform.getOrigin().y() = %f", transform.getOrigin().y());



    marker.pose.position.x = x_left_cone; 
    marker.pose.position.y = y_left_cone;
    marker.pose.position.z = 0.0;

    /*marker.pose.orientation.x = transform.getRotation().x();
    marker.pose.orientation.y = transform.getRotation().y();
    marker.pose.orientation.z = transform.getRotation().z();
    marker.pose.orientation.w = 1.0;*/

    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;
    marker.color.a = 1.0;

    //publish the message
    cone_pub.publish(marker);



    //------------------------------------------------------------
    //last_time = current_time;
    ++count;
    rate.sleep();
  }
}