#include "arduino.h"
#include "Bread.h"


void Bread::Bread(){
	 if(Serial.available()>0){

      switch(a){
        case 1:
        a++;
        newFrame.start = Serial.read();
             break;
        case 2:
         a++;
        newFrame.throttle=Serial.read();
             break;
        case 3:
        a++;
        newFrame.yaw=Serial.read();
             break;
        case 4:
        a++;
        newFrame.pitch=Serial.read();
              break;
        case 5:
        a++;
        newFrame.roll=Serial.read();
              break;
        case 6:
        a++;
        newFrame.yA=Serial.read();
              break;
        case 7:
        a++;
        newFrame.zA=Serial.read();
              break;
        case 8:
        a++;
        newFrame.LED=Serial.read();
              break;
        case 9:
        a++;
        newFrame.REC=Serial.read();
        
              break;
        case 10:
        a++;
        newFrame.Ch=Serial.read();
        
              break;
        case 11:
        a=1;
        newFrame.End=Serial.read();
              break;

      }
    }
 }
 
 void Bread::save(){
 	myframe.start = newframe->start;
 	myframe.throttle = newframe->throttle;
 	myframe.yaw = newframe->yaw;
 	myframe.pitch = newframe->pitch;
 	myframe.roll = newframe->roll;
 	myframe.yA = newframe->yA;
 	myframe.zA = newframe->zA;
 	myframe.LED = newframe->LED;
 	myframe.REC = newframe.REC;
 	myframe.Ch = newframe->Ch;
 	myframe.End = newframe->End;	
 }
 
 void Bread::show(){
 	   Serial.print("Start: ");
   Serial.println(newFrame.start,DEC);
   Serial.print("throttle: ");
   Serial.println(newFrame.throttle,DEC);
   Serial.print("yaw: ");
   Serial.println(newFrame.yaw,DEC);
   Serial.print("pitch: ");
   Serial.println(newFrame.pitch,DEC);
   Serial.print("roll: ");
   Serial.println(newFrame.roll,DEC);
   Serial.print("yAccelaration: ");
   Serial.println(newFrame.yA,DEC);
   Serial.print("zAccelaration: ");
   Serial.println(newFrame.zA,DEC);
   Serial.print("LED: ");
   Serial.println(newFrame.LED,DEC);
   if(newFrame.LED==1)
        {
            analogWrite(LED_PIN1,map(newFrame.throttle,0,100,0,255));
        }
   else if(newFrame.LED==0)
        {
            digitalWrite(LED_PIN1,LOW);
        }
   Serial.print("REC: ");
   Serial.println(newFrame.REC,DEC);
   Serial.print("CheckSum: ");
   Serial.println(newFrame.Ch,DEC);
   Serial.print("End: ");
   Serial.println(newFrame.End,DEC);
 }
