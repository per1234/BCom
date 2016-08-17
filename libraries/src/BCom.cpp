#include "Arduino.h"
#include "BCom.h"

BFrameIn::printTo(Print& p)
{
  p.print("{Start:");
  p.print(start,DEC);
  p.print(",throttle:");
  p.print(throttle,DEC);
  p.print(",yaw:");
  p.print(yaw,DEC);
  p.print(",pitch:");
  p.print(pitch,DEC);
  p.print(",roll:");
  p.print(roll,DEC);
  p.print(",yAccel:");
  p.print(yA,DEC);
  p.print(",zAccel:");
  p.print(zA,DEC);
  p.print(",LED:");
  p.print(LED,DEC);
  p.print(",REC:");
  p.print(REC,DEC);
  p.print(",CheckSum:");
  p.print(Ch,DEC);
  p.print(",End:");
  p.print(End,DEC);
  p.print("}");
}
 
int BCom::read(BFrameIn *frame)
{
  int a = 0;
  while(a<11)
  {
    if(available()>0)
    {
      switch(a){
        case 0:
        frame->start = read();
             break;

        case 1:
        frame->throttle=read();
             break;

        case 2:
        frame->yaw=read();
             break;

        case 3:
        frame->pitch=read();
              break;

        case 4:
        frame->roll=read();
              break;

        case 5:
        frame->yA=read();
              break;

        case 6:
        frame->zA=read();
              break;

        case 7:
        frame->LED=read();
              break;

        case 8:
        frame->REC=read();
              break;

        case 9:
        frame->Ch=read();
              break;

        case 10:
        frame->End=read();
        break;

      }
      a++;
    }
  }
}
 
int BCom::available(void)
{
  return sub_stream.available();
}

int BCom::peek(void)
{
  return sub_stream.peek();
}

int BCom::read(void)
{
  return sub_stream.read();
}

void BCom::flush(void)
{
  return sub_stream.flush();
}

size_t BCom::write(uint8_t c)
{
  return sub_stream.write(c);
}