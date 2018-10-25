// Import from https://github.com/scogswell/ArduinoSerialCommand, Thanks  Steven Cogswell
/*
  ROS CLI control by ROS string messagae
  Description:
    Arduino send std_msg:String "hello world!" every second through topic : /Tx
    Arduino sub /Rx: std_msg:String, confirm comand to /Tx, and process as CLI command
  Issue:
    Not send command result back yet
  
  Running example:
    ﻿ubuntu@ha:~$ rosrun rosserial_python serial_node.py /dev/ttyACM0
    [INFO] [1540425253.412201]: ROS Serial Python Node
    [INFO] [1540425253.435285]: Connecting to /dev/ttyACM0 at 57600 baud
    [INFO] [1540425255.571703]: Note: publish buffer size is 512 bytes
    [INFO] [1540425255.573582]: Setup publisher on Tx [std_msgs/String]
    [INFO] [1540425255.589281]: Note: subscribe buffer size is 512 bytes
    [INFO] [1540425255.590872]: Setup subscriber on Rx [std_msgs/String]
  
﻿    ubuntu@ha:~$ rostopic pub -r 0.5 /Rx std_msgs/String '{data : "OFF"}'
    ubuntu@ha:~$ rostopic pub -r 0.5 /Rx std_msgs/String '{data : "ON"}'
  
  osboxes@osboxes:~$ rostopic echo /Tx
    ﻿data: "HELLO"
    ---
    data: "ON"

  By WuLung Hsu
    https://www.facebook.com/wuulong.hsu
*/


#include <SoftwareSerial.h>   // We need this even if we're not using a SoftwareSerial object
                              // Due to the way the Arduino IDE compiles
#include "SerialCommand.h"
#define arduinoLED 13   // Arduino LED on board

#include <ros.h>
#include <std_msgs/String.h>

SerialCommand SCmd;   // The demo SerialCommand object
ros::NodeHandle nh;

std_msgs::String tx_str_msg;
ros::Publisher chatter("Tx", &tx_str_msg);

char on_str[13] = "ON";

void messageCb( const std_msgs::String& rx_str_msg) {
  tx_str_msg.data = rx_str_msg.data;
  /*
  int i,len;
  len = strlen(rx_str_msg.data);
  for(i=0;i< 2; i++){
    SCmd.readSerial(rx_str_msg.data[i]);
  }*/
  //SCmd.readSerial(on_str);  //OK
  SCmd.readSerial(rx_str_msg.data);
  

  chatter.publish( &tx_str_msg );
  //Serial.println(rx_str_msg.data);
}
ros::Subscriber<std_msgs::String> sub("Rx", messageCb );



void setup()
{  
  pinMode(arduinoLED,OUTPUT);      // Configure the onboard LED for output
  digitalWrite(arduinoLED,LOW);    // default to LED off

  

  // Setup callbacks for SerialCommand commands 
  SCmd.addCommand("ON",LED_on);       // Turns LED on
  SCmd.addCommand("OFF",LED_off);        // Turns LED off
  SCmd.addCommand("HELLO",SayHello);     // Echos the string argument back
  SCmd.addCommand("P",process_command);  // Converts two arguments to integers and echos them back 
  SCmd.addDefaultHandler(unrecognized);  // Handler for command that isn't matched  (says "What?") 
  Serial.println("Ready"); 

  // ROS
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
  //tx_str_msg.data = hello;

  Serial.begin(57600); 
}

void loop()
{ 
  if(SCmd.rosmode==0)
    SCmd.readSerial(NULL);     // We don't do much, just process serial commands

  //tx_str_msg.data = hello;
  //chatter.publish( &tx_str_msg );
  nh.spinOnce();
  //delay(1000);

}


void LED_on()
{
  Serial.println("LED on"); 
  digitalWrite(arduinoLED,HIGH);  
}

void LED_off()
{
  Serial.println("LED off"); 
  digitalWrite(arduinoLED,LOW);
}

void SayHello()
{
  char *arg;  
  arg = SCmd.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL)      // As long as it existed, take it
  {
    Serial.print("Hello "); 
    Serial.println(arg); 
  } 
  else {
    Serial.println("Hello, whoever you are"); 
  }
}


void process_command()    
{
  int aNumber;  
  char *arg; 

  Serial.println("We're in process_command"); 
  arg = SCmd.next(); 
  if (arg != NULL) 
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    Serial.print("First argument was: "); 
    Serial.println(aNumber); 
  } 
  else {
    Serial.println("No arguments"); 
  }

  arg = SCmd.next(); 
  if (arg != NULL) 
  {
    aNumber=atol(arg); 
    Serial.print("Second argument was: "); 
    Serial.println(aNumber); 
  } 
  else {
    Serial.println("No second argument"); 
  }

}

// This gets set as the default handler, and gets called when no other command matches. 
void unrecognized()
{
  Serial.println("What?"); 
}
