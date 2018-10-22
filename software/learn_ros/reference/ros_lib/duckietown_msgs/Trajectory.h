#ifndef _ROS_duckietown_msgs_Trajectory_h
#define _ROS_duckietown_msgs_Trajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3Stamped.h"

namespace duckietown_msgs
{

  class Trajectory : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t pos_length;
      typedef geometry_msgs::Vector3Stamped _pos_type;
      _pos_type st_pos;
      _pos_type * pos;
      uint32_t vel_length;
      typedef geometry_msgs::Vector3Stamped _vel_type;
      _vel_type st_vel;
      _vel_type * vel;
      uint32_t acc_length;
      typedef geometry_msgs::Vector3Stamped _acc_type;
      _acc_type st_acc;
      _acc_type * acc;
      uint32_t jerk_length;
      typedef geometry_msgs::Vector3Stamped _jerk_type;
      _jerk_type st_jerk;
      _jerk_type * jerk;

    Trajectory():
      header(),
      pos_length(0), pos(NULL),
      vel_length(0), vel(NULL),
      acc_length(0), acc(NULL),
      jerk_length(0), jerk(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->pos_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pos_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pos_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pos_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_length);
      for( uint32_t i = 0; i < pos_length; i++){
      offset += this->pos[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->vel_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vel_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vel_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vel_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_length);
      for( uint32_t i = 0; i < vel_length; i++){
      offset += this->vel[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->acc_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->acc_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->acc_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->acc_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc_length);
      for( uint32_t i = 0; i < acc_length; i++){
      offset += this->acc[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->jerk_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->jerk_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->jerk_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->jerk_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jerk_length);
      for( uint32_t i = 0; i < jerk_length; i++){
      offset += this->jerk[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t pos_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pos_length);
      if(pos_lengthT > pos_length)
        this->pos = (geometry_msgs::Vector3Stamped*)realloc(this->pos, pos_lengthT * sizeof(geometry_msgs::Vector3Stamped));
      pos_length = pos_lengthT;
      for( uint32_t i = 0; i < pos_length; i++){
      offset += this->st_pos.deserialize(inbuffer + offset);
        memcpy( &(this->pos[i]), &(this->st_pos), sizeof(geometry_msgs::Vector3Stamped));
      }
      uint32_t vel_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vel_length);
      if(vel_lengthT > vel_length)
        this->vel = (geometry_msgs::Vector3Stamped*)realloc(this->vel, vel_lengthT * sizeof(geometry_msgs::Vector3Stamped));
      vel_length = vel_lengthT;
      for( uint32_t i = 0; i < vel_length; i++){
      offset += this->st_vel.deserialize(inbuffer + offset);
        memcpy( &(this->vel[i]), &(this->st_vel), sizeof(geometry_msgs::Vector3Stamped));
      }
      uint32_t acc_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      acc_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      acc_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      acc_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->acc_length);
      if(acc_lengthT > acc_length)
        this->acc = (geometry_msgs::Vector3Stamped*)realloc(this->acc, acc_lengthT * sizeof(geometry_msgs::Vector3Stamped));
      acc_length = acc_lengthT;
      for( uint32_t i = 0; i < acc_length; i++){
      offset += this->st_acc.deserialize(inbuffer + offset);
        memcpy( &(this->acc[i]), &(this->st_acc), sizeof(geometry_msgs::Vector3Stamped));
      }
      uint32_t jerk_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      jerk_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      jerk_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      jerk_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->jerk_length);
      if(jerk_lengthT > jerk_length)
        this->jerk = (geometry_msgs::Vector3Stamped*)realloc(this->jerk, jerk_lengthT * sizeof(geometry_msgs::Vector3Stamped));
      jerk_length = jerk_lengthT;
      for( uint32_t i = 0; i < jerk_length; i++){
      offset += this->st_jerk.deserialize(inbuffer + offset);
        memcpy( &(this->jerk[i]), &(this->st_jerk), sizeof(geometry_msgs::Vector3Stamped));
      }
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/Trajectory"; };
    const char * getMD5(){ return "4a5c4bf7a2bfb37b947e3dfa585ede51"; };

  };

}
#endif