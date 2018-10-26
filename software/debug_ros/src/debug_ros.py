#!/usr/bin/env python
# VERSION history:
#    0.0.2 - serial cli debug example with ROS_SerialCommandExample 
#    0.0.3 - rosserial performance test utility
import rospy
import rosnode
import rosbag
from std_msgs.msg import String
import cmd
import time
import numpy as np

VERSION = "0.0.3"
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
        self.cnt_pub=0
        self.cnt_sub=0
        self.last_sub_time=[] # record receive msg time
        self.t_rec_last=None
        self.drop_rx_enabled=False
        self.cli_test_rxtimeout=1.0 #s

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
        if self.drop_rx_enabled:
            return 
        t_rec_cur = rospy.Time.from_sec(time.time())
        self.cnt_sub=self.cnt_sub+1
        if self.t_rec_last:
            self.last_sub_time.append(t_rec_cur-self.t_rec_last)
        self.t_rec_last = t_rec_cur
        #rospy.loginfo("SCLI Rx:%s", data.data)
    
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
    def stabletest_analyzer(self):
        if 0:
            str_result = ""
            for item in self.last_sub_time:
                str_result = str_result + "%f" %( item.to_sec()) + "\n"
            rospy.loginfo("per msg receive gap=\n%s" %(str_result[:-1]))
        
        #rospy.loginfo("last_sub_time analyze (ns):\nmean=%s\nmedian=%s\nptp=%s\nvar=%s\nstd=%s" %(np.mean(self.last_sub_time),np.median(self.last_sub_time),np.ptp(self.last_sub_time),np.var(self.last_sub_time),np.std(self.last_sub_time)) )
        rospy.loginfo("mean=%s" %(np.mean(self.last_sub_time)))
        #rospy.loginfo("nvar=%s" %(np.var(self.last_sub_time)))
        rospy.loginfo("max=%s" %(np.max(self.last_sub_time)))
        rospy.loginfo("min=%s" %(np.min(self.last_sub_time)))
        rospy.loginfo("median=%s" %(np.median(self.last_sub_time)))
        rospy.loginfo("ptp=%s" %(np.ptp(self.last_sub_time)))
        #rospy.loginfo("nstd=%s" %(np.std(self.last_sub_time)))
        
        
    def scli_stabletest(self,set_speed,set_cnt):
        cnt=0
        self.drop_rx_enabled=False
        self.cnt_pub=0
        self.cnt_sub=0
        self.t_rec_last=None
        self.last_sub_time=[]
        r = rospy.Rate(set_speed) # 10hz
        t_start = rospy.Time.from_sec(time.time())
        
        while not rospy.is_shutdown():
            self.scli_pub.publish("ON")
            self.cnt_pub=self.cnt_pub+1
            cnt=cnt+1
            if cnt==set_cnt:
                break
                
            r.sleep()
            
        t_end = rospy.Time.from_sec(time.time())
        t_dur = t_end - t_start
        rospy.sleep(self.cli_test_rxtimeout)
        self.drop_rx_enabled=True
        
        rospy.loginfo("scli stable test result: setup speed=%i, count=%i\nresult pub_cnt=%i,sub_cnt=%i,receive rate=%f,duration seconds=%f" %(set_speed,set_cnt,self.cnt_pub,self.cnt_sub,float(self.cnt_sub)/self.cnt_pub,t_dur.to_sec()))
    def scli_maxstablerate_search(self,set_max,set_min,set_step,set_cnt):
        r_max = set_max
        r_min = set_min
        r_cur =0
        r_result= 0
        b_first=True
        rospy.loginfo("Using search setting max=%i,min=%i,step=%i,count=%i" %(set_max,set_min,set_step,set_cnt))
        while(1):
            if b_first:
                r_cur=r_min
                b_first=False
            else:
                r_cur = (r_max + r_min)/2
                r_cur = int(r_cur/set_step)*set_step #align to step
            self.scli_stabletest(r_cur,set_cnt)
            if self.cnt_pub <= self.cnt_sub: #pass
                rospy.loginfo("PASS rate: %i" %(r_cur)  )
                r_min = r_cur
                r_result= r_cur
            else:
                rospy.loginfo("FAIL rate: %i" %(r_cur)  )
                if r_cur==r_min:
                    return 0
                r_max = r_cur
                rospy.sleep(10) #wait to receive all
            if(r_max-r_min <= set_step): 
                break
        return r_result
    def do_scli_maxstablerate_search(self,line):
        """  using binary search to find the max stable rate
        max rate should setup a rate that can't reach
        scli_maxstablerate_search [max] [min] [step] [count]
        ex: scli_maxstablerate_search 1000 100 50 1000
            
        """    
        if not self.scli_pub:   
            rospy.loginfo("scli enable needed!" )
            return
        pars = line.strip().split()
        #rospy.loginfo("line=%s,len=%i" %(line,len(pars)))
        
        set_max=1000
        set_min=100
        set_step=50
        set_cnt=1000
        
        if len(pars)>3:
            set_max=int(pars[0])
            set_min=int(pars[1])
            set_step=int(pars[2])
            set_cnt=int(pars[3])
        else:
            rospy.loginfo("using default setting, the same as example")
        result_rate = self.scli_maxstablerate_search(set_max,set_min,set_step,set_cnt)
        rospy.loginfo("maxstablerate_search result rate=%i" %(result_rate))
        
    def do_scli_stabletest_range(self,line):
        """ check how stable rosserial demo can be, send cmd with count and speed, check how many reply (speed: time/s)
        scli_stabletest_range [start] [end] [step] [count]

        ex: scli_stabletest_range 200 1001 50 1000
            send range(200,1001,50) , everytime send  1000 commands
        """    
        start=100
        end=1001
        step=50
        set_cnt=1000
        if not self.scli_pub:   
            rospy.loginfo("scli enable needed!" )
            return
        pars = line.strip().split()
        #rospy.loginfo("line=%s,len=%i" %(line,len(pars)))
        
            
        if len(pars)>3:
            #rospy.loginfo("pars[0]=%s,pars[1]=%s" %(pars[0],pars[1]))
            start=int(pars[0])
            end=int(pars[1])
            step=int(pars[2])
            set_cnt=int(pars[3])
        else:
            rospy.loginfo("using default setting, the same as example")
        
        rospy.loginfo("test setting: cli_test_rxtimeout=%i" %(self.cli_test_rxtimeout))
            

        for i in range(start,end,step):
            self.scli_stabletest(i,set_cnt)
            self.stabletest_analyzer()
           
    def do_scli_stabletest(self,line):
        """ check how stable rosserial demo can be, send cmd with count and speed, check how many reply (speed: time/s)
        scli_stabletest [speed] [count]

        ex: scli_stabletest 200 1000
            send 200 times per second with 1000 commands
        """    
        set_speed=100
        set_cnt=1000

        if not self.scli_pub:   
            rospy.loginfo("scli enable needed!" )
            return
        pars = line.strip().split()
        #rospy.loginfo("line=%s,len=%i" %(line,len(pars)))
        
            
        if len(pars)>1:
            #rospy.loginfo("pars[0]=%s,pars[1]=%s" %(pars[0],pars[1]))
            set_speed = int(pars[0])
            set_cnt = int(pars[1])
        elif len(pars)>0:
            #rospy.loginfo("pars[0]=%s" %(pars[0]))
            set_speed = int(pars[0])
        
        rospy.loginfo("test setting: cli_test_rxtimeou=%i" %(self.self.cli_test_rxtimeou))
        self.scli_stabletest(set_speed,set_cnt)
        

def main():
    global rcli
    try:
        rospy.loginfo("----- debug_ros V%s" %(str(VERSION)))
        rospy.loginfo("----- CLI need to run with ros master exist!" )
        rospy.init_node('debug_ros')

        
        
        rcli = RosDebugCli()
        rcli.cmdloop()
        
        #rospy.spin()
    except rospy.ROSInterruptException,ValueError:
        pass
    else:
        pass       

if __name__ == '__main__':
    main()