/*
 TouchWheel.pde
 MPR121 WhellPad Example Code
 
 by:Waiman Zhao
 Mail:Binpower@foxmail.com
 created on: 11/2/14
 license: CC-SA 3.0
 
 Hardware: 3.3V Arduino Pro Mini
           SDA -> A4
           SCL -> A5
           IRQ -> D2
*/


#include <Wire.h>
#include <mpr121.h>

short key = 0;


// =========  setup  =========
void setup()
{ 
	//  initialize function
  Serial.begin(19200);
  Wire.begin();
  CapaTouch.begin();

  delay(500);
  Serial.println("START"); 
}


// =========  loop  =========
void loop()
{
  key=CapaTouch.getAll(12);

  for (int i = 0; i < 12; i++) { // Check all sensors
    Serial.print("zones: ")
    if (zones & (1 << i)) {
      Serial.print(i+1);
      Serial.print(" ");
    }
    Serial.println();
  }
	delay(200);
}



 



