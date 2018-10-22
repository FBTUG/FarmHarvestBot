#ifndef _ROS_duckietown_msgs_SceneSegments_h
#define _ROS_duckietown_msgs_SceneSegments_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "duckietown_msgs/Rect.h"

namespace duckietown_msgs
{

  class SceneSegments : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _segimage_type;
      _segimage_type segimage;
      uint32_t rects_length;
      typedef duckietown_msgs::Rect _rects_type;
      _rects_type st_rects;
      _rects_type * rects;

    SceneSegments():
      segimage(),
      rects_length(0), rects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->segimage.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->rects_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rects_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rects_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rects_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rects_length);
      for( uint32_t i = 0; i < rects_length; i++){
      offset += this->rects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->segimage.deserialize(inbuffer + offset);
      uint32_t rects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rects_length);
      if(rects_lengthT > rects_length)
        this->rects = (duckietown_msgs::Rect*)realloc(this->rects, rects_lengthT * sizeof(duckietown_msgs::Rect));
      rects_length = rects_lengthT;
      for( uint32_t i = 0; i < rects_length; i++){
      offset += this->st_rects.deserialize(inbuffer + offset);
        memcpy( &(this->rects[i]), &(this->st_rects), sizeof(duckietown_msgs::Rect));
      }
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/SceneSegments"; };
    const char * getMD5(){ return "2aa3c1097b948038841bf28c11cf95cb"; };

  };

}
#endif