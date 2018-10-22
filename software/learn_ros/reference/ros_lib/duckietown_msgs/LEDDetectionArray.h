#ifndef _ROS_duckietown_msgs_LEDDetectionArray_h
#define _ROS_duckietown_msgs_LEDDetectionArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "duckietown_msgs/LEDDetection.h"

namespace duckietown_msgs
{

  class LEDDetectionArray : public ros::Msg
  {
    public:
      uint32_t detections_length;
      typedef duckietown_msgs::LEDDetection _detections_type;
      _detections_type st_detections;
      _detections_type * detections;

    LEDDetectionArray():
      detections_length(0), detections(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->detections_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->detections_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->detections_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->detections_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detections_length);
      for( uint32_t i = 0; i < detections_length; i++){
      offset += this->detections[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t detections_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->detections_length);
      if(detections_lengthT > detections_length)
        this->detections = (duckietown_msgs::LEDDetection*)realloc(this->detections, detections_lengthT * sizeof(duckietown_msgs::LEDDetection));
      detections_length = detections_lengthT;
      for( uint32_t i = 0; i < detections_length; i++){
      offset += this->st_detections.deserialize(inbuffer + offset);
        memcpy( &(this->detections[i]), &(this->st_detections), sizeof(duckietown_msgs::LEDDetection));
      }
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/LEDDetectionArray"; };
    const char * getMD5(){ return "a95456786a73967a5a29fdbf726c022c"; };

  };

}
#endif