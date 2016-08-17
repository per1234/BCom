#ifndef Bread_h;
#define Bread_h;

#include "Bread.h";

Class Bread{
	public:
		void Bread();
		void show();
		void save();
		Bframe myframe;
	private:
			typedef struct Bframe{
				int start,Ch,End,throttle,yaw,pitch,roll,LED,REC,b;
 				char yA,zA;
			}Bframe;
		Bframe newframe;
			
};
