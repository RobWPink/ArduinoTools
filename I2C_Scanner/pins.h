#include <LedHelper.h>

#include <Adafruit_LEDBackpack.h>
#include <Adafruit_GFX.h>

#include <Adafruit_LiquidCrystal.h>

#define MAN1_PRESS A6
#define MAN2_PRESS A7

//C1
#define ACT1_PRESS A10
#define ACT1_POS A9
#define ACT1_CLOCK 38
#define ACT1_RESET 27
#define ACT1_CW 25
#define ACT1_ENABLE 34
#define ACT1_HOME 36
#define ACT1_CTRL 29
#define ACT1_HALF 32
#define C1_TT1 A0
#define C1_TT2 A1

//C2
#define ACT2_PRESS A12
#define ACT2_POS A11
#define ACT2_CLOCK 39
#define ACT2_CTRL 28
#define ACT2_CW 24
#define ACT2_ENABLE 35
#define ACT2_HALF 33
#define ACT2_HOME 37
#define ACT2_RESET 26
#define C2_TT1 A2
#define C2_TT2 A3

//C3
#define ACT3_PRESS A14
#define ACT3_POS A13
#define ACT3_CLOCK 5
#define ACT3_CTRL 4
#define ACT3_CW 2
#define ACT3_ENABLE 9
#define ACT3_HALF 8
#define ACT3_HOME 11
#define ACT3_RESET 3
#define ACT3_VREF 6
#define C3_TT1 A4
#define C3_TT2 A5


#define XV_IN 47 //RLY0
#define XV_OUT 45 //RLY1
#define RPL 43 //RLY2
#define APL 41 //RLY3
#define GPL 49 //RLY4
#define BPL 48 //RLY5
#define RLY6
#define DEMAND 13 //RLY7
#define SUPPLY 42 //RLY8
#define INTERLOCK 44 //RLY9
#define RLY10
#define RLY11

#define H2SNIFFER0 A8
#define H2SNIFFER1 A14

#define SS 10  //W5500 CS
#define RST 7  //W5500 RST

#define ESTOP_BREAK 40
#define LED_PWR 22
#define TRACO_24VDC 23
#define IO_ADDR 0x23
#define RE_DE1 12
#define RE_DE3 31