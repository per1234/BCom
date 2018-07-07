#include "Arduino.h"
#include "Printable.h"
#include "BCom.h"


BCom::BCom(Stream *sub_stream)
:sub_stream(sub_stream)
{
}
 
int BCom::read(BFrameIn& frame)
{
  int a = 0;
  BFrameIn temp_frame;

  while(a<11)
  {
    if(available()>0)
    {
      switch(a)
      {
        case 0:
        temp_frame.start = read();
        if(temp_frame.start != 240)
        {
          return 0;
        }
        break;

        case 1:
        temp_frame.throttle=read();
        break;

        case 2:
        temp_frame.yaw=read();
        break;

        case 3:
        temp_frame.pitch=read();
        break;

        case 4:
        temp_frame.roll=read();
        break;

        case 5:
        temp_frame.yA=read();
        break;

        case 6:
        temp_frame.zA=read();
        break;

        case 7:
        temp_frame.LED=read();
        break;

        case 8:
        temp_frame.REC=read();
        break;

        case 9:
        temp_frame.Ch=read();
        break;

        case 10:
        temp_frame.End=read();
        if(temp_frame.End = 250)
        {
          frame = temp_frame;
        }

        break;
      }
      a++;
    }
  }
  return 1;
}
 
int BCom::available(void)
{
  return sub_stream->available();
}

int BCom::peek(void)
{
  return sub_stream->peek();
}

int BCom::read(void)
{
  return sub_stream->read();
}

void BCom::flush(void)
{
  return sub_stream->flush();
}

size_t BCom::write(uint8_t c)
{
  return sub_stream->write(c);
}