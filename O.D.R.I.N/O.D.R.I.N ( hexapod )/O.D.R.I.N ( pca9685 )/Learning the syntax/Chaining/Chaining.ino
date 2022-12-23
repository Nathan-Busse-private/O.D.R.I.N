/* pca9685 pins that will be used and their pinout to the Arduino.

   GND ------> GND

   VCC ------> 5v ( Logic Power!!! )

   SCL ------> A5

   SDA ------> A4

   OE -------> OE ( Between chained boards!!! )

   V+ -------> V+ ( External Power Distobution between chained boards!!! )

*/

// Libraries

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

/* Binary Address so that the Arduino can identify that the,
 * 2 chained pca9685 boards are individual to avoid conflict. 
*/

Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

// Declaring Servos
uint8_t servonum1 = 0;
uint8_t servonum2 = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("16 channel PWM test!");

// pca9685 board 1

  pwm1.begin();
  pwm1.setPWMFreq(1600); // This is the maximum PWM frequency.
  

  pwm1.writeMicroseconds(servonum1, 130);

// pca9685 board 2

  pwm2.begin();
  pwm2.setPWMFreq(1600); // This is the maximum PWM frequency.

  pwm2.writeMicroseconds(servonum2, 130);

  

}

void loop() {
  // put your main code here, to run repeatedly:

}
