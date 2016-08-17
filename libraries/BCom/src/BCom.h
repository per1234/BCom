#ifndef _BCOM_H_
#define _BCOM_H_

#include "Arduino.h"
#include "Stream.h"
#include "Printable.h"


class BFrameIn : public Printable
{
  public:
   // BFrameIn();

    size_t printTo(Print& p) const
    {
      size_t bytes_send = 0;

      bytes_send += p.print("{Start:");
      bytes_send += p.print(start,DEC);
      bytes_send += p.print(",throttle:");
      bytes_send += p.print(throttle,DEC);
      bytes_send += p.print(",yaw:");
      bytes_send += p.print(yaw,DEC);
      bytes_send += p.print(",pitch:");
      bytes_send += p.print(pitch,DEC);
      bytes_send += p.print(",roll:");
      bytes_send += p.print(roll,DEC);
      bytes_send += p.print(",yAccel:");
      bytes_send += p.print(yA,DEC);
      bytes_send += p.print(",zAccel:");
      bytes_send += p.print(zA,DEC);
      bytes_send += p.print(",LED:");
      bytes_send += p.print(LED,DEC);
      bytes_send += p.print(",REC:");
      bytes_send += p.print(REC,DEC);
      bytes_send += p.print(",CheckSum:");
      bytes_send += p.print(Ch,DEC);
      bytes_send += p.print(",End:");
      bytes_send += p.print(End,DEC);
      bytes_send += p.print("}");

      return bytes_send;
    }

    /* data */
    int start,Ch,End,throttle,yaw,pitch,roll,LED,REC,b;
    char yA,zA;

// private:
//     size_t selfPrint(Print& p);
};


class BCom: public Stream
{
  public:
    BCom(Stream *sub_stream);

    void read(BFrameIn frame);

    // virtual functions from Stream class
    virtual int available(void);
    virtual int peek(void);
    virtual int read(void);
    virtual void flush(void);
    virtual size_t write(uint8_t);

  private:
    Stream *sub_stream;
};


#endif
