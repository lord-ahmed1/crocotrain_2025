/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/String.h>
int ledPin = LED_BUILTIN;
ros::NodeHandle  nh;

void messageCb( const std_msgs::String& toggle_msg){
  if(*toggle_msg.data=='h'){digitalWrite(ledPin,HIGH);}
  else{ if(*toggle_msg.data=='l'){digitalWrite(ledPin,LOW);} }
 
}

ros::Subscriber<std_msgs::String> sub("toggle_led", &messageCb );

void setup()
{ 
  pinMode(ledPin, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
