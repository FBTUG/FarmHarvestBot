#ifndef _ROS_duckietown_msgs_ObstacleType_h
#define _ROS_duckietown_msgs_ObstacleType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckietown_msgs
{

  class ObstacleType : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      enum { DUCKIE = 0 };
      enum { CONE = 1 };

    ObstacleType():
      type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/ObstacleType"; };
    const char * getMD5(){ return "9ebfbd5f069d46cb29c52358b5e953fb"; };

  };

}
#endif