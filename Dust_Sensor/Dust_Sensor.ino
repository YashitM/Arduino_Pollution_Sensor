int ledpin2 = 2;    

float voltage = 0;
float actualvoltage = 0;
float dustlevel = 0;
  
void setup(){
  Serial1.begin(230400);
  pinMode(ledpin2,OUTPUT);
}
  
void loop(){
  voltage = analogRead(1);
  actualvoltage = volatge * (5.0 / 1024.0);
  Dustlevel = 0.17 * actualvoltage - 0.1;
  Serial1.print("Dust");
  Serial1.println(Dustlevel);
  if(Dustlevel>100)
  {
    Serial.print("Danger");
  }
  else if (Dustlevel>50 && Dustlevel<100)
  {
    Serial.print("Be careful");
  }
  else
  {
    Serial.print("Everything is fine! :D")
  }
  delay(1000);
}
