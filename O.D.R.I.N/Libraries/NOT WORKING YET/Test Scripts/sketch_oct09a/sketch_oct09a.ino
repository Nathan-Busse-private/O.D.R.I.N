#include <Arduino.h>

#include "ServoEasing.hpp"
#include "PinDefinitionsAndMore.h"
/*
 * Pin mapping table for different platforms - used by all examples
 *
 * Platform         Servo1      Servo2      Servo3      Analog     Core/Pin schema
 * -------------------------------------------------------------------------------
 * (Mega)AVR + SAMD    9          10          11          A0
 * ATtiny3217         20|PA3       0|PA4       1|PA5       2|PA6   MegaTinyCore
 * ESP8266            14|D5       12|D6       13|D7        0
 * ESP32               5          18          19          A0
 * BluePill          PB7         PB8         PB9         PA0
 * APOLLO3            11          12          13          A3
 * RP2040             6|GPIO18     7|GPIO19    8|GPIO20
 */

#define TIBIA 45

 
#define COXA_CCW 115
#define COXA_CW 60

#define AC_UP 100
#define AC_DOWN 92

int UP = AC_UP;
int DOWN = AC_DOWN;

ServoEasing Servo1;
ServoEasing Servo2;
ServoEasing Servo3;

ServoEasing Servo4;
ServoEasing Servo5;
ServoEasing Servo6;

ServoEasing Servo7;
ServoEasing Servo8;
ServoEasing Servo9;

ServoEasing Servo10;
ServoEasing Servo11;
ServoEasing Servo12;

void setup() {
  
    Servo1.attach(SERVO1_PIN, 45);

    delay(500); // Wait for servo to reach start position.

    Servo2.attach(SERVO2_PIN, 45);

    delay(500); // Wait for servo to reach start position.

    Servo3.attach(SERVO3_PIN, 45);

    delay(500); // Wait for servo to reach start position.

    Servo4.attach(SERVO4_PIN, 45);

    delay(500); // Wait for servo to reach start position.

    Servo5.attach(SERVO5_PIN, 45);

    delay(500); // Wait for servo to reach start position.

    Servo6.attach(SERVO6_PIN, 45);

    delay(500); // Wait for servo to reach start position.

    Servo7.attach(SERVO7_PIN, 45);

    delay(500); // Wait for servo to reach start position.

    Servo8.attach(SERVO8_PIN, 45);

    delay(500); // Wait for servo to reach start position.

    Servo9.attach(SERVO9_PIN, 45);

    delay(500); // Wait for servo to reach start position.

    Servo10.attach(SERVO10_PIN, 45);

     delay(500); // Wait for servo to reach start position.

    Servo11.attach(SERVO11_PIN, 45);

     delay(500); // Wait for servo to reach start position.

    Servo12.attach(SERVO12_PIN, 45);

    

    delay(500); // Wait for servo to reach start position.
}

void loop() {
    Servo1.easeTo(COXA_CCW, 40); // Blocking call

    Servo1.easeTo(COXA_CW, 40); // Blocking call
    delay(1000);

    Servo2.easeTo(DOWN, 40); // Blocking call

    Servo2.easeTo(UP, 40); // Blocking call
    delay(1000);

    Servo3.easeTo(TIBIA, 40); // Blocking call

    Servo3.easeTo(TIBIA, 40); // Blocking call
    delay(1000);

    Servo4.easeTo(COXA_CCW, 40); // Blocking call

    Servo4.easeTo(COXA_CW, 40); // Blocking call
    delay(1000);

    Servo5.easeTo(DOWN, 40); // Blocking call

    Servo5.easeTo(UP, 40); // Blocking call
    delay(1000);

    Servo6.easeTo(TIBIA, 40); // Blocking call

    Servo6.easeTo(TIBIA, 40); // Blocking call
    delay(1000);

    Servo7.easeTo(COXA_CCW, 40); // Blocking call

    Servo7.easeTo(COXA_CW, 40); // Blocking call
    delay(1000);

    Servo8.easeTo(DOWN, 40); // Blocking call

    Servo8.easeTo(UP, 40); // Blocking call
    delay(1000);

    Servo9.easeTo(TIBIA, 40); // Blocking call

    Servo9.easeTo(TIBIA, 40); // Blocking call
    delay(1000);

    Servo10.easeTo(COXA_CCW, 40); // Blocking call

    Servo10.easeTo(COXA_CW, 40); // Blocking call
    delay(1000);

    Servo11.easeTo(DOWN, 40); // Blocking call

    Servo11.easeTo(UP, 40); // Blocking call
    delay(1000);

    Servo12.easeTo(TIBIA, 40); // Blocking call

    Servo12.easeTo(TIBIA, 40); // Blocking call
    delay(1000);
}
