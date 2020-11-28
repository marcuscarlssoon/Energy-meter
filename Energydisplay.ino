
#include <LiquidCrystal_I2C.h>  //LCD library

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //LCD I2C command'


long pulseCount = 0; //number of pulses(number of Wh)
unsigned long pulseTime, lastTime; // measure time between pulses
double power;  //calculated power
float current; //calculated current
int voltage = 234.0; //measured mains voltage

void setup()
{
  
 lcd.begin(16,2);

  // pulse detection interrupt (emontx pulse channel - IRQ0 (pin D3))
  attachInterrupt(1, onPulse, FALLING);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(round(power));
  lcd.print("W  "); 
  lcd.print(current); 
  lcd.print("A");
  lcd.setCursor(0,1);
  lcd.print(pulseCount); // watt hour elapsed
  lcd.print("Wh");
  delay(1000);

    
}

// The interrupt routine - runs each time a falling edge of a pulse is detected
void onPulse()
{
  lastTime = pulseTime; //copy value of pulseTime to lastTime 
  pulseTime = micros(); //number of microseconds since last loop is new value on pulseTime
  pulseCount++;  
  power = int(3600000000.0 / (pulseTime - lastTime)); // calculate power (3600000000.0 is microseconds per hour) 
  current = power/voltage;

}
