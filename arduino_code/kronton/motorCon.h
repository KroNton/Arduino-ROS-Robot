#ifndef _ROS_kronton_motorCon_h
#define _ROS_kronton_motorCon_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace kronton
{

  class motorCon : public ros::Msg
  {
    public:
      typedef int64_t _IN1_type;
      _IN1_type IN1;
      typedef int64_t _IN2_type;
      _IN2_type IN2;
      typedef float _ENA_type;
      _ENA_type ENA;

    motorCon():
      IN1(0),
      IN2(0),
      ENA(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_IN1;
      u_IN1.real = this->IN1;
      *(outbuffer + offset + 0) = (u_IN1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_IN1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_IN1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_IN1.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_IN1.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_IN1.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_IN1.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_IN1.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->IN1);
      union {
        int64_t real;
        uint64_t base;
      } u_IN2;
      u_IN2.real = this->IN2;
      *(outbuffer + offset + 0) = (u_IN2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_IN2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_IN2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_IN2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_IN2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_IN2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_IN2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_IN2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->IN2);
      offset += serializeAvrFloat64(outbuffer + offset, this->ENA);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_IN1;
      u_IN1.base = 0;
      u_IN1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_IN1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_IN1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_IN1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_IN1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_IN1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_IN1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_IN1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->IN1 = u_IN1.real;
      offset += sizeof(this->IN1);
      union {
        int64_t real;
        uint64_t base;
      } u_IN2;
      u_IN2.base = 0;
      u_IN2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_IN2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_IN2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_IN2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_IN2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_IN2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_IN2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_IN2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->IN2 = u_IN2.real;
      offset += sizeof(this->IN2);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ENA));
     return offset;
    }

    const char * getType(){ return "kronton/motorCon"; };
    const char * getMD5(){ return "7a0720910cc0ec58821e5410b89fe667"; };

  };

}
#endif
