#ifndef _ROS_duckietown_msgs_ObstacleImageDetection_h
#define _ROS_duckietown_msgs_ObstacleImageDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "duckietown_msgs/Rect.h"
#include "duckietown_msgs/ObstacleType.h"

namespace duckietown_msgs
{

  class ObstacleImageDetection : public ros::Msg
  {
    public:
      typedef duckietown_msgs::Rect _bounding_box_type;
      _bounding_box_type bounding_box;
      typedef duckietown_msgs::ObstacleType _type_type;
      _type_type type;

    ObstacleImageDetection():
      bounding_box(),
      type()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->bounding_box.serialize(outbuffer + offset);
      offset += this->type.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->bounding_box.deserialize(inbuffer + offset);
      offset += this->type.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/ObstacleImageDetection"; };
    const char * getMD5(){ return "e532bfbd15e6046dab5e4261999811a9"; };

  };

}
#endif