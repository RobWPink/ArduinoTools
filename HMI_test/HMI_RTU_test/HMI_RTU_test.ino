#include <ModbusMaster_oneH2.h>
#define ESTOP_BREAK 40
#define LED_PWR 22
#define TRACO_24VDC 23

#define REDE 12
#define HMIrtu 63
int i = 0;
ModbusMaster mbRTU;
unsigned long timer = 0;
bool tog = false;
double inp = 0;
void (*resetFunc)(void) = 0;  // Allows hard reset of arduino through software
void setup() {
  pinModeSetup();
  Serial.begin(9600);
  Serial1.begin(9600);
  mbRTU.begin(HMIrtu, Serial1);
  mbRTU.preTransmission(preTransmission);
  mbRTU.postTransmission(postTransmission);
}

void loop() {
 i++;
  mbRTU.setTransmitBuffer(0,1111+i);
  mbRTU.setTransmitBuffer(1,2222+i);
  mbRTU.setTransmitBuffer(2,3333+i);
  uint8_t result = mbRTU.writeMultipleRegisters(0,3);
  if(result == mbRTU.ku8MBSuccess){
    mbRTU.readHoldingRegisters(3,1);
    Serial.println(mbRTU.getResponseBuffer(0));
  }
  mbRTU.clearResponseBuffer();
  delay(500);
  mbRTU.readCoils(3,1);
  tog = mbRTU.getResponseBuffer(0);
  mbRTU.writeSingleCoil(0,tog);
  mbRTU.writeSingleCoil(1,!tog);
  mbRTU.writeSingleCoil(2,tog);
}

void preTransmission() {digitalWrite(REDE, 1);}
void postTransmission() {digitalWrite(REDE, 0);}

void pinModeSetup() {

  pinMode(ESTOP_BREAK, OUTPUT);
  digitalWrite(ESTOP_BREAK, HIGH);

  pinMode(LED_PWR, OUTPUT);
  digitalWrite(LED_PWR, HIGH);
  
  pinMode(REDE, OUTPUT);
  digitalWrite(REDE, LOW);

  pinMode(TRACO_24VDC, OUTPUT);
  digitalWrite(TRACO_24VDC, HIGH);
}
