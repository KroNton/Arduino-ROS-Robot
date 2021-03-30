#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import Bool





def talker():
    pub = rospy.Publisher('cmd_dir', Bool, queue_size=10)
    rospy.init_node('motor_a', anonymous=False)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        
        while  True:
            x = True
            bool(x)
            rospy.loginfo("sending motor Direction1")
            pub.publish(x)
            rospy.sleep(3)
            x = False
            rospy.loginfo("sending motor Direction2")
            pub.publish(x)
            rospy.sleep(3)

    rate.sleep()


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
