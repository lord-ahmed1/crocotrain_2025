#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from random import randint

if __name__=="__main__":
    rospy.init_node("led_toggler")
    rospy.loginfo("toggle_led started")
    pub=rospy.Publisher("toggle_led",String,queue_size=10)
    rate=rospy.Rate(1)
    while not rospy.is_shutdown():
        msg=input("enter msg")
        pub.publish(msg)
        rospy.loginfo("message sent")
        rate.sleep()

    