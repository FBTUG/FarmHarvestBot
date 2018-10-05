export ROBOT=duckbot12;
echo "User defined setting: NODE=$NODE, TOPIC=$TOPIC, MSG=$MSG"
PS3='run 1-quit,2-master,3-bot,4-sbc: '
options=("quit" "master" "bot" "sbc" )
select opt in "${options[@]}"
do
    case $opt in
        "master")
            echo "\$export ROS_MASTER_URI=http://duckbot12:11311 =====>"
            export ROS_MASTER_URI=http://$ROBOT:11311
            ;;
        "bot")
            echo "\$roslaunch duckietown camera.launch veh:=duckbot12 =====>"
            roslaunch duckietown camera.launch veh:=$ROBOT
            ;;
        "sbc")
            echo "\$rostopic list =====>"
            rosnode list
            ;;
        "quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
