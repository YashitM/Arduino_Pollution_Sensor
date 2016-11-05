//#include "MQ135.h"

int ppm;
int ledpin = 5;
void setup()
{
  Serial.begin(9600);      // sets the serial port to 9600
  pinMode(ledpin, OUTPUT);
}

void loop()
{
  ppm = analogRead(0); 
  Serial.print(ppm, DEC); 
  Serial.println(ppm,2);
  if (ppm>500) {
    digitalWrite(ledpin, HIGH);
  }
  else {
    digitalWrite(ledpin, LOW);
  }

  delay(100);
}
