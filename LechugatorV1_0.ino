/*Thanks to:
 David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 
 This program was created based on yours!
 
 Lechugator V1.0
 
 Written by: Daniel Sanchez a.k.a. Spartanhack
 
 */
 
const int valpin =  13;        // Pin that goes to the resistor

int val = LOW;                     // Waterbomb state
long off = 10800000, on = 300000;  //Assign on/off intervals
long laston = 0, lastoff = 0;
unsigned long time = 0;

void setup() {
  // set the digital pin as output:
  pinMode(valpin, OUTPUT);      
}

void loop()
{
  time = millis();
  
  if(time - laston > on && val == HIGH ){
      val = LOW;
      lastoff = time;
    }
    else {
      if(time - lastoff > off && val == LOW ){
        val = HIGH;
        laston = time;
      }
    }
    digitalWrite(valpin, val);
  }
}
