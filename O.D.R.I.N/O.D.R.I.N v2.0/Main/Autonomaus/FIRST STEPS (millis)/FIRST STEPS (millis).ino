

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver left = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver right = Adafruit_PWMServoDriver(0x41);

// Milli setup

unsigned long begin;  //some global variables available anywhere in the program
unsigned long current;
const unsigned long wait = 100;  //the value is a number of milliseconds

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

  begin = millis();
}

void loop() {

  current = millis();  // Get current time in milliseconds

  //-----------------------------------------------------------------------------------------------------------------------

  // Servo config

  //-----------------------------------------------------------------------------------------------------------------------
  if (current - begin >= wait) {                                         // Test whether the wait has elapsed
    left.setPWM(coxa_A, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // A
    begin = current;                                                     // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                         // Test whether the wait has elapsed
    left.setPWM(coxa_C, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // C
    begin = current;                                                     // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                         // Test whether the wait has elapsed
    left.setPWM(coxa_E, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // E
    begin = current;                                                     // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                          // Test whether the wait has elapsed
    right.setPWM(coxa_D, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // D
    begin = current;                                                      // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                          // Test whether the wait has elapsed
    right.setPWM(coxa_F, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // F
    begin = current;                                                      // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                          // Test whether the wait has elapsed
    right.setPWM(coxa_B, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // B
    begin = current;                                                      // Save the start time of the current servo state.
  }

  // Board 1

  // (Femur)
  if (current - begin >= wait) {                                          // Test whether the wait has elapsed
    left.setPWM(femur_A, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // A
    begin = current;                                                      // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                          // Test whether the wait has elapsed
    left.setPWM(femur_C, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // C
    begin = current;                                                      // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                          // Test whether the wait has elapsed
    left.setPWM(femur_E, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // E
    begin = current;                                                      // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                           // Test whether the wait has elapsed
    right.setPWM(femur_D, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // D
    begin = current;                                                       // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                           // Test whether the wait has elapsed
    right.setPWM(femur_F, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // F
    begin = current;                                                       // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                           // Test whether the wait has elapsed
    right.setPWM(femur_B, 0, map(config, 0, config, SERVOMIN, SERVOMAX));  // B
    begin = current;                                                       // Save the start time of the current servo state.
  }

  //-----------------------------------------------------------------------------------------------------------------------

  // Tibia config

  //-----------------------------------------------------------------------------------------------------------------------
  // Board 1
  if (current - begin >= wait) {                                        // Test whether the wait has elapsed
    left.setPWM(tibia_A, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // A
    begin = current;                                                    // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                        // Test whether the wait has elapsed
    left.setPWM(tibia_B, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // B
    begin = current;                                                    // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                        // Test whether the wait has elapsed
    left.setPWM(tibia_C, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // C
    begin = current;                                                    // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                         // Test whether the wait has elapsed
    right.setPWM(tibia_D, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // D
    begin = current;                                                     // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                         // Test whether the wait has elapsed
    right.setPWM(tibia_E, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // E
    begin = current;                                                     // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                         // Test whether the wait has elapsed
    right.setPWM(tibia_F, 0, map(TIBIA, 0, TIBIA, SERVOMIN, SERVOMAX));  // F
    begin = current;                                                     // Save the start time of the current servo state.
  }

  //-----------------------------------------------------------------------------------------------------------------------
  // Servo positions
  //-----------------------------------------------------------------------------------------------------------------------

  // Cycle 1

  //-----------------------------------------------------------------------------------------------------------------------
  // Board 1

  // (Coxa)

  if (current - begin >= wait) {                                 // Test whether the wait has elapsed
    left.setPWM(coxa_A, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // A
    begin = current;                                             // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                 // Test whether the wait has elapsed
    left.setPWM(coxa_C, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // C
    begin = current;                                             // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    left.setPWM(coxa_E, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // E
    begin = current;                                               // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    right.setPWM(coxa_D, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // D
    begin = current;                                              // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    right.setPWM(coxa_F, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // F
    begin = current;                                              // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                    // Test whether the wait has elapsed
    right.setPWM(coxa_B, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // B
    begin = current;                                                // Save the start time of the current servo state.
  }
  // Board 1

  // (Femur)
  if (current - begin >= wait) {                                      // Test whether the wait has elapsed
    left.setPWM(femur_A, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // A
    begin = current;                                                  // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                      // Test whether the wait has elapsed
    left.setPWM(femur_C, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // C
    begin = current;                                                  // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                      // Test whether the wait has elapsed
    left.setPWM(femur_E, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // E
    begin = current;                                                  // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    right.setPWM(femur_D, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // D
    begin = current;                                               // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    right.setPWM(femur_F, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // F
    begin = current;                                               // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    right.setPWM(femur_B, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // B
    begin = current;                                               // Save the start time of the current servo state.
  }
  //-----------------------------------------------------------------------------------------------------------------------

  // Cycle 2

  //-----------------------------------------------------------------------------------------------------------------------
  // Board 1

  // (Coxa)

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    left.setPWM(coxa_A, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // A
    begin = current;                                               // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    left.setPWM(coxa_C, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // C
    begin = current;                                               // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                 // Test whether the wait has elapsed
    left.setPWM(coxa_E, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // E
    begin = current;                                             // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                    // Test whether the wait has elapsed
    right.setPWM(coxa_D, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // D
    begin = current;                                                // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                    // Test whether the wait has elapsed
    right.setPWM(coxa_F, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // F
    begin = current;                                                // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    right.setPWM(coxa_B, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // B
    begin = current;                                              // Save the start time of the current servo state.
  }
  // Board 1

  // (Femur)

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    left.setPWM(femur_A, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // A
    begin = current;                                              // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    left.setPWM(femur_C, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // C
    begin = current;                                              // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    left.setPWM(femur_E, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // E
    begin = current;                                              // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                       // Test whether the wait has elapsed
    right.setPWM(femur_D, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // D
    begin = current;                                                   // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                       // Test whether the wait has elapsed
    right.setPWM(femur_F, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // F
    begin = current;                                                   // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                       // Test whether the wait has elapsed
    right.setPWM(femur_B, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // B
    begin = current;                                                   // Save the start time of the current servo state.
  }
  //-----------------------------------------------------------------------------------------------------------------------

  // Cycle 3

  //-----------------------------------------------------------------------------------------------------------------------
  // Board 1

  // (Coxa)

  if (current - begin >= wait) {                                 // Test whether the wait has elapsed
    left.setPWM(coxa_A, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // A
    begin = current;                                             // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                 // Test whether the wait has elapsed
    left.setPWM(coxa_C, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // C
    begin = current;                                             // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    left.setPWM(coxa_E, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // E
    begin = current;                                               // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    right.setPWM(coxa_D, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // D
    begin = current;                                              // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    right.setPWM(coxa_F, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // F
    begin = current;                                              // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                    // Test whether the wait has elapsed
    right.setPWM(coxa_B, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // B
    begin = current;                                                // Save the start time of the current servo state.
  }
  // Board 1

  // (Femur)
  if (current - begin >= wait) {                                      // Test whether the wait has elapsed
    left.setPWM(femur_A, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // A
    begin = current;                                                  // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                      // Test whether the wait has elapsed
    left.setPWM(femur_C, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // C
    begin = current;                                                  // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                      // Test whether the wait has elapsed
    left.setPWM(femur_E, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // E
    begin = current;                                                  // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    right.setPWM(femur_D, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // D
    begin = current;                                               // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    right.setPWM(femur_F, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // F
    begin = current;                                               // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    right.setPWM(femur_B, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // B
    begin = current;                                               // Save the start time of the current servo state.
  }
  //-----------------------------------------------------------------------------------------------------------------------

  // Cycle 4

  //-----------------------------------------------------------------------------------------------------------------------
  // Board 1

  // (Coxa)

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    left.setPWM(coxa_A, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // A
    begin = current;                                               // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                   // Test whether the wait has elapsed
    left.setPWM(coxa_C, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // C
    begin = current;                                               // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                 // Test whether the wait has elapsed
    left.setPWM(coxa_E, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // E
    begin = current;                                             // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                    // Test whether the wait has elapsed
    right.setPWM(coxa_D, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // D
    begin = current;                                                // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                    // Test whether the wait has elapsed
    right.setPWM(coxa_F, 0, map(CCW, 0, CCW, SERVOMIN, SERVOMAX));  // F
    begin = current;                                                // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    right.setPWM(coxa_B, 0, map(CW, 0, CW, SERVOMIN, SERVOMAX));  // B
    begin = current;                                              // Save the start time of the current servo state.
  }
  // Board 1

  // (Femur)

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    left.setPWM(femur_A, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // A
    begin = current;                                              // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    left.setPWM(femur_C, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // C
    begin = current;                                              // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                  // Test whether the wait has elapsed
    left.setPWM(femur_E, 0, map(UP, 0, UP, SERVOMIN, SERVOMAX));  // E
    begin = current;                                              // Save the start time of the current servo state.
  }

  // Board 2

  if (current - begin >= wait) {                                       // Test whether the wait has elapsed
    right.setPWM(femur_D, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // D
    begin = current;                                                   // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                       // Test whether the wait has elapsed
    right.setPWM(femur_F, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // F
    begin = current;                                                   // Save the start time of the current servo state.
  }

  if (current - begin >= wait) {                                       // Test whether the wait has elapsed
    right.setPWM(femur_B, 0, map(DOWN, 0, DOWN, SERVOMIN, SERVOMAX));  // B
    begin = current;                                                   // Save the start time of the current servo state.
  }

  delay(500);
}
//-----------------------------------------------------------------------------------------------------------------------
