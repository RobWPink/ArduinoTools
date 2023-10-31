#include <Wire.h>
#include "pins.h"
Adafruit_LiquidCrystal lcd(0);
SmallMatrix smallMatrix[3] = { SmallMatrix(0x70), SmallMatrix(0x71), SmallMatrix(0x72) };
LargeMatrix bigMatrix[3] = { LargeMatrix(0x73), LargeMatrix(0x74), LargeMatrix(0x75) };
void setup()
{
  Wire.begin();
 
  Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");
  delay(100);
  pinMode(ESTOP_BREAK, OUTPUT);
  digitalWrite(ESTOP_BREAK, HIGH);
  pinMode(LED_PWR, OUTPUT);
  digitalWrite(LED_PWR, HIGH);
  pinMode(TRACO_24VDC, OUTPUT);
  digitalWrite(TRACO_24VDC, HIGH);

  pinMode(ACT1_ENABLE, OUTPUT);
  digitalWrite(ACT1_ENABLE, LOW);
  pinMode(ACT1_CLOCK, OUTPUT);
  digitalWrite(ACT1_CLOCK, LOW);
  pinMode(ACT1_HOME, OUTPUT);
  digitalWrite(ACT1_HOME, LOW);
  pinMode(ACT1_HALF, OUTPUT);
  digitalWrite(ACT1_HALF, LOW);
  pinMode(ACT1_RESET, OUTPUT);
  digitalWrite(ACT1_RESET, LOW);
  pinMode(ACT1_CW, OUTPUT);
  digitalWrite(ACT1_CW, LOW);
  pinMode(ACT1_CTRL, OUTPUT); 
  digitalWrite(ACT1_CTRL, LOW);

  pinMode(ACT2_ENABLE, OUTPUT);
  digitalWrite(ACT2_ENABLE, LOW);
  pinMode(ACT2_CLOCK, OUTPUT);
  digitalWrite(ACT2_CLOCK, LOW);
  pinMode(ACT2_HOME, OUTPUT);
  digitalWrite(ACT2_HOME, LOW);
  pinMode(ACT2_HALF, OUTPUT);
  digitalWrite(ACT2_HALF, LOW);
  pinMode(ACT2_RESET, OUTPUT);
  digitalWrite(ACT2_RESET, LOW);
  pinMode(ACT2_CW, OUTPUT);
  digitalWrite(ACT2_CW, LOW);
  pinMode(ACT2_CTRL, OUTPUT); 
  digitalWrite(ACT2_CTRL, LOW);

  pinMode(ACT3_ENABLE, OUTPUT);
  digitalWrite(ACT3_ENABLE, LOW);
  pinMode(ACT3_CLOCK, OUTPUT);
  digitalWrite(ACT3_CLOCK, LOW);
  pinMode(ACT3_HOME, OUTPUT);
  digitalWrite(ACT3_HOME, LOW);
  pinMode(ACT3_HALF, OUTPUT);
  digitalWrite(ACT3_HALF, LOW);
  pinMode(ACT3_RESET, OUTPUT);
  digitalWrite(ACT3_RESET, LOW);
  pinMode(ACT3_CW, OUTPUT);
  digitalWrite(ACT3_CW, LOW);
  pinMode(ACT3_CTRL, OUTPUT); 
  digitalWrite(ACT3_CTRL, LOW);
}
 
 
void loop()
{
  byte error, address;
  int nDevices,aa;
  
  Serial.println("Scanning...");
  aa = 0;
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
      aa++;
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.print("Found ");
    Serial.print(aa);
    Serial.println(" devices.");
    Serial.println("done\n");
    
 
  delay(5000);           // wait 5 seconds for next scan
}
void matrixSetup(String s1, String s2) {
  //begin matrix
  for (int i = 0; i < 3; i++) {
    smallMatrix[i].begin();
    bigMatrix[i].begin();
  }
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print(s1);
  lcd.setCursor(0, 1);
  lcd.print(s2);
  lcd.setBacklight(HIGH);
  lcd.display();
}
