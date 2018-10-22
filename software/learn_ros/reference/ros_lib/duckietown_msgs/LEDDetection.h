#ifndef _ROS_duckietown_msgs_LEDDetection_h
#define _ROS_duckietown_msgs_LEDDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "duckietown_msgs/Vector2D.h"

namespace duckietown_msgs
{

  class LEDDetection : public ros::Msg
  {
    public:
      typedef ros::Time _timestamp1_type;
      _timestamp1_type timestamp1;
      typedef ros::Time _timestamp2_type;
      _timestamp2_type timestamp2;
      typedef duckietown_msgs::Vector2D _pixels_normalized_type;
      _pixels_normalized_type pixels_normalized;
      typedef float _frequency_type;
      _frequency_type frequency;
      typedef const char* _color_type;
      _color_type color;
      typedef float _confidence_type;
      _confidence_type confidence;
      uint32_t signal_ts_length;
      typedef float _signal_ts_type;
      _signal_ts_type st_signal_ts;
      _signal_ts_type * signal_ts;
      uint32_t signal_length;
      typedef float _signal_type;
      _signal_type st_signal;
      _signal_type * signal;
      uint32_t fft_fs_length;
      typedef float _fft_fs_type;
      _fft_fs_type st_fft_fs;
      _fft_fs_type * fft_fs;
      uint32_t fft_length;
      typedef float _fft_type;
      _fft_type st_fft;
      _fft_type * fft;

    LEDDetection():
      timestamp1(),
      timestamp2(),
      pixels_normalized(),
      frequency(0),
      color(""),
      confidence(0),
      signal_ts_length(0), signal_ts(NULL),
      signal_length(0), signal(NULL),
      fft_fs_length(0), fft_fs(NULL),
      fft_length(0), fft(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->timestamp1.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp1.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp1.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp1.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp1.sec);
      *(outbuffer + offset + 0) = (this->timestamp1.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp1.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp1.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp1.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp1.nsec);
      *(outbuffer + offset + 0) = (this->timestamp2.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp2.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp2.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp2.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp2.sec);
      *(outbuffer + offset + 0) = (this->timestamp2.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp2.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp2.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp2.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp2.nsec);
      offset += this->pixels_normalized.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_frequency;
      u_frequency.real = this->frequency;
      *(outbuffer + offset + 0) = (u_frequency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frequency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frequency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frequency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequency);
      uint32_t length_color = strlen(this->color);
      varToArr(outbuffer + offset, length_color);
      offset += 4;
      memcpy(outbuffer + offset, this->color, length_color);
      offset += length_color;
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence);
      *(outbuffer + offset + 0) = (this->signal_ts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->signal_ts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->signal_ts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->signal_ts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signal_ts_length);
      for( uint32_t i = 0; i < signal_ts_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->signal_ts[i]);
      }
      *(outbuffer + offset + 0) = (this->signal_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->signal_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->signal_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->signal_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signal_length);
      for( uint32_t i = 0; i < signal_length; i++){
      union {
        float real;
        uint32_t base;
      } u_signali;
      u_signali.real = this->signal[i];
      *(outbuffer + offset + 0) = (u_signali.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_signali.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_signali.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_signali.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->signal[i]);
      }
      *(outbuffer + offset + 0) = (this->fft_fs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fft_fs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fft_fs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fft_fs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fft_fs_length);
      for( uint32_t i = 0; i < fft_fs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_fft_fsi;
      u_fft_fsi.real = this->fft_fs[i];
      *(outbuffer + offset + 0) = (u_fft_fsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fft_fsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fft_fsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fft_fsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fft_fs[i]);
      }
      *(outbuffer + offset + 0) = (this->fft_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fft_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fft_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fft_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fft_length);
      for( uint32_t i = 0; i < fft_length; i++){
      union {
        float real;
        uint32_t base;
      } u_ffti;
      u_ffti.real = this->fft[i];
      *(outbuffer + offset + 0) = (u_ffti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ffti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ffti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ffti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fft[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->timestamp1.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp1.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp1.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp1.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp1.sec);
      this->timestamp1.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp1.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp1.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp1.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp1.nsec);
      this->timestamp2.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp2.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp2.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp2.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp2.sec);
      this->timestamp2.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp2.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp2.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp2.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp2.nsec);
      offset += this->pixels_normalized.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_frequency;
      u_frequency.base = 0;
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->frequency = u_frequency.real;
      offset += sizeof(this->frequency);
      uint32_t length_color;
      arrToVar(length_color, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_color; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_color-1]=0;
      this->color = (char *)(inbuffer + offset-1);
      offset += length_color;
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
      uint32_t signal_ts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      signal_ts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      signal_ts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      signal_ts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->signal_ts_length);
      if(signal_ts_lengthT > signal_ts_length)
        this->signal_ts = (float*)realloc(this->signal_ts, signal_ts_lengthT * sizeof(float));
      signal_ts_length = signal_ts_lengthT;
      for( uint32_t i = 0; i < signal_ts_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_signal_ts));
        memcpy( &(this->signal_ts[i]), &(this->st_signal_ts), sizeof(float));
      }
      uint32_t signal_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      signal_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      signal_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      signal_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->signal_length);
      if(signal_lengthT > signal_length)
        this->signal = (float*)realloc(this->signal, signal_lengthT * sizeof(float));
      signal_length = signal_lengthT;
      for( uint32_t i = 0; i < signal_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_signal;
      u_st_signal.base = 0;
      u_st_signal.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_signal.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_signal.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_signal.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_signal = u_st_signal.real;
      offset += sizeof(this->st_signal);
        memcpy( &(this->signal[i]), &(this->st_signal), sizeof(float));
      }
      uint32_t fft_fs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fft_fs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fft_fs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fft_fs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fft_fs_length);
      if(fft_fs_lengthT > fft_fs_length)
        this->fft_fs = (float*)realloc(this->fft_fs, fft_fs_lengthT * sizeof(float));
      fft_fs_length = fft_fs_lengthT;
      for( uint32_t i = 0; i < fft_fs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_fft_fs;
      u_st_fft_fs.base = 0;
      u_st_fft_fs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_fft_fs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_fft_fs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_fft_fs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_fft_fs = u_st_fft_fs.real;
      offset += sizeof(this->st_fft_fs);
        memcpy( &(this->fft_fs[i]), &(this->st_fft_fs), sizeof(float));
      }
      uint32_t fft_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fft_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fft_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fft_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fft_length);
      if(fft_lengthT > fft_length)
        this->fft = (float*)realloc(this->fft, fft_lengthT * sizeof(float));
      fft_length = fft_lengthT;
      for( uint32_t i = 0; i < fft_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_fft;
      u_st_fft.base = 0;
      u_st_fft.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_fft.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_fft.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_fft.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_fft = u_st_fft.real;
      offset += sizeof(this->st_fft);
        memcpy( &(this->fft[i]), &(this->st_fft), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "duckietown_msgs/LEDDetection"; };
    const char * getMD5(){ return "d1ac8691d7a30e838dc372a724aee94b"; };

  };

}
#endif