#ifndef _ROS_duckietown_msgs_AprilTagDetection_h
#define _ROS_duckietown_msgs_AprilTagDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace duckietown_msgs
{

  class AprilTagDetection : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef float _size_type;
      _size_type size;
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;

    AprilTagDetection():
      id(0),
      size(0),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += serializeAvrFloat64(outbuffer + offset, this->size);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->size));
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/AprilTagDetection"; };
    const char * getMD5(){ return "c7dd623e54eca222750cda2ae82f5257"; };

  };

}
#endif