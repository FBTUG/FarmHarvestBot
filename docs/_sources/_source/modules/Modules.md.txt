# Modules
>
* [FarmHarvestBot Base 帶起](https://paper.dropbox.com/doc/FBTUG-FarmHarvestBot-Base--ATHsJq0_N0knNQDuFdo~9HsTAg-ychnvBySo6k1JsVhE64o9)

## core
* fhb Action_lib framework
* Project library
* Report framework 
![](/_static/report1.png)
## basic
```
roslaunch ./10-basic/cli/launch/cli.launch
roslaunch  ./10-basic/cli/launch/cli_sim.launch
roslaunch  ./10-basic/cli/launch/fsm.launch
roslaunch  ./10-basic/cli/launch/sim.launch
```

* CLI
![](/_static/sim1.png)
* NodeJS ROS Test
* ActionLib for Web
![](/_static/web1.png)

## msgs
[FhbAct.action](https://github.com/FBTUG/farmharvestbot_base/tree/master/20-msgs/action)
## Harvestbot_model
* Installation

[安裝gazebo_ros_pkgs](http://gazebosim.org/tutorials?tut=ros_installing&fbclid=IwAR2LlxwI3-s2LaOrcWPE-FSZYbAoyndSzWMt_WpyePqJ6j40pdA0O_w5Rbg)

* Usage
```
以rviz觀看harvestbot:
roslaunch harvestbot_description harvestbot_rviz.launch
在gazebo模擬時可看到camera跟laser scan訊號

以gazebo模擬harvestbot:
roslaunch harvestbot_gazebo harvestbot_world.launch

在gazebo模擬時可打開rqt發送topic控制harvestbot:
roslaunch harvestbot_control harvestbot_rqt.launch

```
![](/_static/model1.png)
![](/_static/model_msgflow.png)
![](/_static/model_race.png)

## harvest
```
roslaunch ./30-harvest/launch/harvest_analyzer.launch
roslaunch ./30-harvest/launch/harvest_sys.launch
```
* fsm
## vision
```
roslaunch ./40-vision/launch/vision_sys.launch
roslaunch  ./40-vision/launch/vision_test.launch
```
* ROS with RPI camera
* ROS+RPI camera+python opencv
* ROS + YOLO
![](/_static/darknet1.png)
* Publishing an image from disk
## arm
```
roslaunch ./50-arm/launch/arm_sys.launch
```
* MoveIT
[FarmHarvestBot 研究筆記-MoveIT](https://paper.dropbox.com/doc/FBTUG-FarmHarvestBot-MoveIT--ATJRGbqpsAU8Y6Escp~iWIpLAg-p2YqvAMuQikfHsMfeaefU)
![](/_static/moveit_mindmap.png)
![](/_static/moveit_example1.png)
![](/_static/moveit_xyz1.png)
![demo.launch](/_static/moveit_demolaunch.png)
## car
```
roslaunch ./60-car/launch/car_sys.launch
```
## test
```
roslaunch ./80-test/launch/test_sys.launch
```
* unittest by bag file


