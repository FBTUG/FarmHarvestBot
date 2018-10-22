#ifndef _ROS_duckietown_msgs_VehiclePose_h
#define _ROS_duckietown_msgs_VehiclePose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Bool.h"

namespace duckietown_msgs
{

  class VehiclePose : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Float32 _rho_type;
      _rho_type rho;
      typedef std_msgs::Float32 _theta_type;
      _theta_type theta;
      typedef std_msgs::Float32 _psi_type;
      _psi_type psi;
      typedef std_msgs::Bool _detection_type;
      _detection_type detection;

    VehiclePose():
      header(),
      rho(),
      theta(),
      psi(),
      detection()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->rho.serialize(outbuffer + offset);
      offset += this->theta.serialize(outbuffer + offset);
      offset += this->psi.serialize(outbuffer + offset);
      offset += this->detection.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->rho.deserialize(inbuffer + offset);
      offset += this->theta.deserialize(inbuffer + offset);
      offset += this->psi.deserialize(inbuffer + offset);
      offset += this->detection.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/VehiclePose"; };
    const char * getMD5(){ return "69c01ed5e84e0f58f795e563d073900d"; };

  };

}
#endif