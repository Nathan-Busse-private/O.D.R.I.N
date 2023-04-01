

/* Amp test
  Project: O.D.R.I.N v2.0
  Start date: 13 July 2022
  Info:

  The imdividual leg test script will make O.D.R.I.N perform a set of six inches for each leg.
  One leg will raize for each set.
  while tethered to a power supply which will display the total current O.D.R.I.N
  requires for one leg to funcion properly.

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
#define coxa_A 14
#define femur_A 13
#define tibia_A 12

/*
  -------
  Leg B
  -------
*/
#define coxa_B 6
#define femur_B 5
#define tibia_B 4

/*
  -------
  Leg C
  -------
*/
#define coxa_C 2
#define femur_C 1
#define tibia_C 0


//Right (Board 2)
/*
  -------
  Leg D
  -------
*/
#define coxa_D 14
#define femur_D 13
#define tibia_D 12

/*
  -------
  Leg E
  -------
*/
#define coxa_E 6
#define femur_E 5
#define tibia_E 4

/*
  -------
  Leg F
  -------
*/
#define coxa_F 2
#define femur_F 1
#define tibia_F 0

// Declaring position values for servo joints.

#define coxa_left 110  // Degree for left direction for Coxa
#define coxa_right 60  // Degree for right direction for Coxa

#define femur_down 90  // Degree for Lower Femur
#define femur_up 160   // Degree for Upper Femur

#define tibia_down 90  // Degree for Lower Tibia
#define tibia_up 150   // Degree for Upper Tibia

//Min and Max pulse values

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

int degrees;

// Millis declarations
#define hold 100
#define pause 5000

// Address definitions for servo controllers
Adafruit_PWMServoDriver left = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver right = Adafruit_PWMServoDriver(0x41);


void setup() {
  // put your setup code here, to run once:

  left.begin();
  left.setPWMFreq(FREQUENCY);  // Analog servos run at ~60 Hz updates

  right.begin();
  right.setPWMFreq(FREQUENCY);  // Analog servos run at ~60 Hz updates
}

void loop() {
  //--------------------------------------------------------------------
  // RISE ( right board )
  //--------------------------------------------------------------------

  right.setPWM(coxa_A, 0, pulseWidth(coxa_left));  // A

  delay(hold);

  right.setPWM(femur_A, 0, pulseWidth(femur_up));  // A

  delay(hold);

  right.setPWM(tibia_A, 0, pulseWidth(tibia_up));  // A

  delay(hold);


  right.setPWM(coxa_B, 0, pulseWidth(coxa_left));  // A

  delay(hold);

  right.setPWM(femur_B, 0, pulseWidth(femur_up));  // A

  delay(hold);

  right.setPWM(tibia_B, 0, pulseWidth(tibia_up));  // A

  delay(hold);


  right.setPWM(coxa_C, 0, pulseWidth(coxa_left));  // A

  delay(hold);

  right.setPWM(femur_C, 0, pulseWidth(femur_up));  // A

  delay(hold);

  right.setPWM(tibia_C, 0, pulseWidth(tibia_up));  // A

  delay(hold);




  //--------------------------------------------------------------------
  // LOWER  ( right board )
  //--------------------------------------------------------------------

  right.setPWM(coxa_A, 0, pulseWidth(coxa_right));  // A

  delay(hold);

  right.setPWM(femur_A, 0, pulseWidth(femur_down));  // A

  delay(hold);

  right.setPWM(tibia_A, 0, pulseWidth(tibia_down));  // A

  delay(hold);


  right.setPWM(coxa_B, 0, pulseWidth(coxa_right));  // A

  delay(hold);

  right.setPWM(femur_B, 0, pulseWidth(femur_down));  // A

  delay(hold);

  right.setPWM(tibia_B, 0, pulseWidth(tibia_down));  // A

  delay(hold);


  right.setPWM(coxa_C, 0, pulseWidth(coxa_right));  // A

  delay(hold);

  right.setPWM(femur_C, 0, pulseWidth(femur_down));  // A

  delay(hold);

  right.setPWM(tibia_C, 0, pulseWidth(tibia_down));  // A

  delay(hold);


  //--------------------------------------------------------------------
  // RISE ( left board )
  //--------------------------------------------------------------------

  left.setPWM(coxa_D, 0, pulseWidth(coxa_left));  // A

  delay(hold);

  left.setPWM(femur_D, 0, pulseWidth(femur_up));  // A

  delay(hold);

  left.setPWM(tibia_D, 0, pulseWidth(tibia_up));  // A

  delay(hold);


  left.setPWM(coxa_E, 0, pulseWidth(coxa_left));  // A

  delay(hold);

  left.setPWM(femur_E, 0, pulseWidth(femur_up));  // A

  delay(hold);

  left.setPWM(tibia_E, 0, pulseWidth(tibia_up));  // A

  delay(hold);


  left.setPWM(coxa_F, 0, pulseWidth(coxa_left));  // A

  delay(hold);

  left.setPWM(femur_F, 0, pulseWidth(femur_up));  // A

  delay(hold);

  left.setPWM(tibia_F, 0, pulseWidth(tibia_up));  // A

  delay(hold);




  //--------------------------------------------------------------------
  // LOWER  ( left board )
  //--------------------------------------------------------------------

  left.setPWM(coxa_D, 0, pulseWidth(coxa_right));  // A

  delay(hold);

  left.setPWM(femur_D, 0, pulseWidth(femur_down));  // A

  delay(hold);

  left.setPWM(tibia_D, 0, pulseWidth(tibia_down));  // A

  delay(hold);


  left.setPWM(coxa_E, 0, pulseWidth(coxa_right));  // A

  delay(hold);

  left.setPWM(femur_E, 0, pulseWidth(femur_down));  // A

  delay(hold);

  left.setPWM(tibia_E, 0, pulseWidth(tibia_down));  // A

  delay(hold);


  left.setPWM(coxa_F, 0, pulseWidth(coxa_right));  // A

  delay(hold);

  left.setPWM(femur_F, 0, pulseWidth(femur_down));  // A

  delay(hold);

  left.setPWM(tibia_F, 0, pulseWidth(tibia_down));  // A

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
