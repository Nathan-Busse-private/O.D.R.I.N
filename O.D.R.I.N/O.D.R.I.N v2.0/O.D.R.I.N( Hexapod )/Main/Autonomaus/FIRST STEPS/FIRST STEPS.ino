

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver left = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver right = Adafruit_PWMServoDriver(0x41);

// Channel definitions


//Left (Board 1)
/*
-------
Leg A
-------
*/
#define coxa_A 0
#define femur_A 1
#define tibia_A 2

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
#define coxa_C 8
#define femur_C 9
#define tibia_C 10


//Right (Board 2)
/*
-------
Leg D
-------
*/
#define coxa_D 0
#define femur_D 1
#define tibia_D 2

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
#define coxa_F 8
#define femur_F 9
#define tibia_F 10

//Min and Max pulse values

#define SERVOMIN 500   // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 2500  // this is the 'maximum' pulse length count (out of 4096)

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

  left.begin();
  left.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  right.begin();
  right.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}



void setServoPulse(uint8_t n, double pulse) {
  double pulselength;

  pulselength = 1000000;
  pulselength /= 60;
  pulselength /= 4096;
  pulse *= 1000;
  pulse /= pulselength;

  // Board 1

  left.setPWM(n, 0, pulse);
  degrees = map(pulselength, SERVOMIN, SERVOMAX, 0, 90);

  // Boserfs

  right.setPWM(n, 0, pulse);
  degrees = map(pulselength, SERVOMIN, SERVOMAX, 0, 90);
}

void loop() {

  // Board 1

  // (Tibia)


  left.setPWM(tibia_A, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // A
  delay(1500);
  left.setPWM(tibia_B, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // B
  delay(1500);
  left.setPWM(tibia_C, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // C
  delay(1500);

  // Board 2

  right.setPWM(tibia_D, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // D
  delay(1500);
  right.setPWM(tibia_E, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // E
  delay(1500);
  right.setPWM(tibia_F, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // F

  // Cycle 1

  // Board 1

  // (Coxa)

  left.setPWM(coxa_A, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // A
  delay(1500);
  left.setPWM(coxa_C, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // C
  delay(1500);
  left.setPWM(coxa_E, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // E
  delay(1500);

  // Board 2

  right.setPWM(coxa_D, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // D
  delay(1500);
  right.setPWM(coxa_F, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // F
  delay(1500);
  right.setPWM(coxa_B, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // B

  // Board 1

  // (Femur)

  left.setPWM(femur_A, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // A
  delay(1500);
  left.setPWM(femur_C, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // C
  delay(1500);
  left.setPWM(femur_E, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // E
  delay(1500);

  // Board 2

  right.setPWM(femur_D, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // D
  delay(1500);
  right.setPWM(femur_F, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // F
  delay(1500);
  right.setPWM(femur_B, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // B

  // Cycle 2

  // Board 1

  // (Coxa)

  left.setPWM(coxa_A, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // A
  delay(1500);
  left.setPWM(coxa_C, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // C
  delay(1500);
  left.setPWM(coxa_E, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // E
  delay(1500);

  // Board 2

  right.setPWM(coxa_D, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // D
  delay(1500);
  right.setPWM(coxa_F, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // F
  delay(1500);
  right.setPWM(coxa_B, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // B

  // Board 1

  // (Femur)

  left.setPWM(femur_A, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // A
  delay(1500);
  left.setPWM(femur_C, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // C
  delay(1500);
  left.setPWM(femur_E, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // E
  delay(1500);

  // Board 2

  right.setPWM(femur_D, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // D
  delay(1500);
  right.setPWM(femur_F, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // F
  delay(1500);
  right.setPWM(femur_B, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // B

  // Cycle 3

  // Board 1

  // (Coxa)

  left.setPWM(coxa_A, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // A
  delay(1500);
  left.setPWM(coxa_C, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // C
  delay(1500);
  left.setPWM(coxa_E, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // E
  delay(1500);

  // Board 2

  right.setPWM(coxa_D, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // D
  delay(1500);
  right.setPWM(coxa_F, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // F
  delay(1500);
  right.setPWM(coxa_B, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // B

  // Board 1

  // (Femur)

  left.setPWM(femur_A, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // A
  delay(1500);
  left.setPWM(femur_C, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // C
  delay(1500);
  left.setPWM(femur_E, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // E
  delay(1500);

  // Board 2

  right.setPWM(femur_D, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // D
  delay(1500);
  right.setPWM(femur_F, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // F
  delay(1500);
  right.setPWM(femur_B, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // B

  // Cycle 4

  // Board 1

  // (Coxa)

  left.setPWM(coxa_A, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // A
  delay(1500);
  left.setPWM(coxa_C, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // C
  delay(1500);
  left.setPWM(coxa_E, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // E
  delay(1500);

  // Board 2

  right.setPWM(coxa_D, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // D
  delay(1500);
  right.setPWM(coxa_F, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // F
  delay(1500);
  right.setPWM(coxa_B, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // B

  // Board 1

  // (Femur)

  left.setPWM(femur_A, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // A
  delay(1500);
  left.setPWM(femur_C, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // C
  delay(1500);
  left.setPWM(femur_E, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // E
  delay(1500);

  // Board 2

  right.setPWM(femur_D, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // D
  delay(1500);
  right.setPWM(femur_F, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // F
  delay(1500);
  right.setPWM(femur_B, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // B


  delay(500);
}
