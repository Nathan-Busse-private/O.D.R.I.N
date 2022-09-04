#include <math.h>

#include <Servo.h>   
const int COXA1_SERVO  = 45;          //servo port definitions
const int FEMUR1_SERVO = 43;
const int TIBIA1_SERVO = 41;
const int COXA2_SERVO  = 39;
const int FEMUR2_SERVO = 37;
const int TIBIA2_SERVO = 35;
const int COXA3_SERVO  = 33;
const int FEMUR3_SERVO = 31;
const int TIBIA3_SERVO = 29;
const int COXA4_SERVO  = 27;
const int FEMUR4_SERVO = 25;
const int TIBIA4_SERVO = 23;
const int COXA5_SERVO  = 21;
const int FEMUR5_SERVO = 19;
const int TIBIA5_SERVO = 17;
const int COXA6_SERVO  = 15;
const int FEMUR6_SERVO = 13;
const int TIBIA6_SERVO = 11;


const int COXA_LENGTH = 51;           //leg part lengths
const int FEMUR_LENGTH = 65;
const int TIBIA_LENGTH = 121;

const int TRAVEL = 30;                //translate and rotate travel limit constant

const long A12DEG = 209440;           //12 degrees in radians x 1,000,000
const long A30DEG = 523599;           //30 degrees in radians x 1,000,000

const int FRAME_TIME_MS = 20;         //frame time (20msec = 50Hz)

const float HOME_X[6] = {  82.0,   0.0, -82.0,  -82.0,    0.0,  82.0};  //coxa-to-toe home positions
const float HOME_Y[6] = {  82.0, 116.0,  82.0,  -82.0, -116.0, -82.0};
const float HOME_Z[6] = { -80.0, -80.0, -80.0,  -80.0,  -80.0, -80.0};

const float BODY_X[6] = { 110.4,  0.0, -110.4, -110.4,    0.0, 110.4};  //body center-to-coxa servo distances 
const float BODY_Y[6] = {  58.4, 90.8,   58.4,  -58.4,  -90.8, -58.4};
const float BODY_Z[6] = {   0.0,  0.0,    0.0,    0.0,    0.0,   0.0};

const int COXA_CAL[6]  = {2, -1, -1, -3, -2, -3};                       //servo calibration constants
const int FEMUR_CAL[6] = {4, -2,  0, -1,  0,  0};
const int TIBIA_CAL[6] = {0, -3, -3, -2, -3, -1};

//18 servos

Servo coxa1_servo;      
Servo femur1_servo;
Servo tibia1_servo;
Servo coxa2_servo;
Servo femur2_servo;
Servo tibia2_servo;
Servo coxa3_servo;
Servo femur3_servo;
Servo tibia3_servo;
Servo coxa4_servo;
Servo femur4_servo;
Servo tibia4_servo;
Servo coxa5_servo;
Servo femur5_servo;
Servo tibia5_servo;
Servo coxa6_servo;
Servo femur6_servo;
Servo tibia6_servo;

void setup() 
{ 
  
 Serial.begin(115200);
  
  //attach servos
  coxa1_servo.attach(COXA1_SERVO,610,2400);
  femur1_servo.attach(FEMUR1_SERVO,610,2400);
  tibia1_servo.attach(TIBIA1_SERVO,610,2400);
  coxa2_servo.attach(COXA2_SERVO,610,2400);
  femur2_servo.attach(FEMUR2_SERVO,610,2400);
  tibia2_servo.attach(TIBIA2_SERVO,610,2400);
  coxa3_servo.attach(COXA3_SERVO,610,2400);
  femur3_servo.attach(FEMUR3_SERVO,610,2400);
  tibia3_servo.attach(TIBIA3_SERVO,610,2400);
  coxa4_servo.attach(COXA4_SERVO,610,2400);
  femur4_servo.attach(FEMUR4_SERVO,610,2400);
  tibia4_servo.attach(TIBIA4_SERVO,610,2400);
  coxa5_servo.attach(COXA5_SERVO,610,2400);
  femur5_servo.attach(FEMUR5_SERVO,610,2400);
  tibia5_servo.attach(TIBIA5_SERVO,610,2400);
  coxa6_servo.attach(COXA6_SERVO,610,2400);
  femur6_servo.attach(FEMUR6_SERVO,610,2400);
  tibia6_servo.attach(TIBIA6_SERVO,610,2400);

} 

void loop() 

//******************************************************
// Calibrate the servos to 90 degrees with every powerup

{ 
  coxa1_servo.write(90+COXA_CAL[0]); 
  femur1_servo.write(90+FEMUR_CAL[0]); 
  tibia1_servo.write(90+TIBIA_CAL[0]); 
  
  coxa2_servo.write(90+COXA_CAL[1]); 
  femur2_servo.write(90+FEMUR_CAL[1]); 
  tibia2_servo.write(90+TIBIA_CAL[1]); 
  
  coxa3_servo.write(90+COXA_CAL[2]); 
  femur3_servo.write(90+FEMUR_CAL[2]); 
  tibia3_servo.write(90+TIBIA_CAL[2]); 
  
  coxa4_servo.write(90+COXA_CAL[3]); 
  femur4_servo.write(90+FEMUR_CAL[3]); 
  tibia4_servo.write(90+TIBIA_CAL[3]); 
  
  coxa5_servo.write(90+COXA_CAL[4]); 
  femur5_servo.write(90+FEMUR_CAL[4]); 
  tibia5_servo.write(90+TIBIA_CAL[4]); 
  
  coxa6_servo.write(90+COXA_CAL[5]); 
  femur6_servo.write(90+FEMUR_CAL[5]); 
  tibia6_servo.write(90+TIBIA_CAL[5]); 
  delay(1000); // doesn't constantly update the servos which can fry them
}
//******************************************************

// Ripple programme

void Ripple(){

  tibia1 




  
}
