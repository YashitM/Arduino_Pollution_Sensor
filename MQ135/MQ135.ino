int ppm;

int red=10;
int green=12;
int blue=11;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  ppm = analogRead(0); 
  if (ppm>500) {
    Serial.println("high: ");
    Serial.print (ppm);
    Serial.println("");
    analogWrite(red,255);
  }
  else {
    Serial.print ("low: ");
    Serial.print (ppm);
    Serial.println();
    analogWrite(green,255);
  }
  delay(1000);
}
