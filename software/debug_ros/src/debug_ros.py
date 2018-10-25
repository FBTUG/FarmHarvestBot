#!/usr/bin/env python
# VERSION history:
#    0.0.2 - serial cli debug example with ROS_SerialCommandExample 
import rospy
import rosnode
import rosbag
from std_msgs.msg import String
import cmd
import time

VERSION = "0.0.2"
CMD_VERSION = "0.1"
rcli = None

#ros_debug CLI
class RosDebugCli(cmd.Cmd):
    """ros_debug CLI"""

    def __init__(self):
        cmd.Cmd.__init__(self)
        self.prompt = 'CLI>'
        self.scli_pub = None #scli pub
        self.scli_sub = None #scli sub

############ cli maintain ####################
    def do_quit(self, line):
        """quit"""

        return True
    def do_version(self,line):
        """Report software version"""
        output = "V" + VERSION
        print(output)
############ commands  ####################
    def do_test(self,line):
        """Current test function"""
        nodes = rosnode.get_node_names()
        rospy.loginfo("node list:%s" %(nodes))

    def do_dump(self,line):
        """Dump information"""
        nodes = rosnode.get_node_names()
        rospy.loginfo("node list:%s" %(nodes))
    def do_bag(self,line):
        """Show bag information
        bag {filename}
            filename :  default big.bag
        """
        bag_filename = "big.bag"
        pars = line.split("\n")
        if len(pars)>1:        
            bag_filename = pars[0]
        
        bag = rosbag.Bag(bag_filename)
        topics = bag.get_type_and_topic_info()[1].keys()
        rospy.loginfo("topics=%s" %(topics))
        types = []
        for i in range(0,len(bag.get_type_and_topic_info()[1].values())):
            types.append(bag.get_type_and_topic_info()[1].values()[i][0])
        rospy.loginfo("types=%s" %(types))

        for topic, msg, t in rosbag.Bag(bag_filename).read_messages():
            rospy.loginfo("topic=%s,t=%s,msg=%s" %(topic,t,msg))

    def scli_sub_callback(self,data):
        rospy.loginfo("SCLI Rx:%s", data.data)
    
    def do_scli_enable(self,line):
        """ setup rosserial CLI pub/sub support
        scli_enable [setting]
            setting:
                0: disable
                1: enable (default)
        ex: scli_enable 1 
        """     
        if line=="1":
            if not self.scli_pub:   
                self.scli_sub =rospy.Subscriber("Tx", String, self.scli_sub_callback)
                self.scli_pub = rospy.Publisher('Rx', String, queue_size=10)
                rospy.loginfo("scli enabled")
            else:
                rospy.loginfo("Already enabled, ignore!" )
        else:
            self.scli_pub = None
            if self.scli_sub:
                self.scli_sub.unregister()
                self.scli_sub = None
            rospy.loginfo("scli disabled")
        
    def do_scli(self,line):
        """ send cli command to serial
        scli {serial_cli_command}

        ex: scli ON
            demo rosserial CLI have ON/OFF/HELLO command
        """    
        scli_str = line
        if not self.scli_pub:
            rospy.loginfo("please enable serial CLI first!")
            return
        
        self.scli_pub.publish(scli_str)  
        

def main():
    global rcli
    try:
        rospy.loginfo("----- debug_ros V%s" %(str(VERSION)))
        rospy.loginfo("----- CLI need to run with ros master exist!" )
        rospy.init_node('debug_ros')

        
        
        rcli = RosDebugCli()
        rcli.cmdloop()
        
        #rospy.spin()
    except rospy.ROSInterruptException:
        pass        

if __name__ == '__main__':
    main()