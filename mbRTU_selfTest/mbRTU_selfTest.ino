
#include <ModbusRTU.h>
unsigned long timer = 0;
ModbusRTU      mbM;
ModbusRTU      mbS;
uint16_t y[8] = {0};
bool cbWrite(Modbus::ResultCode event, uint16_t transactionId, void* data){ //callback function to observe transmission status
  Serial.print("Request result: 0x");
  Serial.println(event, HEX);
  return true;
}

void setup() {
  Serial.begin(9600);
  pinModeSetup();
  Serial1.begin(9600, SERIAL_8N1);
  Serial3.begin(9600, SERIAL_8N1);
  mbM.begin(&Serial1,12);
  mbM.setBaudrate(9600);
  mbM.master();
  mbS.begin(&Serial3,31);
  mbS.setBaudrate(9600);
  mbS.slave(30); 
  mbS.addHreg(0,3,100);
  for(int i = 0; i < 50;i++){
    mbS.Hreg(i,i*2);
  }
}

void loop() {

 mbM.readHreg(30,1,y,2,cbWrite);
 while(mbM.slave()) { // Needed for library to actually read/write
    mbM.task();
    yield();
  }
   
  
  if(!timer){timer = millis();}
  if(millis() - timer > 1000){
    Serial.println();
    timer = 0;
    Serial.println(mbS.Hreg(2));
    for(int i = 0; i< 8; i++){
      Serial.print(y[i]);
      if(i != 7){Serial.print(",");}
    }
    Serial.println();
  }

  mbS.task();
  yield();
  delay(50);

}
#define SS 10    //W5500 CS
#define RST 7    //W5500 RST

#define RE_DE1 12
#define RE_DE2 31

#define ESTOP_BREAK 40
#define LED_PWR 22
#define TRACO_24VDC 23

#define I2C_ADC1 0x49
#define I2C_ADC2 0x4B
//#define I2C_DAC 0x60
#define I2C_IOEXP 0x60
#define I2C_IoT 0x48
#define I2C_INERT 0x68
#define I2C_RTC 0x51
#define I2C_ESP32 0x69 // configurable 
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