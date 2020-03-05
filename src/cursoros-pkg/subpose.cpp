//gerenciador de velocidades randomicas para turtlesim

#include<ros/ros.h>
#include<turtlesim/Pose.h>
#include<iomanip>// for std::setprecision and std::fixed

//callback function. executa toda vez que uma nova msg chega em pose.
void poseMessageReceived(const turtlesim::Pose &msg)
{
    ROS_INFO_STREAM(std::setprecision(2) << std::fixed
            << "position=( " << msg.x << "|" << msg.y << ")"
            << " direction= " << msg.theta
            );
}


int main(int argc, char **argv)
{
    ros::init(argc,argv, "subscribe_to_pose");
    ros::NodeHandle nh;

    //cria objeto inscrito
    ros::Subscriber sub = nh.subscribe("turtle1/pose", 1000, &poseMessageReceived);

    //deixa o ROS assumir o controle
    ros::spin();
    
}
