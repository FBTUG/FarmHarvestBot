export NODE=/turtlesim;export TOPIC=/turtle1/cmd_vel; export MSG=geometry_msgs/Twist
echo "User defined setting: NODE=$NODE, TOPIC=$TOPIC, MSG=$MSG"
PS3='run 1-quit,2-basic,3-info,4-runtime,5-design,6-dump: '
options=("quit" "basic" "info" "runtime" "design" "dump")
select opt in "${options[@]}"
do
    case $opt in
        "basic")
            echo "\$rostopic list =====>"
            rostopic list
            echo "\$rosnode list =====>"
            rosnode list
            echo "\$rosparam list =====>"
            rosparam list   
            ;;
        "info")
            echo "\$rosnode info $NODE =====>"
            rosnode info $NODE
            ;;
        "runtime")
            echo "\$rostopic echo $TOPIC =====>"
            rostopic echo $TOPIC
            ;;
        "design")
            echo "\$rosmsg show $MSG =====>"
            rosmsg show $MSG
            ;;
        "dump")
        		#echo "dump rosgraph =====>"
        		#rosgraph
        		
        		echo "[PARAM_DUMP]\$rosparam dump debug_ros_param.yaml =====>"
        		rosparam dump debug_ros_param.yaml
        		
        		echo "[NODE_LIST]\$rosnode list =====>"
        		rosnode list
        		
        		echo "[SRV_LIST]\$rossrv list =====>"
        		rossrv list
        		
            for item in `rosnode list` 
            do 
              echo "[NODE=$item]\$rosnode info $item =====>"
              rosnode info "$item" 
            done
            

            echo "[TOPIC_LIST]\$rostopic list =====>"
            rostopic list
            for item in `rostopic list` 
            do 
              echo "[TOPIC=$item]\$rostopic info $item =====>"
              rostopic info "$item"
              
              echo "[TOPIC_HZ=$item]\$timeout 1 rostopic hz $item =====>"
              timeout 1 rostopic hz "$item"
               
              for msg in `rostopic type $item` 
                do 
                  echo "[TOPIC_TYPE=$msg]\$rosmsg show $msg =====>"
                  rosmsg show "$msg" 
              
                done
            done
            
            
        		
            echo "[BAG]\$timeout -s SIGINT 10 rosbag record -a =====>"
            timeout -s SIGINT 10 rosbag record -a
            ;;          
        "quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
