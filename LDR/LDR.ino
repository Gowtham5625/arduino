/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.13.13 or later version;
     - for iOS 1.10.3 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT


// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377
#define REMOTEXY_ACCESS_PASSWORD "123456"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 70 bytes
  { 255,3,0,0,0,63,0,17,0,0,0,31,1,106,200,1,1,3,0,2,
  26,28,44,22,1,2,26,31,31,79,78,0,79,70,70,0,2,25,75,44,
  22,1,2,26,31,31,79,78,0,79,70,70,0,2,24,122,44,22,1,2,
  26,31,31,79,78,0,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_01; // =1 if switch ON and =0 if OFF
  uint8_t switch_02; // =1 if switch ON and =0 if OFF
  uint8_t switch_03; // =1 if switch ON and =0 if OFF

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  pinMode(11,OUTPUT) ;
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT); 
}

void loop() 
{ 
  RemoteXY_Handler ();
  
digitalWrite(11,HIGH);
delay(1000);
 digitalWrite(11,LOW);
delay(1000);
digitalWrite(12,HIGH);
delay(1000);
digitalWrite(12,LOW);
delay(1000);
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
delay(1000);

}