#include <avr/wdt.h>

# define RESETWATCHDOG 0

 
void setup() {
  // put your setup code here, to run once:
          Serial.begin(57600);
          Serial.println("");
          Serial.println ("------->Arduino Rebooted");
          Serial.println("");
          // wdt_disable();  desactiva el watch dog para poder tambien cambiar el tiempo.
          wdt_enable(WDTO_8S); // activa en el tiempo del activacion del watchdog esta a 8seg.
         // WDTO_15MS
         // WDTO_30MS
          // WDTO_60MS
          //WDTO_120MS
          //WDTO_250MS  
          //WDTO_500MS
           //WDTO_1S
          //WDTO_2S
          //WDTO_4S
          //WDTO_8S
}

void loop(){
  // put your main code here, to run repeatedly
  if (RESETWATCHDOG){
  wdt_reset(); // reinicia el watchdog para que no se active de nuevo el intervalo se activa RESETWATCHDOG cuando es 1
 
  }
  
  Serial.println("Arduino Running");
  delay(1000);

}
