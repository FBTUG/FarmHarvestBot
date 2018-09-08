#!/usr/bin/env python

import rospy
from harvest_try1.msg import FruitCnt

#every 10 second fruit_cnt=1
def vision_pub():
    pub = rospy.Publisher('vision_fruit_cnt', FruitCnt, queue_size=10)
    rospy.init_node('vision_pub')
    rate = rospy.Rate(10) # 10hz 
    
    message = FruitCnt()
    message.fruit_cnt=0
    check_cnt=0
    
    while not rospy.is_shutdown():
        check_cnt += 1
        if 	check_cnt % 100 ==0:
            message.fruit_cnt = (message.fruit_cnt+1)%2

        pub.publish(message)
        rate.sleep()

if __name__ == '__main__':
    try:
        vision_pub()
    except rospy.ROSInterruptException:
        pass
