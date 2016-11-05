int red = 11;
int green = 10;
int blue = 9;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);  
  pinMode(green, OUTPUT);
}
 
void loop()
{
  analogWrite(red, 255); // for red
  analogWrite(green, 255); // for green
  //both of the above combined give yellow
}

