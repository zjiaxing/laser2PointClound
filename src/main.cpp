#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <laser_geometry/laser_geometry.h>
#include "laser2PointClound.h"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "laser2PointClound");

    laser2PointClound m;

    ros::spin();

    return 0;
}
