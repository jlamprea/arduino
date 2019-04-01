////////////////////////////////////////////// 
//        RemoteXY include library NODEMCU V3 // 
////////////////////////////////////////////// 

// RemoteXY select connection mode and include library  
#define REMOTEXY_MODE__ESP8266WIFI_LIB_CLOUD
#include <ESP8266WiFi.h> 

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_WIFI_SSID "UNE_HFC_2E00" 
#define REMOTEXY_WIFI_PASSWORD "ADBB65CF" 
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com" 
#define REMOTEXY_CLOUD_PORT 6376 
#define REMOTEXY_CLOUD_TOKEN "27e6836331313b3b37674933479674c4" // token generado por la aplicacion directamente 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,1,0,1,0,26,0,8,13,0,
  2,0,37,38,25,13,2,26,31,31,
  79,78,0,79,70,70,0,65,4,41,
  9,17,17 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 

    // output variable
  uint8_t EstadoPush_r; // =0..255 LED Red brightness 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

#define PIN_SWITCH_1 D4


void setup()  
{ 
  RemoteXY_Init ();  
   
  pinMode (PIN_SWITCH_1, OUTPUT);
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
   
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?HIGH:LOW);

    if (digitalRead(0) == LOW) // if pin 0 enjoyed a high level voltage 
    RemoteXY.EstadoPush_r = 255;   // then turn on red light 
  else                        // else 
    RemoteXY.EstadoPush_r = 0;     // turn off red 
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 

// toca generar el token desde la web. primero hay que loging.
// al dar Stop a la aplicacion, se detiene y se reanuda desde el nuevo icono de la aplicacion. 
// con clouse se puede cerrar la aplicacion y se cierra la conexion con el servidor cloud.
}
