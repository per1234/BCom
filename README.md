# BCom
Arduino library for communicating trough bluetooth with the DroneRemote Android program from @MRinalducci


Incoming frame:
- Start = 240 
- Throttle = 0-100%
- Yaw = 0-100%
- Pitch = 0-100% 
- Roll = 0-100% 
- yAccelerometer = 60-110 degrees
- zAccelerometer = 60-110 degrees
- LED = 0-1 boolean
- REC = 0-1 boolean
- Checksum = 0-255
- End = 250
