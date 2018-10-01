export NODE=/turtlesim;export TOPIC=/turtle1/cmd_vel; export MSG=geometry_msgs/Twist
echo "User defined setting: NODE=$NODE, TOPIC=$TOPIC, MSG=$MSG"
PS3='run 1-basic,2-info,3-runtime,4-design,5-Quit: '
options=("basic" "info" "runtime" "design" "Quit")
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
        "Quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
