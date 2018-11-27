#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <std_msgs/ColorRGBA.h>


int main(int argc, char** argv){
  ros::init(argc, argv, "cone_publisher");

  ros::NodeHandle n;
  ros::Publisher cone_pub = n.advertise<visualization_msgs::Marker>("cone_publisher", 50);

  //-----------------------------
  // define cone positions
  double x_left_cone = 3.0;
  double y_left_cone = -4.0;
  double x_right_cone = 5.0;
  double y_right_cone = 0.0;

  ros::Time current_time = ros::Time::now();

  int max_amount_cones = 20;

  ros::Rate rate(1.0); //rate in Hz
  int count = 0;
  while (n.ok()){

    if (count > max_amount_cones) {
      count = 0;
    }

    ros::spinOnce(); //check for incoming messages

    current_time = ros::Time::now(); //specify time for both cones


    //------------------------------------------------------------
    //publish left cone

    visualization_msgs::Marker marker_left_cone;
    marker_left_cone.header.frame_id = "base_link"; //publish to coordinate frame of the urdf-car-model
    marker_left_cone.header.stamp = current_time;
    marker_left_cone.id = count;

    marker_left_cone.type = visualization_msgs::Marker::SPHERE;
    marker_left_cone.action = visualization_msgs::Marker::ADD;

    marker_left_cone.pose.position.x = x_left_cone; 
    marker_left_cone.pose.position.y = y_left_cone;
    marker_left_cone.pose.position.z = 0.0;

    marker_left_cone.scale.x = 0.5;
    marker_left_cone.scale.y = 0.5;
    marker_left_cone.scale.z = 0.5;

    marker_left_cone.color.r = 0.0;
    marker_left_cone.color.g = 0.0;
    marker_left_cone.color.b = 1.0;
    marker_left_cone.color.a = 1.0;

    cone_pub.publish(marker_left_cone);


    //------------------------------------------------------------
    //publish right cone
    
    visualization_msgs::Marker marker_right_cone;
    marker_right_cone.header.frame_id = "base_link";
    marker_right_cone.header.stamp = current_time;
    marker_right_cone.id = ++count;

    marker_right_cone.type = visualization_msgs::Marker::SPHERE;
    marker_right_cone.action = visualization_msgs::Marker::ADD;

    marker_right_cone.pose.position.x = x_right_cone; 
    marker_right_cone.pose.position.y = y_right_cone;
    marker_right_cone.pose.position.z = 0.0;

    marker_right_cone.scale.x = 0.5;
    marker_right_cone.scale.y = 0.5;
    marker_right_cone.scale.z = 0.5;

    marker_right_cone.color.r = 1.0;
    marker_right_cone.color.g = 1.0;
    marker_right_cone.color.b = 0.0;
    marker_right_cone.color.a = 1.0;
    
    cone_pub.publish(marker_right_cone);



    //------------------------------------------------------------
    ++count;
    rate.sleep();
  }
}