/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <kronton/motorCon.h>

#define in1 7
#define in2 8
#define enA 6
ros::NodeHandle  nh;

void motor_Cb( const kronton::motorCon& cmd_dir){
  
  digitalWrite(in1,(cmd_dir.IN1));
  digitalWrite(in2,(cmd_dir.IN2));
  digitalWrite(enA,(cmd_dir.ENA));
  // blink the led
 digitalWrite(LED_BUILTIN,(cmd_dir.IN1));
}

ros::Subscriber<kronton::motorCon> sub("cmd_dir", &motor_Cb );

void setup()
{ 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
