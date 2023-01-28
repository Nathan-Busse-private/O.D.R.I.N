

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Millis

long OdrinServo_movetime = 0;

long OdrinServo_wait_time = 0;

int tDelay = 500;  // Delay between moves of smooth motion

int wDelay = 5;  // Delay wait time between pulses


Adafruit_PWMServoDriver left = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver right = Adafruit_PWMServoDriver(0x41);

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

//Min and Max pulse values

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50
// Robot initialization

#define config 90  // Set all joints excluding Tibia to 90 degrees.

// Walking positions for walking

#define CCW 60  // Min degree for Coxa
#define CW 115  // Max degree for Coxa

#define DOWN 92  // Min degree for Femur
#define UP 100   // Max degree for Femur

#define tibia 45  // Degree for Tibia

int degrees;

void setup() {

  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  left.begin();
  left.setPWMFreq(FREQUENCY);  // Analog servos run at ~60 Hz updates

  right.begin();
  right.setPWMFreq(FREQUENCY);  // Analog servos run at ~60 Hz updates
}


void loop() {

  // COXA
  //if (wait) { // block until the servo is at its new position
  if (pulseWidth < MIN_PULSE_WIDTH) {
    left.setPWM(coxa_A, 0, pulseWidth(CW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    left.setPWM(coxa_C, 0, pulseWidth(CW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  if (pulseWidth < MIN_PULSE_WIDTH) {
    right.setPWM(coxa_E, 0, pulseWidth(CCW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    right.setPWM(coxa_D, 0, pulseWidth(CW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  if (pulseWidth < MIN_PULSE_WIDTH) {
    right.setPWM(coxa_F, 0, pulseWidth(CW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    left.setPWM(coxa_B, 0, pulseWidth(CCW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  // opposite

  //if (wait) { // block until the servo is at its new position
  if (pulseWidth < MIN_PULSE_WIDTH) {
    left.setPWM(coxa_A, 0, pulseWidth(CCW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    left.setPWM(coxa_C, 0, pulseWidth(CCW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  if (pulseWidth < MIN_PULSE_WIDTH) {
    right.setPWM(coxa_E, 0, pulseWidth(CW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    right.setPWM(coxa_D, 0, pulseWidth(CCW));
    OdrinServo_wait_time = millis() + tDelay;
  }


  if (pulseWidth < MIN_PULSE_WIDTH) {
    right.setPWM(coxa_F, 0, pulseWidth(CCW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    left.setPWM(coxa_B, 0, pulseWidth(CW));
    OdrinServo_wait_time = millis() + tDelay;
  }

  // tibia
  //if (wait) { // block until the servo is at its new position
  if (pulseWidth < MIN_PULSE_WIDTH) {
    left.setPWM(tibia_A, 0, pulseWidth(tibia));

    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    left.setPWM(tibia_C, 0, pulseWidth(tibia));
    OdrinServo_wait_time = millis() + tDelay;
  }


  if (pulseWidth < MIN_PULSE_WIDTH) {
    right.setPWM(tibia_E, 0, pulseWidth(tibia));
    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    right.setPWM(tibia_D, 0, pulseWidth(tibia));
    OdrinServo_wait_time = millis() + tDelay;
  }

  if (pulseWidth < MIN_PULSE_WIDTH) {
    right.setPWM(tibia_F, 0, pulseWidth(tibia));
    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    left.setPWM(tibia_B, 0, pulseWidth(tibia));
    OdrinServo_wait_time = millis() + tDelay;
  }

  // femur
  //if (wait) { // block until the servo is at its new position
  if (pulseWidth < MIN_PULSE_WIDTH) {
    left.setPWM(femur_A, 0, pulseWidth(DOWN));
    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    left.setPWM(femur_C, 0, pulseWidth(DOWN));
    OdrinServo_wait_time = millis() + tDelay;
  }

  if (pulseWidth < MIN_PULSE_WIDTH) {
    right.setPWM(femur_E, 0, pulseWidth(DOWN));
    OdrinServo_wait_time = millis() + tDelay;
  }

  // oppoaite

  else {
    right.setPWM(femur_D, 0, pulseWidth(UP));
    OdrinServo_wait_time = millis() + tDelay;
  }

  if (pulseWidth < MIN_PULSE_WIDTH) {
    right.setPWM(femur_F, 0, pulseWidth(UP));
    OdrinServo_wait_time = millis() + tDelay;
  }

  else {
    left.setPWM(femur_B, 0, pulseWidth(UP));
    OdrinServo_wait_time = millis() + tDelay;
  }
}

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println(analog_value);
  return analog_value;
}
