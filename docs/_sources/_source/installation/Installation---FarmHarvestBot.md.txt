# FarmHarvestBot Installation
>

## Usage

1. Build
   ```
   cd ~/catkin_ws/src
   git clone https://github.com/FBTUG/farmharvestbot_base
   cd ~/catkin_ws
   catkin_make
   ```
1. Run
   ```
   ~/catkin_ws/src/farmharvestbot_base/10-basic/cli/launch$ roslaunch fhb.launch
   ```
1. fhb.launch setting
   ```
	<arg name="cli_enabled" default="false"/>
	<arg name="harvest_enabled" default="true"/>
	<arg name="model_enabled" default="true"/>
	<arg name="vision_enabled" default="true"/>
	<arg name="camera_enabled" default="false"/>
	<arg name="feature_detector_enabled" default="false"/>
	<arg name="arm_enabled" default="true"/>
	<arg name="fake_arm_enabled" default="false"/>
	<arg name="car_enabled" default="true"/>
	<arg name="sim_enabled" default="false"/>
	<arg name="test_enabled" default="false"/>
	<arg name="fsm_enabled" default="false"/>   
   ```
1. [More information](https://paper.dropbox.com/doc/FBTUG-FarmHarvestBot--ATDe887EhobuDuaVhVkk1wAdAg-fNLXTm8xpJD8plZd3cTOT)

## CLI User Manual
   ```
	oroslaunch fhb.launch 
	SUMMARY
	========

	PARAMETERS
	 * /fhb_arm/mode: 0
	 * /fhb_car/mode: 0
	 * /fhb_cli/mode: 0
	 * /fhb_harvest/mode: 0
	 * /fhb_vision/mode: 0
	 * /rosdistro: kinetic
	 * /rosversion: 1.12.13

	NODES
	  /
	    fhb_arm (farmharvestbot_arm/arm_node.py)
	    fhb_car (farmharvestbot_car/car_node.py)
	    fhb_cli (farmharvestbot_cli/cli_node.py)
	    fhb_harvest (farmharvestbot_harvest/harvest_node.py)
	    fhb_vision (farmharvestbot_vision/vision_node.py)

	Base>help

	Documented commands (type help <topic>):
	========================================
	arm  car  harvest  help  quit  sim  sys  test  version  vision

	Base>help sys
	sys sub command directory
	Base>sys
	Base:sys>help

	Documented commands (type help <topic>):
	========================================
	actionclient  help  monitor_statistic  quit

	Base:sys>quit
	Base>harvest
	Base:harvest>help

	Documented commands (type help <topic>):
	========================================
	help  quit

	Base:harvest>quit
	Base>vision
	Base:vision>help

	Documented commands (type help <topic>):
	========================================
	help  quit

	Base:vision>quit
	Base>arm
	Base:arm>help

	Documented commands (type help <topic>):
	========================================
	arm_setup  cmd_pos  help  quit

	Base:arm>quit
	Base>car
	Base:car>help

	Documented commands (type help <topic>):
	========================================
	help  quit

	Base:car>quit
	Base>sim
	Base:sim>help

	Documented commands (type help <topic>):
	========================================
	help  quit  sim_setup  sim_turtlesim_key

	Base:sim>quit
	Base>help

	Documented commands (type help <topic>):
	========================================
	arm  car  harvest  help  quit  sim  sys  test  version  vision

	Base>sys

	Base:sys>actionclient
	[INFO] [1541468190.900285]: missing enable information, use default: 101 1 0 0 0.0 0.0 test
	[INFO] [1541468190.900671]: act_grp=harvest
	[INFO] [1541468191.028853]: harvest_act: Executing... Goal =
	act_id: 101
	act_subid: 1
	i1: 0
	i2: 0
	f1: 0.0
	f2: 0.0
	line: "test"
	[INFO] [1541468191.030214]: feedback: notice_id: 0
	progrsss: 0
	fb_msg: ''
	[INFO] [1541468192.033419]: feedback: notice_id: 0
	progrsss: 20
	fb_msg: ''
	[INFO] [1541468193.030142]: feedback: notice_id: 0
	progrsss: 40
	fb_msg: ''
	[INFO] [1541468194.030546]: feedback: notice_id: 0
	progrsss: 60
	fb_msg: ''
	[INFO] [1541468195.031611]: feedback: notice_id: 0
	progrsss: 80
	fb_msg: ''
	[INFO] [1541468196.030016]: harvest_act Succeeded :success
	[INFO] [1541468196.052794]: status: 3
	error_level: 0
	error_msg: "success"
	Base:sys>monitor_statistic
	[INFO] [1541468202.330091]: missing enable information, use default: 1
	[INFO] [1541468202.341122]: sys monitor statistic been setup!
	Base:sys>[INFO] [1541468202.569276]: cli_node:receive from /diagnostics: header: 
	  seq: 87
	  stamp: 
	    secs: 1541468202
	    nsecs: 568011045
	  frame_id: ''
	status: 
	  - 
	    level: 0
	    name: "fhb_vision: vision_statistic"
	    message: "vision statistic"
	    hardware_id: "vision"
	    values: 
	      - 
		key: "fruit_cnt"
		value: "87"

	Base:sys>quit
	Base>help

	Documented commands (type help <topic>):
	========================================
	arm  car  harvest  help  quit  sim  sys  test  version  vision

	Base>version
	V0.0.5
	Base>quit
   ```
