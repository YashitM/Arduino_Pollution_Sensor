int ledpin2 = 2;    
int ppm;
int ledpin = 5;
float voltage = 0;
float actualvoltage = 0;
float dustlevel = 0;
  
void setup(){
  Serial1.begin(9600);
  pinMode(ledpin2,OUTPUT);
  pinMode(ledpin, OUTPUT);
}
  
void loop(){
  ppm = analogRead(0); 
  Serial.print("ppm: ");
  Serial.print(ppm, DEC); 
  if (ppm>500) {
    digitalWrite(ledpin, HIGH);
  }
  else {
    digitalWrite(ledpin, LOW);
  }
  delay(1000);
  voltage = analogRead(1);
  actualvoltage = volatge * (5.0 / 1024.0);
  Dustlevel = 0.17 * actualvoltage - 0.1;
  Serial1.print("Dust");
  Serial1.println(Dustlevel);
  if(Dustlevel>131)
  {
    Serial.print("Danger");
  }
  if(Dustlevel>61 && Dustlevel<=130)
  {
    Serial.print("Be careful");
  }
  else if (Dustlevel<60)
  {
    Serial.print("It's alright");
  }
  delay(1000);
}
