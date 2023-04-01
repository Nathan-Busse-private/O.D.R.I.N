

/* Amp test
Project: O.D.R.I.N v2.0
Start date: 13 July 2022
Info:

The Amp test script will make O.D.R.I.N perform a set of bench presses
while tethered to a power supply which will display the total current O.D.R.I.N
requires to funcion properly.

Made by Nathan-Busse.
*/

// The code

// Calling Libraries

#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

// Declaring pins

// Channel definitions


//Left (Board 1)
/*
-------
Leg A
-------
*/
#define coxa_A 12
#define femur_A 13
#define tibia_A 14

/*
-------
Leg B
-------
*/
#define coxa_B 4
#define femur_B 5
#define tibia_B 6

/*
-------
Leg C
-------
*/
#define coxa_C 0
#define femur_C 1
#define tibia_C 2


//Right (Board 2)
/*
-------
Leg D
-------
*/
#define coxa_D 12
#define femur_D 13
#define tibia_D 14

/*
-------
Leg E
-------
*/
#define coxa_E 4
#define femur_E 5
#define tibia_E 6

/*
-------
Leg F
-------
*/
#define coxa_F 0
#define femur_F 1
#define tibia_F 2

// Declaring position values

#define config 90  // Set all joints excluding Tibia to 90 degrees.
//#define tibia 45   // Degree for Tibia
#define down 60      // Min degree for Femur
#define up 160       // Max degree for Femur
#define tib_down 10  // Min degree for Tibia
#define tib_up 90   // Max degree for Tibia


//Min and Max pulse values

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

int degrees;

// Millis declarations
#define hold 10
#define pause 5000
/*
unsigned long begin;  //some global variables available anywhere in the program
unsigned long current;
const unsigned long wait = 1000;  //the value is a number of milliseconds
*/
// Address definitions for servo controllers

Adafruit_PWMServoDriver left = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver right = Adafruit_PWMServoDriver(0x41);


void setup() {
  // put your setup code here, to run once:

  left.begin();
  left.setPWMFreq(FREQUENCY);  // Analog servos run at ~60 Hz updates

  right.begin();
  right.setPWMFreq(FREQUENCY);  // Analog servos run at ~60 Hz updates

  // begin = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  //current = millis();  // Get current time in milliseconds
  //--------------------------------------------------------------------
  // RISE
  //--------------------------------------------------------------------

   left.setPWM(coxa_A, 0, pulseWidth(config));  // A

  delay(hold);


  left.setPWM(tibia_A, 0, pulseWidth(tib_up));  // A
  delay(hold);
  // begin = current;


  left.setPWM(femur_A, 0, pulseWidth(down));  // A
  //begin = current;
  delay(hold);

  // LEg 2

  //if (current - begin >= wait) {
  left.setPWM(coxa_B, 0, pulseWidth(config));  // B
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  left.setPWM(tibia_B, 0, pulseWidth(tib_up));  // B
  delay(hold);
  // begin = current;

  //if (current - begin >= wait) {
  left.setPWM(femur_B, 0, pulseWidth(down));  // B
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  left.setPWM(coxa_C, 0, pulseWidth(config));  // C
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  left.setPWM(tibia_C, 0, pulseWidth(tib_up));  // C
  delay(hold);
  // begin = current;

  //if (current - begin >= wait) {
  left.setPWM(femur_C, 0, pulseWidth(down));  // C
  //begin = current;
  delay(hold);


  right.setPWM(coxa_D, 0, pulseWidth(config));  // D

  delay(hold);


  right.setPWM(tibia_D, 0, pulseWidth(tib_up));  // D
  delay(hold);
  // begin = current;


  right.setPWM(femur_D, 0, pulseWidth(down));  // D
  //begin = current;
  delay(hold);

  // LEg 2

  //if (current - begin >= wait) {
  right.setPWM(coxa_E, 0, pulseWidth(config));  // E
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  right.setPWM(tibia_E, 0, pulseWidth(tib_up));  // E
  delay(hold);
  // begin = current;

  //if (current - begin >= wait) {
  right.setPWM(femur_E, 0, pulseWidth(down));  // E
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  right.setPWM(coxa_F, 0, pulseWidth(config));  // F
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  right.setPWM(tibia_F, 0, pulseWidth(tib_up));  // F
  delay(hold);
  // begin = current;

  //if (current - begin >= wait) {
  right.setPWM(femur_F, 0, pulseWidth(down));  // F
  //begin = current;
  


delay(pause);


//--------------------------------------------------------------------
  // LOWER
  //--------------------------------------------------------------------



  left.setPWM(coxa_A, 0, pulseWidth(config));  // A

  delay(hold);


  left.setPWM(tibia_A, 0, pulseWidth(tib_down));  // A
  delay(hold);
  // begin = current;


  left.setPWM(femur_A, 0, pulseWidth(up));  // A
  //begin = current;
  delay(hold);

  // LEg 2

  //if (current - begin >= wait) {
  left.setPWM(coxa_B, 0, pulseWidth(config));  // B
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  left.setPWM(tibia_B, 0, pulseWidth(tib_down));  // B
  delay(hold);
  // begin = current;

  //if (current - begin >= wait) {
  left.setPWM(femur_B, 0, pulseWidth(up));  // B
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  left.setPWM(coxa_C, 0, pulseWidth(config));  // C
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  left.setPWM(tibia_C, 0, pulseWidth(tib_down));  // C
  delay(hold);
  // begin = current;

  //if (current - begin >= wait) {
  left.setPWM(femur_C, 0, pulseWidth(up));  // C
  //begin = current;
  delay(hold);

  right.setPWM(coxa_D, 0, pulseWidth(config));  // D

  delay(hold);


  right.setPWM(tibia_D, 0, pulseWidth(tib_down));  // D
  delay(hold);
  // begin = current;


  right.setPWM(femur_D, 0, pulseWidth(up));  // D
  //begin = current;
  delay(hold);

  // LEg 2

  //if (current - begin >= wait) {
  right.setPWM(coxa_E, 0, pulseWidth(config));  // E
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  right.setPWM(tibia_E, 0, pulseWidth(tib_down));  // E
  delay(hold);
  // begin = current;

  //if (current - begin >= wait) {
  right.setPWM(femur_E, 0, pulseWidth(up));  // E
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  right.setPWM(coxa_F, 0, pulseWidth(config));  // F
  //begin = current;
  delay(hold);

  //if (current - begin >= wait) {
  right.setPWM(tibia_F, 0, pulseWidth(tib_down));  // F
  delay(hold);
  // begin = current;

  //if (current - begin >= wait) {
  right.setPWM(femur_F, 0, pulseWidth(up));  // F
  //begin = current;
  delay(hold);


}

// Pulsewidth declaration

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println(analog_value);
  return analog_value;
}
