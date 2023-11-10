/*
  Ethernet Modbus TCP Server LED

  This sketch creates a Modbus TCP Server with a simulated coil.
  The value of the simulated coil is set on the LED

  Circuit:
   - Any Arduino MKR Board
   - MKR ETH Shield

  created 16 July 2018
  by Sandeep Mistry
*/
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

#define ACT3_PRESS A13
#define ACT3_POS 
#define ACT3_CLOCK 5
#define ACT3_CTRL 4
#define ACT3_CW 2
#define ACT3_ENABLE 9
#define ACT3_HALF 8
#define ACT3_HOME 11
#define ACT3_RESET 3
#define ACT3_VREF 6

//#define RLY0 47
//#define RLY1 45
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

#define SS 10  //W5500 CS
#define RST 7  //W5500 RST

#define DEMAND 45
#define OK 47
#define ESTOP_BREAK 40
#define LED_PWR 22
#define TRACO_24VDC 23

#define RE_DE1 12
#define RE_DE3 31

#include <SPI.h>
#include <Ethernet.h>

#include <ArduinoRS485.h> // ArduinoModbus depends on the ArduinoRS485 library
#include <ArduinoModbus.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xA2, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 10);

EthernetServer ethServer(502);

ModbusTCPServer modbusTCPServer;

const int ledPin = LED_BUILTIN;

unsigned long timer = 0;
void (*resetFunc)(void) = 0; 
void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  pinModeSetup();

 Ethernet.init(10);
  Ethernet.begin(mac, ip);
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
  timer = 0;

  // start the server
  ethServer.begin();
  
  // start the Modbus TCP server
  if (!modbusTCPServer.begin()) {
    Serial.println("Failed to start Modbus TCP Server!");
    while (1);
  }

  // configure the LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // configure a single coil at address 0x00
  modbusTCPServer.configureCoils(0x00, 1);
}

void loop() {
  // listen for incoming clients
  EthernetClient client = ethServer.available();
  
  if (client) {
    // a new client connected
    Serial.println("new client");

    // let the Modbus TCP accept the connection 
    modbusTCPServer.accept(client);

    while (client.connected()) {
      // poll for Modbus TCP requests, while client connected
      modbusTCPServer.poll();

      // update the LED
      updateLED();
    }

    Serial.println("client disconnected");
  }
}

void updateLED() {
  // read the current value of the coil
  int coilValue = modbusTCPServer.coilRead(0x00);

  if (coilValue) {
    // coil value set, turn LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // coild value clear, turn LED off
    digitalWrite(ledPin, LOW);
  }
}

void pinModeSetup() {
  // Inputs
  pinMode(DEMAND, INPUT);

  // Power
  pinMode(ESTOP_BREAK, OUTPUT);
  digitalWrite(ESTOP_BREAK, HIGH);
// Ethernet
  pinMode(7, OUTPUT );
  digitalWrite(7, HIGH);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(SS, OUTPUT);
  pinMode(RST, OUTPUT);
  digitalWrite(SS, LOW);

  pinMode(LED_PWR, OUTPUT);
  digitalWrite(LED_PWR, HIGH);
  pinMode(31, OUTPUT);
  digitalWrite(31, 0);
  pinMode(12, OUTPUT);
  digitalWrite(12, 0);
  pinMode(TRACO_24VDC, OUTPUT);
  digitalWrite(TRACO_24VDC, HIGH);

  pinMode(RLY2, OUTPUT);
  digitalWrite(RLY2, LOW);

  pinMode(RLY3, OUTPUT);
  digitalWrite(RLY3, LOW);
}
