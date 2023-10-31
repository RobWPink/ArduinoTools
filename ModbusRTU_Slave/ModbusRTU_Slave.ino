
#include <ModbusRTU.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h> //For I2C comms
unsigned long timer = 0;
ModbusRTU      mbRTU;
void setup() {
  Serial1.begin(9600, SERIAL_8N1);
  Serial3.begin(9600, SERIAL_8N1);
  Serial.begin(9600);
  //pinModeSetup();
  mbRTU.begin(&Serial1,12);
  mbRTU.setBaudrate(9600);
  mbRTU.slave(1); 
  mbRTU.addIreg(0,5,100);
  mbRTU.addHreg(0,3,100);
  mbRTU.addCoil(0,1,100);
  mbRTU.addIsts(0,1,100);
  for(int i = 0; i < 50;i++){
    mbRTU.Hreg(i,i*2);
  }
}
void loop() {
  delay(50);
  if(!timer){timer = millis();}
  if(millis() - timer > 1000){
    timer = 0;
    Serial.println(mbRTU.Hreg(2));
  }

  mbRTU.task();
  yield();


}

#define ACT1_PRESS A10
#define ACT1_POS A9
#define ACT1_CLOCK 38
#define ACT1_CTRL 29
#define ACT1_CW 25
#define ACT1_ENABLE 34
#define ACT1_HALF 32
#define ACT1_HOME 36
#define ACT1_RESET 27
#define ACT1_VREF 44

#define ACT2_PRESS A12
#define ACT2_POS A11
#define ACT2_CLOCK 39
#define ACT2_CTRL 28
#define ACT2_CW 24
#define ACT2_ENABLE 35
#define ACT2_HALF 33
#define ACT2_HOME 37
#define ACT2_RESET 26
#define ACT2_VREF 46

#define ACT3_PRESS A7
#define ACT3_POS A6
#define ACT3_CLOCK 5
#define ACT3_CTRL 4
#define ACT3_CW 2
#define ACT3_ENABLE 9
#define ACT3_HALF 8
#define ACT3_HOME 11
#define ACT3_RESET 3
#define ACT3_VREF 6 

#define RLY0 47
#define RLY1 45
#define RLY2 43
#define RLY3 41
#define RLY4 49
#define RLY5 48
#define RLY6 
#define RLY7 
#define RLY8 
#define RLY9
#define RLY10 
#define RLY11 

#define SS 10    //W5500 CS
#define RST 7    //W5500 RST

#define RE_DE1 12
#define RE_DE2 31

#define ESTOP_BREAK 40
#define LED_PWR 22
#define TRACO_24VDC 23
void pinModeSetup() {
  pinMode(12, OUTPUT);
  digitalWrite(12, 0);
  pinMode(ESTOP_BREAK, OUTPUT);
  digitalWrite(ESTOP_BREAK, HIGH);
  pinMode(LED_PWR, OUTPUT);
  digitalWrite(LED_PWR, HIGH);
  pinMode(TRACO_24VDC, OUTPUT);
  digitalWrite(TRACO_24VDC, HIGH);
  pinMode(31, OUTPUT);
  digitalWrite(31, 0);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(SS, OUTPUT);
  pinMode(RST, OUTPUT);
}