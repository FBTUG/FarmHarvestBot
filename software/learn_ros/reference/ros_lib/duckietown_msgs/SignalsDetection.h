#ifndef _ROS_duckietown_msgs_SignalsDetection_h
#define _ROS_duckietown_msgs_SignalsDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class SignalsDetection : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _front_type;
      _front_type front;
      typedef const char* _right_type;
      _right_type right;
      typedef const char* _left_type;
      _left_type left;
      typedef const char* _traffic_light_state_type;
      _traffic_light_state_type traffic_light_state;
      enum { NO_CAR = 'no_car_detected' };
      enum { SIGNAL_A = 'car_signal_A' };
      enum { SIGNAL_B = 'car_signal_B' };
      enum { SIGNAL_C = 'car_signal_C' };
      enum { NO_TRAFFIC_LIGHT = 'no_traffic_light' };
      enum { STOP = 'tl_stop' };
      enum { GO = 'tl_go' };
      enum { YIELD = 'tl_yield' };

    SignalsDetection():
      header(),
      front(""),
      right(""),
      left(""),
      traffic_light_state("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_front = strlen(this->front);
      varToArr(outbuffer + offset, length_front);
      offset += 4;
      memcpy(outbuffer + offset, this->front, length_front);
      offset += length_front;
      uint32_t length_right = strlen(this->right);
      varToArr(outbuffer + offset, length_right);
      offset += 4;
      memcpy(outbuffer + offset, this->right, length_right);
      offset += length_right;
      uint32_t length_left = strlen(this->left);
      varToArr(outbuffer + offset, length_left);
      offset += 4;
      memcpy(outbuffer + offset, this->left, length_left);
      offset += length_left;
      uint32_t length_traffic_light_state = strlen(this->traffic_light_state);
      varToArr(outbuffer + offset, length_traffic_light_state);
      offset += 4;
      memcpy(outbuffer + offset, this->traffic_light_state, length_traffic_light_state);
      offset += length_traffic_light_state;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_front;
      arrToVar(length_front, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_front; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_front-1]=0;
      this->front = (char *)(inbuffer + offset-1);
      offset += length_front;
      uint32_t length_right;
      arrToVar(length_right, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_right; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_right-1]=0;
      this->right = (char *)(inbuffer + offset-1);
      offset += length_right;
      uint32_t length_left;
      arrToVar(length_left, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_left; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_left-1]=0;
      this->left = (char *)(inbuffer + offset-1);
      offset += length_left;
      uint32_t length_traffic_light_state;
      arrToVar(length_traffic_light_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_traffic_light_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_traffic_light_state-1]=0;
      this->traffic_light_state = (char *)(inbuffer + offset-1);
      offset += length_traffic_light_state;
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/SignalsDetection"; };
    const char * getMD5(){ return "30bdaa5e0b8f4e5aabc36ddd53f7926a"; };

  };

}
#endif