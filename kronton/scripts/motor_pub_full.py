#!/usr/bin/env python
# license removed for brevity
import rospy

from kronton.msg import motorCon

def talker():
    pub = rospy.Publisher('cmd_dir', motorCon, queue_size=10)
    rospy.init_node('motor_a', anonymous=False)
    rate = rospy.Rate(10) # 10hz
    motor_a=motorCon()
    while not rospy.is_shutdown():
        
        while  True:
            motor_a.IN1 =1
            motor_a.IN2 =0
            motor_a.ENA =100
            pub.publish( motor_a)
            rospy.loginfo("sending motor Direction1")
            rospy.sleep(3)
            motor_a.IN1 =0
            motor_a.IN2 =1
            motor_a.ENA =100
            pub.publish( motor_a)
            rospy.loginfo("sending motor Direction2")
            rospy.sleep(3)
           

    rate.sleep()


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
