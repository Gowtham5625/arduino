// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT


// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "Naik@777"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377
#define REMOTEXY_ACCESS_PASSWORD "qwerty123"

#include <RemoteXY.h>
#include <LiquidCrystal.h> 
unsigned long time; 
long int seconds=0; 
int minutes=0; 
int hours=0; 
int set=0; 
int reset=0; 
LiquidCrystal LCD(12, 11, 5, 4, 3, 2); 

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 53 bytes
  { 255,2,0,0,0,46,0,17,0,0,0,31,1,106,200,1,1,2,0,10,
  36,48,24,24,48,4,26,31,79,78,0,31,79,70,70,0,10,37,99,24,
  24,48,4,26,31,79,78,0,31,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t pushSwitch_01; // =1 if state is ON, else =0
  uint8_t pushSwitch_02; // =1 if state is ON, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;  

#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_PUSHSWITCH_01 7
#define PIN_PUSHSWITCH_02 8


void setup() 
{
  RemoteXY_Init (); 
  Serial.begin(9600);                   //initiates serial communication 
  LCD.begin(16, 2);     //sets the number of columns and rows 
  pinMode(8,INPUT); 
  pinMode(7,INPUT); 
  pinMode(PIN_PUSHSWITCH_01, OUTPUT);
  pinMode(PIN_PUSHSWITCH_02, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 

  RemoteXY_Handler ();
  
  digitalWrite(PIN_PUSHSWITCH_01, (RemoteXY.pushSwitch_01==0)?LOW:HIGH);
  digitalWrite(PIN_PUSHSWITCH_02, (RemoteXY.pushSwitch_02==0)?LOW:HIGH);
  
  // TODO you loop code
  if(digitalRead(8)==1) 
{ 
 while(digitalRead(7)==0) 
{   
setClock();         //function 
LCD.setCursor(0,1);     //sets the cursor to 0th column and 1st row,numbering starts from 0 
{ 
if(hours<10)        //suppose 4 
{ 
LCD.print("0");     //LCD first prints 0 and stopwatch shows 0 
LCD.print(hours);       //LCD then prints 4. So value printed is 04 stopwatch shows 04 
} 
else 
{ 
LCD.print(hours); 
} 
} 
LCD.print(":"); 
{ 
if(minutes<10) 
{ 
LCD.print("0"); 
LCD.print(minutes); 
LCD.print(":"); 
} 
else 
{ 
LCD.print(minutes); 
LCD.print(":"); 
} 
} 
{ 
if(seconds<10) 
{ 
LCD.print("0"); 
LCD.print(seconds); 
} 
else 
{ 
LCD.print(seconds); 
} 
} 
} 
}
} 

void setClock() 
{ 
seconds++;       //counts seconds from 0 
delay(1000);     //a delay of 1000 milliseconds is given for each second count 
if (seconds>59) 
{ 
seconds=0;      //whenever second is greater than 59 than second is made equal to 
minutes++;     // zero and a minute is counted for it 
} 
if (minutes>59) 
{hours++; 
minutes=0; 
} 

if(hours>23) 
{ 
hours=0; 
} 
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


}