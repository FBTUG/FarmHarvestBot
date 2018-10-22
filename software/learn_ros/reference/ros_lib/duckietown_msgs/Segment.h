#ifndef _ROS_duckietown_msgs_Segment_h
#define _ROS_duckietown_msgs_Segment_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "duckietown_msgs/Vector2D.h"
#include "geometry_msgs/Point.h"

namespace duckietown_msgs
{

  class Segment : public ros::Msg
  {
    public:
      typedef uint8_t _color_type;
      _color_type color;
      duckietown_msgs::Vector2D pixels_normalized[2];
      typedef duckietown_msgs::Vector2D _normal_type;
      _normal_type normal;
      geometry_msgs::Point points[2];
      enum { WHITE = 0 };
      enum { YELLOW = 1 };
      enum { RED = 2 };

    Segment():
      color(0),
      pixels_normalized(),
      normal(),
      points()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->color >> (8 * 0)) & 0xFF;
      offset += sizeof(this->color);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->pixels_normalized[i].serialize(outbuffer + offset);
      }
      offset += this->normal.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->color =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->color);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->pixels_normalized[i].deserialize(inbuffer + offset);
      }
      offset += this->normal.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->points[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/Segment"; };
    const char * getMD5(){ return "63449fcee6301e43c25adab0c5e5d117"; };

  };

}
#endif