#ifndef _ROS_duckietown_msgs_CoordinationSignal_h
#define _ROS_duckietown_msgs_CoordinationSignal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace duckietown_msgs
{

  class CoordinationSignal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _signal_type;
      _signal_type signal;
      enum { OFF = light_off };
      enum { SIGNAL_A = CAR_SIGNAL_A };
      enum { SIGNAL_B = CAR_SIGNAL_B };
      enum { SIGNAL_C = CAR_SIGNAL_C };
      enum { TL_GO_ALL = tl_go_all };
      enum { TL_STOP_ALL = tl_stop_all };
      enum { TL_GO_N = tl_go_N };
      enum { TL_GO_S = tl_go_S };
      enum { TL_GO_W = tl_go_W };
      enum { TL_GO_E = tl_go_E };
      enum { TL_YIELD = tl_yield };

    CoordinationSignal():
      header(),
      signal("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_signal = strlen(this->signal);
      varToArr(outbuffer + offset, length_signal);
      offset += 4;
      memcpy(outbuffer + offset, this->signal, length_signal);
      offset += length_signal;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_signal;
      arrToVar(length_signal, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_signal; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_signal-1]=0;
      this->signal = (char *)(inbuffer + offset-1);
      offset += length_signal;
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/CoordinationSignal"; };
    const char * getMD5(){ return "38d01c6c7727f64c628b7afcb3e7ccd2"; };

  };

}
#endif