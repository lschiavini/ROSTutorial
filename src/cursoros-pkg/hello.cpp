//"Hello World" no ROS
//Define as classes padrões do ROS
#include <ros/ros.h>


int main(int argc, char **argv)
{
    
    //inicializa o sistema ROS
    //Ultimo parametro é o nome padrão do nó
    ros::init(argc, argv, "hello_ros");
    
    ros::Rate rate(1);//taxa-hz

    //estabelece esse programa como um nó do ROS
    ros::NodeHandle nh;

    //Manda algo como mensagem de log
    ROS_INFO_STREAM("Hello, ROS!");

    rate.sleep();

}