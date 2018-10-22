#ifndef _ROS_duckietown_msgs_ObstacleProjectedDetection_h
#define _ROS_duckietown_msgs_ObstacleProjectedDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "duckietown_msgs/ObstacleType.h"

namespace duckietown_msgs
{

  class ObstacleProjectedDetection : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _location_type;
      _location_type location;
      typedef duckietown_msgs::ObstacleType _type_type;
      _type_type type;
      typedef float _distance_type;
      _distance_type distance;

    ObstacleProjectedDetection():
      location(),
      type(),
      distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->location.serialize(outbuffer + offset);
      offset += this->type.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->location.deserialize(inbuffer + offset);
      offset += this->type.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/ObstacleProjectedDetection"; };
    const char * getMD5(){ return "cb503445da742d4aa1f69f0b72163c00"; };

  };

}
#endif