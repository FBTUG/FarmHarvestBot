#ifndef _ROS_duckietown_msgs_SourceTargetNodes_h
#define _ROS_duckietown_msgs_SourceTargetNodes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckietown_msgs
{

  class SourceTargetNodes : public ros::Msg
  {
    public:
      typedef const char* _source_node_type;
      _source_node_type source_node;
      typedef const char* _target_node_type;
      _target_node_type target_node;

    SourceTargetNodes():
      source_node(""),
      target_node("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_source_node = strlen(this->source_node);
      varToArr(outbuffer + offset, length_source_node);
      offset += 4;
      memcpy(outbuffer + offset, this->source_node, length_source_node);
      offset += length_source_node;
      uint32_t length_target_node = strlen(this->target_node);
      varToArr(outbuffer + offset, length_target_node);
      offset += 4;
      memcpy(outbuffer + offset, this->target_node, length_target_node);
      offset += length_target_node;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_source_node;
      arrToVar(length_source_node, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source_node; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source_node-1]=0;
      this->source_node = (char *)(inbuffer + offset-1);
      offset += length_source_node;
      uint32_t length_target_node;
      arrToVar(length_target_node, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_node; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_node-1]=0;
      this->target_node = (char *)(inbuffer + offset-1);
      offset += length_target_node;
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/SourceTargetNodes"; };
    const char * getMD5(){ return "f05fda47731d8da1f80e3a499a42edf9"; };

  };

}
#endif