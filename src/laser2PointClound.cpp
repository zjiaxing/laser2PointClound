#include "laser2PointClound.h"

laser2PointClound::laser2PointClound()
{
        ros::NodeHandle private_nh_("~");

        // parameter
        private_nh_.param("laser_vertical_frame", p_laser_vertical_frame_, std::string("laser"));//laser fram_id
        //private_nh_.param("scan_topic", p_scan_topic_, std::string("laser/vertical/scan"));
        private_nh_.param("scan_topic",p_scan_topic_ , std::string("/scan"));//laser pub topic
        private_nh_.param("pub_cloud", p_pub_cloud_, std::string("laser/vertical/cloud"));
       
        scan_sub_ = node_.subscribe("/scan", 100, &laser2PointClound::scanCallback, this);//subscribe the topic
        point_cloud_pub_ = node_.advertise<sensor_msgs::PointCloud2>(p_pub_cloud_, 100, false);
        tf_listener_.setExtrapolationLimit(ros::Duration(0.1));
}

void laser2PointClound::scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
/*
        if(!tf_listener_.waitForTransform(scan->header.frame_id, p_map_frame_, scan->header.stamp, ros::Duration(0.5)))
{
        ROS_INFO("timeout");
        return;
}
*/

        sensor_msgs::PointCloud2 cloud;
        projector_.transformLaserScanToPointCloud(p_laser_vertical_frame_, *scan, cloud, tf_listener_);
        point_cloud_pub_.publish(cloud);
}
