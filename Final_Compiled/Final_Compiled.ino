int greenpin = 7;    
float gas;
int bluepin = 6;
float voltage = 0;
float actualvoltage = 0;
float Dustlevel;
int redpin = 5;
  
void setup(){
  Serial.begin(9600);
}
  
void loop(){
  gas = analogRead(0); 
  if (gas>500.0) {
    Serial.print ("High gas: ");
    Serial.println (gas,DEC);
  }
  else {
    Serial.print ("Gas Value: ");
    Serial.println (gas,DEC);
    }

  delay(2000);
  voltage = analogRead(1);
  actualvoltage = voltage * (5.0 / 1024.0);
  Dustlevel = (0.17 * actualvoltage - 0.1)*-1000;
  //Serial.println(Dustlevel);

  if (Dustlevel>600.0){
    //display_led(dangerous);
    Serial.print("Danger: ");
    Serial.println(Dustlevel,DEC);
    analogWrite(redpin,255);
  }
  if(Dustlevel>400.0 && Dustlevel<=600.0){
    //display_led(non_acceptable);
    Serial.print("non_acceptable: ");
    Serial.println(Dustlevel,DEC);
    analogWrite(bluepin,165);
  
  }
  if(Dustlevel>225.0 && Dustlevel<=400.0){
    //display_led(acceptable);
    Serial.print("acceptable: ");
    Serial.println(Dustlevel,DEC);
    analogWrite(greenpin,255);
  }
  if(Dustlevel>=100.0 && Dustlevel<=225.0) {
    //display_led(normal);
    Serial.print("normal: ");
    Serial.println(Dustlevel,DEC);
    analogWrite(redpin,255);
    analogWrite(bluepin,255);
    analogWrite(greenpin,255);
  }
  else {
    Serial.print("normal: ");
    Serial.println(Dustlevel,DEC);
  }
  delay(2000);
}

