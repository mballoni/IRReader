//#include <IRremoteInt.h>
#include <IRremote.h>

/* RGB Remote Control
   by: Jim Lindblom
   SparkFun Electronics
   date: October 1, 2013

   This sketch uses Ken Shirriff's *awesome* IRremote library:
       https://github.com/shirriff/Arduino-IRremote



















 */

/* Connect the output of the IR receiver diode to pin 11. */
int RECV_PIN = 11;
/* Initialize the irrecv part of the IRremote  library */
IRrecv irrecv(RECV_PIN);
decode_results results; // This will store our IR received codes

void setup()
{
  Serial.begin(9600); // Use serial to debug. 
  irrecv.enableIRIn(); // Start the receiver
}


void loop() 
{
  if (irrecv.decode(&results)) {
    uint16_t resultCode = (results.value & 0xFFFF);
    if (resultCode == 0xFFFF) {
      Serial.println("held");      
    } else {
      Serial.println(results.value, HEX);
    }
    irrecv.resume();
  }
}

