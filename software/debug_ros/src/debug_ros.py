#!/usr/bin/env python
import rospy
import rosnode
import rosbag
import cmd
import time

VERSION = "0.0.1"
CMD_VERSION = "0.1"
rcli = None

#ros_debug CLI
class RosDebugCli(cmd.Cmd):
    """ros_debug CLI"""

    def __init__(self):
        cmd.Cmd.__init__(self)
        self.prompt = 'CLI>'

############ cli maintain ####################
    def do_quit(self, line):
        """quit"""

        return True
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

    def do_version(self,line):
        """Report software version"""
        output = "V" + VERSION
        print(output)
    

def main():
    global rcli
    try:
        rospy.init_node('debug_ros')

        rospy.loginfo("----- debug_ros V%s" %(str(VERSION)))
        
        rcli = RosDebugCli()
        rcli.cmdloop()
        
        #rospy.spin()
    except rospy.ROSInterruptException:
        pass        

if __name__ == '__main__':
    main()