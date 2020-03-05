//gerenciador de velocidades randomicas para turtlesim

#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<stdlib.h>//rand() e RAND_MAX

int main(int argc, char **argv)
{
    ros::init(argc,argv, "publish_velocity");
    ros::NodeHandle nh;

    //cria objeto publicador
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

    //semente do gerador de num rand
    srand(time(0));

    //loop a 2Hz até que o nó seja desligado
    ros::Rate rate(2);
    while(ros::ok())
    {
        //cria a msg
        geometry_msgs::Twist msg;
        msg.linear.x = double(rand())/double(RAND_MAX);
        msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;

        //publica a msg
        pub.publish(msg);

        //manga msg para o rosout com detalhes.
        ROS_INFO_STREAM("Sending random velocity command:"
                << "linear = " <<msg.linear.x
                << "\n angular = " <<msg.angular.z);
        
        //espera até a proxima iteração
        rate.sleep();
    }



}
