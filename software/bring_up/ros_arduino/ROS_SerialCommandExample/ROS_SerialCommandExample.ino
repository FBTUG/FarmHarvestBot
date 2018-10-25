// Import from https://github.com/scogswell/ArduinoSerialCommand, Thanks  Steven Cogswell
/*
  ROS CLI control by ROS string messagae
  Description:
    Arduino sub /Rx: std_msg:String, if match command, process as CLI command, and reply confirmation by topic /Tx
      if not match, discard it without reply.
    Debug console set to Serial2( pin TX2), It show debug message also accept command, this work with ROS at the same time.
    Terminal should setup to line mode with \r as enter key 
    Demo command list:
      ON: turn on LED
      OFF: turn off LED
      HELLO: do nothing. 
  
  Running example:
    ubuntu@ha:~$ rosrun rosserial_python serial_node.py /dev/ttyACM0
    [INFO] [1540425253.412201]: ROS Serial Python Node
    [INFO] [1540425253.435285]: Connecting to /dev/ttyACM0 at 57600 baud
    [INFO] [1540425255.571703]: Note: publish buffer size is 512 bytes
    [INFO] [1540425255.573582]: Setup publisher on Tx [std_msgs/String]
    [INFO] [1540425255.589281]: Note: subscribe buffer size is 512 bytes
    [INFO] [1540425255.590872]: Setup subscriber on Rx [std_msgs/String]
  
    ubuntu@ha:~$ rostopic pub -r 0.5 /Rx std_msgs/String '{data : "OFF"}'
    ubuntu@ha:~$ rostopic pub -r 0.5 /Rx std_msgs/String '{data : "ON"}'
    ubuntu@ha:~$ rostopic pub -r 0.5 /Rx std_msgs/String '{data : "HELLO"}'
  
  osboxes@osboxes:~$ rostopic echo /Tx
    data: "HELLO"
    ---
    data: "ON"

  By WuLung Hsu
    https://www.facebook.com/wuulong.hsu
*/
#include "SerialCommand.h"
#include <ros.h>
#include <std_msgs/String.h>

#define arduinoLED 13   // Arduino LED on board

SerialCommand SCmd;   // The demo SerialCommand object

ros::NodeHandle nh;

std_msgs::String tx_str_msg;
ros::Publisher chatter("Tx", &tx_str_msg);

void messageCb( const std_msgs::String& rx_str_msg) {
  char* return_str;
  TERMINAL.println(rx_str_msg.data);
  tx_str_msg.data = rx_str_msg.data;
  return_str= SCmd.readSerialByBuffer(rx_str_msg.data);
  if(return_str)  {
    tx_str_msg.data = return_str;
    chatter.publish( &tx_str_msg );
  }
  
  
}
ros::Subscriber<std_msgs::String> sub("Rx", messageCb );


void setup()
{  
  pinMode(arduinoLED,OUTPUT);      // Configure the onboard LED for output
  digitalWrite(arduinoLED,LOW);    // default to LED off


  TERMINAL.begin(115200);
   

  // Setup callbacks for SerialCommand commands 
  SCmd.addCommand("ON",LED_on);       // Turns LED on
  SCmd.addCommand("OFF",LED_off);        // Turns LED off
  SCmd.addCommand("HELLO",SayHello);     // Echos the string argument back
  SCmd.addCommand("P",process_command);  // Converts two arguments to integers and echos them back 
  SCmd.addDefaultHandler(unrecognized);  // Handler for command that isn't matched  (says "What?") 
  TERMINAL.println("Ready1"); 

  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
   

}

void loop()
{  
  SCmd.readSerial();     // We don't do much, just process serial commands
  nh.spinOnce();
}


void LED_on()
{
  TERMINAL.println("LED on"); 
  digitalWrite(arduinoLED,HIGH);  
}

void LED_off()
{
  TERMINAL.println("LED off"); 
  digitalWrite(arduinoLED,LOW);
}

void SayHello()
{
  char *arg;  
  arg = SCmd.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL)      // As long as it existed, take it
  {
    TERMINAL.print("Hello "); 
    TERMINAL.println(arg); 
    
    
  } 
  else {
    TERMINAL.println("Hello, whoever you are");
    //strcpy(tx_str_msg.data,"Hello, whoever you are");
    //chatter.publish( &tx_str_msg ); 
  }
}


void process_command()    
{
  int aNumber;  
  char *arg; 

  TERMINAL.println("We're in process_command"); 
  arg = SCmd.next(); 
  if (arg != NULL) 
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    TERMINAL.print("First argument was: "); 
    TERMINAL.println(aNumber); 
  } 
  else {
    TERMINAL.println("No arguments"); 
  }

  arg = SCmd.next(); 
  if (arg != NULL) 
  {
    aNumber=atol(arg); 
    TERMINAL.print("Second argument was: "); 
    TERMINAL.println(aNumber); 
  } 
  else {
    TERMINAL.println("No second argument"); 
  }

}

// This gets set as the default handler, and gets called when no other command matches. 
void unrecognized()
{
  TERMINAL.println("What?"); 
}
