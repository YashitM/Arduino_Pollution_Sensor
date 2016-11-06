int greenpin = 12;    
int gas;
int bluepin = 11;
float voltage = 0;
float actualvoltage = 0;
int Dustlevel;
int redpin = 10;
  
void setup(){
  Serial.begin(9600);
}
  
void loop(){
  gas = analogRead(0); 
  if (gas>500) {
    Serial.print ("High gas: ");
    Serial.println (gas);
  }
  else {
    Serial.print ("Gas Value: ");
    Serial.println (gas);
    }

  delay(5000);
  voltage = analogRead(1);
  actualvoltage = voltage * (5.0 / 1024.0);
  Dustlevel = (0.17 * actualvoltage - 0.1)*-1000;

  if (Dustlevel>600){
    //display_led(dangerous);
    Serial.print("Danger: ");
    Serial.println(Dustlevel);
    analogWrite(redpin,255);
  }
  if(Dustlevel>400 && Dustlevel<=600){
    //display_led(non_acceptable);
    Serial.print("non_acceptable: ");
    Serial.println(Dustlevel);
    analogWrite(bluepin,165);
  
  }
  if(Dustlevel>225 && Dustlevel<=400){
    //display_led(acceptable);
    Serial.print("acceptable: ");
    Serial.println(Dustlevel);
    analogWrite(greenpin,255);
  }
  if(Dustlevel>=100 && Dustlevel<=225) {
    //display_led(normal);
    Serial.print("normal: ");
    Serial.println(Dustlevel);
    analogWrite(redpin,255);
    analogWrite(bluepin,255);
    analogWrite(greenpin,255);
  }
  else {
    Serial.print("normal: ");
    Serial.println(Dustlevel);
    analogWrite(redpin,255);
    analogWrite(bluepin,255);
    analogWrite(greenpin,255);
  }
  delay(5000);
}


void setColor(int red, int green,int blue)
{
  analogWrite(redpin, red);
  analogWrite(bluepin, blue);
  analogWrite(redpin, red);
  
  
}

