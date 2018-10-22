#ifndef _ROS_duckietown_msgs_AprilTagsWithInfos_h
#define _ROS_duckietown_msgs_AprilTagsWithInfos_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "duckietown_msgs/AprilTagDetection.h"
#include "duckietown_msgs/TagInfo.h"

namespace duckietown_msgs
{

  class AprilTagsWithInfos : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t detections_length;
      typedef duckietown_msgs::AprilTagDetection _detections_type;
      _detections_type st_detections;
      _detections_type * detections;
      uint32_t infos_length;
      typedef duckietown_msgs::TagInfo _infos_type;
      _infos_type st_infos;
      _infos_type * infos;

    AprilTagsWithInfos():
      header(),
      detections_length(0), detections(NULL),
      infos_length(0), infos(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->detections_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->detections_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->detections_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->detections_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detections_length);
      for( uint32_t i = 0; i < detections_length; i++){
      offset += this->detections[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->infos_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->infos_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->infos_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->infos_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->infos_length);
      for( uint32_t i = 0; i < infos_length; i++){
      offset += this->infos[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t detections_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->detections_length);
      if(detections_lengthT > detections_length)
        this->detections = (duckietown_msgs::AprilTagDetection*)realloc(this->detections, detections_lengthT * sizeof(duckietown_msgs::AprilTagDetection));
      detections_length = detections_lengthT;
      for( uint32_t i = 0; i < detections_length; i++){
      offset += this->st_detections.deserialize(inbuffer + offset);
        memcpy( &(this->detections[i]), &(this->st_detections), sizeof(duckietown_msgs::AprilTagDetection));
      }
      uint32_t infos_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      infos_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->infos_length);
      if(infos_lengthT > infos_length)
        this->infos = (duckietown_msgs::TagInfo*)realloc(this->infos, infos_lengthT * sizeof(duckietown_msgs::TagInfo));
      infos_length = infos_lengthT;
      for( uint32_t i = 0; i < infos_length; i++){
      offset += this->st_infos.deserialize(inbuffer + offset);
        memcpy( &(this->infos[i]), &(this->st_infos), sizeof(duckietown_msgs::TagInfo));
      }
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/AprilTagsWithInfos"; };
    const char * getMD5(){ return "0f8211436af5ad17072ef13086108bc6"; };

  };

}
#endif