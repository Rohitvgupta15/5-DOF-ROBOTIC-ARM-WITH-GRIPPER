#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <sensor_msgs/JointState.h>

ros::NodeHandle  nh;

Servo joint1;
Servo joint2;
Servo joint3;
Servo joint4;
Servo joint5;
Servo joint6;

double joint1_angle = 90;
double joint2_angle = 90;
double joint3_angle = 90;
double joint4_angle = 90;
double joint5_angle = 90;
double joint6_angle = 90;

void servo_cb(const sensor_msgs::JointState& cmd_msg){
  joint1_angle = radiansToDegrees(cmd_msg.position[0]);
  joint2_angle = radiansToDegrees(cmd_msg.position[1]);
  joint3_angle = radiansToDegrees(cmd_msg.position[2]);
  joint4_angle = radiansToDegrees(cmd_msg.position[3]);
  joint5_angle = radiansToDegrees(cmd_msg.position[4]);
  joint6_angle = radiansToDegrees(cmd_msg.position[5]);

  joint1.write(joint1_angle);
  joint2.write(joint2_angle);
  joint3.write(joint3_angle);
  joint4.write(joint4_angle);
  joint5.write(joint5_angle);
  joint6.write(joint6_angle);
}

ros::Subscriber<sensor_msgs::JointState> sub("joint_states", servo_cb);

void setup(){
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.subscribe(sub);

  joint1.attach(8);
  joint2.attach(9);
  joint3.attach(10);
  joint4.attach(11);
  joint5.attach(12);
  joint6.attach(13);

  delay(1);
  joint1.write(90);
  joint2.write(90);
  joint3.write(90);
  joint4.write(90);
  joint5.write(90);
  joint6.write(90);
}

void loop(){
  nh.spinOnce();
}

double radiansToDegrees(float position_radians){
  position_radians = position_radians + 1.6;
  return position_radians * 57.2958;
}
