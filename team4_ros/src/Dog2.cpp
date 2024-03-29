#include "ros/ros.h"
#include <stdlib.h>
#include "std_msgs/Empty.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/LaserScan.h>
#include <tf/tf.h>
#include <queue>
#include <sstream>
#include "math.h"
#include <unistd.h>
#include <time.h> 

// Current velocity of the Robot
geometry_msgs::Twist currentVelocity;

// Current location of the robot
geometry_msgs::Pose currentLocation;

// The current angle of the robot
double currentAngle;

// Pub object
ros::Publisher mypub_object;

// Speed and angular velocity when sensor detects something
int x;
float z;

// Set by sensorCallback when robot is near an obstacle
bool nearCollision;

// Index that points to current position in path index
int pathIndex;

// boolean checks if the destination is at the tree and if it is then call the nav function
bool atTree = false;

geometry_msgs::Point desiredLocations[5];

bool checkLocation(){
if (currentVelocity.linear.x == 0 && currentVelocity.angular.z == 0.0){

    return true;
}else{

    return false;
}
}



void sensorCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
    int i = 0;
    bool isNear = false;
    ROS_INFO("Sensor:");
    for (i; i < 180; i++) {
        if (msg->ranges[i] < 1)
        {
            isNear = true;
            nearCollision = true;
            ROS_INFO("I'm near something! [%f]", msg->ranges[i]);

            if (i < 60)
            {
                // Spin to the left
                ROS_INFO("Spinning left");
                currentVelocity.linear.x = 1;
                currentVelocity.angular.z = 0.5;
            } else if (i >= 60 && i < 120)
            {
                // Move backwards and spin right
                ROS_INFO("Moving backwards and spinning right");
                currentVelocity.linear.x = 0;
                currentVelocity.angular.z = -1.0;
            } else
            {
                // Spin to the right
                ROS_INFO("Spinning right");
                currentVelocity.linear.x = 1;
                currentVelocity.angular.z = -0.5;
            }

        }

        if (isNear == false)
        {
            nearCollision = false;
            //currentVelocity.linear.x = 0;
            //currentVelocity.angular.z = 0.0;
        }
        
        mypub_object.publish(currentVelocity);

    }
}


void generateRandomSpeed(){
    // set up for random number generation
    srand (time(NULL));
    currentVelocity.linear.x = rand() % 4 + 2;;

}

void generateRandomDesiredLocations(){
    // set up for random number generation
    srand (time(NULL));

    // Setup points on robot's path
    geometry_msgs::Point desiredLocation1;
    //desiredLocation1.x = -10;
    desiredLocation1.x = rand() % 10 + 1;
    //desiredLocation1.y = -21;
    desiredLocation1.y = rand() % 10 + 1;
    desiredLocation1.z = 0;

    geometry_msgs::Point desiredLocation2;
    //desiredLocation2.x = 10;
    desiredLocation2.x = rand() % 10 + 1;
    //desiredLocation2.y = 21;
    desiredLocation2.y = -1 * (rand() % 10 + 1);
    desiredLocation2.z = 0;

    desiredLocations[0] = desiredLocation1;
    desiredLocations[1] = desiredLocation2;


}

void updateCurrentVelocity() {

    //generateRandomSpeed();

    if (nearCollision == true)
    {
        // Let collision resolution take place before we attempt to move towards the goal
        return;
    }

    // Find the correct angle

    geometry_msgs::Point desiredLocation = desiredLocations[pathIndex];
    // This is the maximum distance a robot can be from it's
    // desired poisition and still be considered to have reached it
    float distanceThreshold = 0.5;

    geometry_msgs::Point directionVector; // Vector from currentLocation to desiredLocation
    directionVector.x = desiredLocation.x - currentLocation.position.x;
    directionVector.y = desiredLocation.y - currentLocation.position.y;
    directionVector.z = desiredLocation.z - currentLocation.position.z;

    ROS_INFO("X distance: [%f]", directionVector.x);
    ROS_INFO("Y distance: [%f]", directionVector.y);

    // Check if we are at the desired location
    if (abs(directionVector.x) <= distanceThreshold && abs(directionVector.y) <= distanceThreshold)
    {
        // Robot has reached it's desired location
        // For now, make robot stop. In future, robot should now try to move
        // to the next location on it's path.
        ROS_INFO("I have reached my destination!");
        ROS_INFO("pathindex");
        
        currentVelocity.linear.x = 0;
        currentVelocity.angular.z = 0.0;
        if (pathIndex < sizeof(desiredLocations) / sizeof(*desiredLocations) - 1)
        {    

            if(pathIndex == 1){
                atTree = true;
                ROS_INFO("at destination 2")
            }

            if(pathIndex == 2){
                 ROS_INFO("at destination 3")
                atTree = true;
            }

            if(pathIndex == 3){

                 ROS_INFO("at destination 4")
                atTree = true;
            }

            pathIndex++;
        }
        else
        {
            // Reset index
            ROS_INFO("Reached final destination, going back to the start");

            pathIndex = 0;
        }
        
        return;
    }
    
    // Calculate the desired angle
    double desiredAngle = atan2(directionVector.y, directionVector.x);

    if (z != 0)
    {
        currentVelocity.linear.x = 4;
        currentVelocity.angular.z = z;
        return;
    }

    // If the desired angle is 0
    if(desiredAngle != 0 && desiredAngle != M_PI)
    {    
        //ROS_INFO("currentAngle is : %f",currentAngle); 
        //ROS_INFO("desiredAngle is : %f",desiredAngle); 

        // If the deifference between current angle and desired angle is less than 0.1 stop spining
        if (currentAngle - desiredAngle > 0.1 || desiredAngle - currentAngle > 0.1)
        {
            // Spin
            currentVelocity.linear.x = 0;
            currentVelocity.angular.z = 0.5;
            
        } else
        {
            // Go forward
            currentVelocity.linear.x = 2;
            currentVelocity.angular.z = 0;
        }
    }
}



void groundTruthCallback(const nav_msgs::Odometry msg) 
{     
    //Update Current Position
    currentLocation = msg.pose.pose;
    double x = currentLocation.orientation.x;
    double y = currentLocation.orientation.y;
    double z = currentLocation.orientation.z;
    double w = currentLocation.orientation.w;
    
    double roll, pitch, yaw;
    tf::Matrix3x3(tf::Quaternion(x, y, z, w)).getRPY(roll, pitch, yaw);
    currentAngle = yaw;
    //ROS_INFO("Yaw is : %f",yaw); 
    
}

void navigation(){

    for(int i = 0;i <10000000;i++){
        ROS_INFO("I'm trying to run around the tree.");
        
        currentVelocity.angular.z =2; 
        currentVelocity.linear.x = 1;
    }

}

int main (int argc, char **argv) 
{

    //tree 1
    geometry_msgs::Point desiredLocation3;
    //desiredLocation1.x = -10;
    desiredLocation3.x = 3.5;
    //desiredLocation1.y = -21;
    desiredLocation3.y = 15.5;
    desiredLocation3.z = 0;

    // tree 2
    geometry_msgs::Point desiredLocation4;
    //desiredLocation1.x = -10;
    desiredLocation4.x = 3.5;
    //desiredLocation1.y = -21;
    desiredLocation4.y = 20.5;
    desiredLocation4.z = 0;

    // tree 3
    geometry_msgs::Point desiredLocation5;
    //desiredLocation1.x = -10;
    desiredLocation5.x = 3.5;
    //desiredLocation1.y = -21;
    desiredLocation5.y = 25.5;
    desiredLocation5.z = 0;


    desiredLocations[2] = desiredLocation3;
    desiredLocations[3] = desiredLocation5;
    desiredLocations[4] = desiredLocation5;

    // generates random locations
    generateRandomDesiredLocations()

    pathIndex = 0;


    nearCollision = false;    

    // command line ROS arguments/ name remapping 
    ros::init(argc, argv, "DogNode2"); 

    // ROS node hander
    ros::NodeHandle velPub_handle;
    ros::NodeHandle sub_handle; 
        ros::NodeHandle bark_handle;

    // master registry pub and sub
    //ros::Publisher mypub_object = velPub_handle.advertise<geometry_msgs::Twist>("robot_0/cmd_vel",1000);
        mypub_object = velPub_handle.advertise<geometry_msgs::Twist>("robot_1/cmd_vel",1000);
        ros::Publisher mypub_bark = bark_handle.advertise<std_msgs::String>("dog_topic",1000);
    ros::Subscriber mysub_object;
    
    // loop 10 
    ros::Rate loop_rate(10);

    mysub_object = sub_handle.subscribe<nav_msgs::Odometry>("robot_1/base_pose_ground_truth",1000, groundTruthCallback);

        // ROS comms access point 
    ros::NodeHandle n;

        ros::Subscriber sub = n.subscribe("robot_1/base_scan", 1000, sensorCallback);


    while (ros::ok()) 
    { 
        loop_rate.sleep();

        updateCurrentVelocity(); 
        // refer to advertise msg type 

        mypub_object.publish(currentVelocity); 

        z=0;

        if(checkLocation() && atTree){          
            navigation();
       }

        ros::spinOnce();
        loop_rate.sleep();
    } 

    /*

        while (ros::ok()) 
    { 
                loop_rate.sleep();
                navigation();
                std_msgs::String mypub_msg;
        mypub_msg.data = "I AM BARKING!!Woof Woof!!";        
        ros::spinOnce();
        loop_rate.sleep();

        }
    */
    return 0; 
}
