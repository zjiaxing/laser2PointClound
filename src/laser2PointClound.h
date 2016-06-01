#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <laser_geometry/laser_geometry.h>

class laser2PointClound
{   
        public:
                laser2PointClound();
                void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan);
        private:
                ros::NodeHandle node_;
                laser_geometry::LaserProjection projector_;
                tf::TransformListener tf_listener_;

                ros::Publisher point_cloud_pub_ ;
                ros::Subscriber scan_sub_;  
        protected:
                std::string p_laser_vertical_frame_;
                std::string p_scan_topic_;
                std::string p_pub_cloud_;         
};
