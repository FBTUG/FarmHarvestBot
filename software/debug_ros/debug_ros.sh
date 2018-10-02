
              echo "\$rostopic info "$item" =====>"
rt NODE=/turtlesim;export TOPIC=/turtle1/cmd_vel; export MSG=geometry_msgs/Twist
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
            echo "dump nodes =====>"
            for item in `rosnode list` 
            do 
              echo "\$rosnode info "$item" =====>"
              rosnode info "$item" 
            done
            
            echo "dump topics =====>"
            for item in `rostopic list` 
            do 
              echo "\$rostopic info "$item" =====>"
              rostopic info "$item" 
            done
            ;;          
        "quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
