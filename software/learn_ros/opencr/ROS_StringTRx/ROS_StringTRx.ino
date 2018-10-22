/*
  Test ROS std_msg:String TRx in OpenCR
  Description:
    OpenCR send std_msg:String "hello world!" every second through topic : /Tx
    OpenCR sub /Rx: std_msg:String, when receive, send copy to /Tx
  
  Running example:
    osboxes@osboxes:~$ rosrun rosserial_python serial_node.py /dev/ttyS0
    [INFO] [1540176503.644228]: ROS Serial Python Node
    [INFO] [1540176503.653203]: Connecting to /dev/ttyS0 at 57600 baud
    [INFO] [1540176545.664788]: Note: publish buffer size is 1024 bytes
    [INFO] [1540176545.665141]: Setup publisher on Tx [std_msgs/String]
    [INFO] [1540176545.671100]: Note: subscribe buffer size is 1024 bytes
    [INFO] [1540176545.671653]: Setup subscriber on Rx [std_msgs/String]
  
  osboxes@osboxes:~$ rostopic pub -r 2 /Rx std_msgs/String '{data : "fdadafd"}'
  
  osboxes@osboxes:~$ rostopic echo /Tx
    data: "hello world!"
    ---
    data: "fdadafd"
    ---
    data: "fdadafd"
    ---
    data: "hello world!"

  By WuLung Hsu
    https://www.facebook.com/wuulong.hsu
*/


#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::String tx_str_msg;
ros::Publisher chatter("Tx", &tx_str_msg);


char hello[13] = "hello world!";

void messageCb( const std_msgs::String& rx_str_msg) {
  tx_str_msg.data = rx_str_msg.data;
  chatter.publish( &tx_str_msg );
  Serial.println(rx_str_msg.data);
}
ros::Subscriber<std_msgs::String> sub("Rx", messageCb );


void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
  tx_str_msg.data = hello;
  Serial.begin(57600);
}

void loop()
{
  
  tx_str_msg.data = hello;
  chatter.publish( &tx_str_msg );
  nh.spinOnce();
  delay(1000);
}
