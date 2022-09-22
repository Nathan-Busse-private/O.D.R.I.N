/* NOTE
 *  
 *  13 to 24 servos use timers 1&5 disabling PWM on pins 11,12,44,45 and 46
 *  
 *  Servos can be assigned to any digital pin from D0 - D53. 
 *  
 */


/* deploy code for Odrin

  10 September 2022

*/

// Libraries

#include <HexaServo.h>

//#################

// declarations (old)

//#define SPEED 130
#define COXA_CCW 70
#define COXA_CW 115
#define TIBIA 45

#define AC_UP 100
#define AC_DOWN 92

int UP = AC_UP;
int DOWN = AC_DOWN;

//##################


// New declarations


#define DEPLOY_TIBIA 125
#define Raze_femur 60
#define Lower_femur 35

#define DEPLOY_SPEED 255

int Rise = Raze_femur;
int Lower = Lower_femur;

/*declarations for leg unfold




*/




/*declarations for leg fold





*/

//###################

// Servo declarations


HexaServo A_coxa;
HexaServo A_femur;
HexaServo A_tibia;

HexaServo B_coxa;
HexaServo B_femur;
HexaServo B_tibia;

HexaServo C_coxa;
HexaServo C_femur;
HexaServo C_tibia;

HexaServo D_coxa;
HexaServo D_femur;
HexaServo D_tibia;

HexaServo E_coxa;
HexaServo E_femur;
HexaServo E_tibia;

HexaServo F_coxa;
HexaServo F_femur;
HexaServo F_tibia;

void setup()
{
  // LEG 1
  digitalWrite(40, OUTPUT);
  digitalWrite(41, OUTPUT);
  digitalWrite(42, OUTPUT);

  // LEG 2
  digitalWrite(47, OUTPUT);
  digitalWrite(48, OUTPUT);
  digitalWrite(49, OUTPUT);

  // LEG 3
  digitalWrite(51, OUTPUT);
  digitalWrite(52, OUTPUT);
  digitalWrite(53, OUTPUT);

  // LEG 4
  digitalWrite(36, OUTPUT);
  digitalWrite(37, OUTPUT);
  digitalWrite(38, OUTPUT);

  // LEG 5
  digitalWrite(30, OUTPUT);
  digitalWrite(31, OUTPUT);
  digitalWrite(32, OUTPUT);

  // LEG 6
  digitalWrite(8, OUTPUT);
  digitalWrite(7, OUTPUT);
  digitalWrite(6, OUTPUT);

  // LEG 1
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);

  // LEG 2
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);

  // LEG 3
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);

  // LEG 4
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);

  // LEG 5
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);

  // LEG 6
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);

  // LEG 1
  A_coxa.attach(40);
  A_femur.attach(41);
  A_tibia.attach(42);

  // LEG 2
  B_coxa.attach(47);
  B_femur.attach(48);
  B_tibia.attach(49);

  // LEG 3
  C_coxa.attach(51);
  C_femur.attach(52);
  C_tibia.attach(53);

  // LEG 4
  D_coxa.attach(36);
  D_femur.attach(37);
  D_tibia.attach(38);

  // LEG 5
  E_coxa.attach(30);
  E_femur.attach(31);
  E_tibia.attach(32
  
  );

  // LEG 6
  F_coxa.attach(8);
  F_femur.attach(7);
  F_tibia.attach(6);
/*
  // LEG 1
  A_coxa.slowmove(90, SPEED);
  A_coxa.wait();

  A_femur.slowmove(90, SPEED);
  A_femur.wait();

  A_tibia.slowmove(90, SPEED);
  A_tibia.wait();

  // LEG 2
  B_coxa.slowmove(90, SPEED);
  B_coxa.wait();

  B_femur.slowmove(90, SPEED);
  B_femur.wait();

  B_tibia.slowmove(90, SPEED);
  B_tibia.wait();

  // LEG 3
  C_coxa.slowmove(90, SPEED);
  C_coxa.wait();

  C_femur.slowmove(90, SPEED);
  C_femur.wait();

  C_tibia.slowmove(90, SPEED);
  C_tibia.wait();

  // LEG 4
  D_coxa.slowmove(90, SPEED);
  D_coxa.wait();

  D_femur.slowmove(90, SPEED);
  D_femur.wait();

  D_tibia.slowmove(90, SPEED);
  D_tibia.wait();

  // LEG 5
  E_coxa.slowmove(90, SPEED);
  E_coxa.wait();

  E_femur.slowmove(90, SPEED);
  E_femur.wait();

  E_tibia.slowmove(90, SPEED);
  E_tibia.wait();

  // LEG 6
  F_coxa.slowmove(90, SPEED);
  F_coxa.wait();

  F_femur.slowmove(90, SPEED);
  F_femur.wait();

  F_tibia.slowmove(90, SPEED);
  F_tibia.wait();
*/
}

void loop()
{
  for (int i = 0; i <= 2; i++) {
    Deploy();
  }
}
void tibia() {
  A_tibia.slowmove(DEPLOY_TIBIA, DEPLOY_SPEED);
  A_tibia.wait();

  B_tibia.slowmove(DEPLOY_TIBIA, DEPLOY_SPEED);
  B_tibia.wait();

  C_tibia.slowmove(DEPLOY_TIBIA, DEPLOY_SPEED);
  C_tibia.wait();

  D_tibia.slowmove(DEPLOY_TIBIA, DEPLOY_SPEED);
  D_tibia.wait();

  E_tibia.slowmove(DEPLOY_TIBIA, DEPLOY_SPEED);
  E_tibia.wait();

  F_tibia.slowmove(DEPLOY_TIBIA, DEPLOY_SPEED);
  F_tibia.wait();
}

void Deploy() {
  tibia();

  Deploy1();

  Deploy2();

  Deploy3();

  Deploy4();

  Deploy5();

  Deploy6();

  Deploy7();

  Deploy8();

}


void Deploy1() {
  A_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  A_coxa.wait();

  C_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  C_coxa.wait();

  E_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  E_coxa.wait();

  D_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  D_coxa.wait();

  F_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  F_coxa.wait();

  B_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  B_coxa.wait();

};
void Deploy2() {

  A_femur.slowmove(Rise, DEPLOY_SPEED);
  A_femur.wait();

  C_femur.slowmove(Lower, DEPLOY_SPEED);
  C_femur.wait();

  E_femur.slowmove(Lower, DEPLOY_SPEED);
  E_femur.wait();

  D_femur.slowmove(Rise, DEPLOY_SPEED);
  D_femur.wait();

  F_femur.slowmove(Rise, DEPLOY_SPEED);
  F_femur.wait();

  B_femur.slowmove(Rise, DEPLOY_SPEED);
  B_femur.wait();

};

void Deploy3() {
  A_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  A_coxa.wait();

  C_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  C_coxa.wait();

  E_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  E_coxa.wait();

  D_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  D_coxa.wait();

  F_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  F_coxa.wait();

  B_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  B_coxa.wait();

};
void Deploy4() {
  A_femur.slowmove(Rise, DEPLOY_SPEED);
  A_femur.wait();

  C_femur.slowmove(Rise, DEPLOY_SPEED);
  C_femur.wait();

  E_femur.slowmove(Rise, DEPLOY_SPEED);
  E_femur.wait();

  D_femur.slowmove(Lower, DEPLOY_SPEED);
  D_femur.wait();

  F_femur.slowmove(Lower, DEPLOY_SPEED);
  F_femur.wait();

  B_femur.slowmove(Lower, DEPLOY_SPEED);
  B_femur.wait();

};

void Deploy5() {
  A_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  A_coxa.wait();

  C_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  C_coxa.wait();

  E_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  E_coxa.wait();

  D_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  D_coxa.wait();

  F_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  F_coxa.wait();

  B_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  B_coxa.wait();

};
void Deploy6() {
  A_femur.slowmove(Lower, DEPLOY_SPEED);
  A_femur.wait();

  C_femur.slowmove(Lower, DEPLOY_SPEED);
  C_femur.wait();

  E_femur.slowmove(Lower, DEPLOY_SPEED);
  E_femur.wait();

  D_femur.slowmove(Rise, DEPLOY_SPEED);
  D_femur.wait();

  F_femur.slowmove(Rise, DEPLOY_SPEED);
  F_femur.wait();

  B_femur.slowmove(Rise, DEPLOY_SPEED);
  B_femur.wait();

};

void Deploy7() {
  A_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  A_coxa.wait();

  C_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  C_coxa.wait();

  E_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  E_coxa.wait();

  D_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  D_coxa.wait();

  F_coxa.slowmove(COXA_CCW, DEPLOY_SPEED);
  F_coxa.wait();

  B_coxa.slowmove(COXA_CW, DEPLOY_SPEED);
  B_coxa.wait();

};
void Deploy8() {
  A_femur.slowmove(Rise, DEPLOY_SPEED);
  A_femur.wait();

  C_femur.slowmove(Rise, DEPLOY_SPEED);
  C_femur.wait();

  E_femur.slowmove(Rise, DEPLOY_SPEED);
  E_femur.wait();

  D_femur.slowmove(Lower, DEPLOY_SPEED);
  D_femur.wait();

  F_femur.slowmove(Lower, DEPLOY_SPEED);
  F_femur.wait();

  B_femur.slowmove(Lower, DEPLOY_SPEED);
  B_femur.wait();

};


// Main code here
