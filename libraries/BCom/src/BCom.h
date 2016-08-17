#ifndef _BCOM_H_
#define _BCOM_H_

#include "Arduino.h"
#include "Stream.h"


class BFrameIn : Printable
{
  public:
    BFrameIn();

    virtual size_t printTo(Print& p);

    /* data */
    int start,Ch,End,throttle,yaw,pitch,roll,LED,REC,b;
    char yA,zA;
};


class BCom: public Stream
{
  public:
    void BCom();

    void read(BFrameIn *frame);

    // virtual functions from Stream class
    virtual int available(void);
    virtual int peek(void);
    virtual int read(void);
    virtual void flush(void);
    virtual size_t write(uint8_t);

  private:
    Stream sub_stream;
};


#endif
