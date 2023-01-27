

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver left = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver right = Adafruit_PWMServoDriver(0x41);

// Milli setup



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
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50
// Robot initialization

#define config 90  // Set all joints excluding Tibia to 90 degrees.

// Walking positions for walking

#define CCW 60  // Min degree for Coxa
#define CW 115  // Max degree for Coxa

#define DOWN 92  // Min degree for Femur
#define UP 100   // Max degree for Femur

#define TIBIA 45  // Degree for Tibia

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
// Tibia
/*
left.setPWM(tibia_A, 0, pulseWidth(TIBIA));
  Serial.println("0");
  delay(500);

  left.setPWM(tibia_B, 0, pulseWidth(TIBIA));
  Serial.println("45");
  delay(500);

  left.setPWM(tibia_C, 0, pulseWidth(TIBIA));
  Serial.println("90");
  delay(500);

 

  right.setPWM(tibia_D, 0, pulseWidth(TIBIA));
  Serial.println("90");
  delay(500);

  right.setPWM(tibia_E, 0, pulseWidth(TIBIA));
  Serial.println("45");
  delay(500);

  right.setPWM(tibia_F, 0, pulseWidth(TIBIA));
  Serial.println("45");
  delay(500);
*/
 // COXA 


  left.setPWM(coxa_A, 0, pulseWidth(CW));
  Serial.println("0");
  delay(500);

  left.setPWM(coxa_A, 0, pulseWidth(CW));
  Serial.println("45");
  delay(500);

  left.setPWM(coxa_B, 0, pulseWidth(CCW));
  Serial.println("90");
  delay(500);

  left.setPWM(coxa_B, 0, pulseWidth(CW));
  Serial.println("135");
  delay(500);

  left.setPWM(coxa_C, 0, pulseWidth(CW));
  Serial.println("180");
  delay(500);

  left.setPWM(coxa_C, 0, pulseWidth(CCW));
  Serial.println("135");
  delay(500);

   right.setPWM(coxa_D, 0, pulseWidth(CW));
  Serial.println("0");
  delay(500);

  right.setPWM(coxa_D, 0, pulseWidth(CW));
  Serial.println("45");
  delay(500);

  right.setPWM(coxa_E, 0, pulseWidth(CCW));
  Serial.println("90");
  delay(500);

  right.setPWM(coxa_E, 0, pulseWidth(CW));
  Serial.println("135");
  delay(500);

  right.setPWM(coxa_F, 0, pulseWidth(CW));
  Serial.println("180");
  delay(500);

  right.setPWM(coxa_F, 0, pulseWidth(CCW));
  Serial.println("135");
  delay(500);

  // femur
/*
  right.setPWM(femur_A, 0, pulseWidth(DOWN));
  Serial.println("90");
  delay(500);

  right.setPWM(femur_C, 0, pulseWidth(DOWN));
  Serial.println("45");
  delay(500);

  right.setPWM(femur_E, 0, pulseWidth(DOWN));
  Serial.println("45");
  delay(500);

  right.setPWM(femur_D, 0, pulseWidth(UP));
  Serial.println("45");
  delay(500);

  right.setPWM(femur_F, 0, pulseWidth(UP));
  Serial.println("45");
  delay(500);

  right.setPWM(femur_B, 0, pulseWidth(UP));
  Serial.println("45");
  delay(500);
  */
}

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println(analog_value);
  return analog_value;
}