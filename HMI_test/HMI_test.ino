#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h> //For I2C comms
#include <ArduinoModbus.h>  //for modbus tcp/ip
#define ESTOP_BREAK 40
#define LED_PWR 22
#define TRACO_24VDC 23

#define SS 10    //W5500 CS
#define RST 7    //W5500 RST
#define CS 4     //SD CS pin

byte mac[] = {0xDE, 0xA1, 0xBE, 0xEF, 0xFA, 0xED};
IPAddress HMIip(192, 168, 2, 88);
IPAddress local_ip(192, 168, 2, 52);
EthernetClient hmi;
ModbusTCPClient HMI(hmi);
unsigned long timer = 0;
bool tog = false;
int inp = 0;
void (*resetFunc)(void) = 0;  // Allows hard reset of arduino through software
void setup() {
  pinModeSetup();
  Serial.begin(9600);
  Ethernet.init(10);
  Ethernet.begin(mac, local_ip);
  delay(5);
  if (Ethernet.linkStatus() == LinkOFF || Ethernet.hardwareStatus() == EthernetNoHardware) {
    bool r, s = false;
    if (!timer) { timer = millis(); }
    while (1) {
      if (Ethernet.linkStatus() != LinkOFF && Ethernet.hardwareStatus() != EthernetNoHardware) {
        Serial.println("Ethernet hardware connected.");
        break;
      }
      if (millis() - timer > 10000 && timer) {
        resetFunc();
        timer = 0;
      }
      if (Ethernet.hardwareStatus() == EthernetNoHardware && !r) {
        Serial.println("Ethernet hardware was not found.");
        r = true;
      }
      if (Ethernet.linkStatus() == LinkOFF && !s) {
        Serial.println("Ethernet cable connection not detected.");
        s = true;
      }
    }
  }

  if (!HMI.connected()) {
    HMI.begin(HMIip, 502);
  }

}

void loop() {

  HMI.holdingRegisterWrite(0,1111);
  HMI.holdingRegisterWrite(1,2222);
  HMI.holdingRegisterWrite(2,3333);
  HMI.coilWrite(0,tog);
  HMI.coilWrite(1,!tog);
  HMI.coilWrite(2,tog);
  int rec = HMI.holdingRegisterRead(3);
  if(HMI.coilRead(3)){Serial.println("button");}
  if(inp != rec){inp = rec; Serial.println(rec);}
  
  if(!timer){timer = millis();}
  if(millis() - timer > 1000 && timer){
    timer = millis();
    if (!HMI.connected()) {
    HMI.begin(HMIip, 502);
  }
    tog = !tog;
  }
  

}

void pinModeSetup() {
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(SS, OUTPUT);
  pinMode(RST, OUTPUT);
  pinMode(CS, OUTPUT);
  digitalWrite(SS, LOW);
  digitalWrite(CS, HIGH);
  pinMode(12, OUTPUT);
  digitalWrite(12, 0);
  pinMode(ESTOP_BREAK, OUTPUT);
  digitalWrite(ESTOP_BREAK, HIGH);

  pinMode(LED_PWR, OUTPUT);
  digitalWrite(LED_PWR, HIGH);

  pinMode(TRACO_24VDC, OUTPUT);
  digitalWrite(TRACO_24VDC, HIGH);
}
