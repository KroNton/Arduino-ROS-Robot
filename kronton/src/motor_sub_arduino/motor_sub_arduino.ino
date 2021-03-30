/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Bool.h>

#define IN1 7
#define IN2 8

ros::NodeHandle  nh;

void motor_Cb( const std_msgs::Bool& cmd_dir){
  
  digitalWrite(IN1,(cmd_dir.data));
  // blink the led
 digitalWrite(LED_BUILTIN,(cmd_dir.data));
}

ros::Subscriber<std_msgs::Bool> sub("cmd_dir", &motor_Cb );

void setup()
{ 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
