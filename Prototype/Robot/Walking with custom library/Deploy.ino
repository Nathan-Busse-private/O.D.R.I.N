
/* deploy code for Odrin 

10 September 2022

*/

// Libraries 

#include <HexaServo.h>

//#################

// declarations (old)

#define SPEED 130
#define COXA_CCW 70
#define COXA_CW 115
#define TIBIA 45

#define AC_UP 100
#define AC_DOWN 92

int UP = AC_UP;
int DOWN = AC_DOWN;

//##################


// New declarations


 #define DEPLOY_TIBIA 120
#define Raze_femur 35
#define Lower_femur 25

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
  analogWrite(48, OUTPUT);
  analogWrite(47, OUTPUT);
  analogWrite(46, OUTPUT);

  // LEG 2
  analogWrite(62, OUTPUT);
  analogWrite(61, OUTPUT);
  analogWrite(60, OUTPUT);

  // LEG 3
  analogWrite(56, OUTPUT);
  analogWrite(55, OUTPUT);
  analogWrite(54, OUTPUT);

  // LEG 4
  analogWrite(45, OUTPUT);
  analogWrite(44, OUTPUT);
  analogWrite(43, OUTPUT);

  // LEG 5
  analogWrite(41, OUTPUT);
  analogWrite(40, OUTPUT);
  analogWrite(39, OUTPUT);

  // LEG 6
  analogWrite(8, OUTPUT);
  analogWrite(7, OUTPUT);
  analogWrite(6, OUTPUT);

  // LEG 1
  pinMode(48, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(46, OUTPUT);

  // LEG 2
  pinMode(62, OUTPUT);
  pinMode(61, OUTPUT);
  pinMode(60, OUTPUT);

  // LEG 3
  pinMode(56, OUTPUT);
  pinMode(55, OUTPUT);
  pinMode(54, OUTPUT);

  // LEG 4
  pinMode(45, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(43, OUTPUT);

  // LEG 5
  pinMode(41, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(39, OUTPUT);

  // LEG 6
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);

  // LEG 1
  A_coxa.attach(48);
  A_femur.attach(47);
  A_tibia.attach(46);

  // LEG 2
  B_coxa.attach(62);
  B_femur.attach(61);
  B_tibia.attach(60);

  // LEG 3
  C_coxa.attach(56);
  C_femur.attach(55);
  C_tibia.attach(54);

  // LEG 4
  D_coxa.attach(45);
  D_femur.attach(44);
  D_tibia.attach(43);

  // LEG 5
  E_coxa.attach(41);
  E_femur.attach(40);
  E_tibia.attach(39);

  // LEG 6
  F_coxa.attach(8);
  F_femur.attach(7);
  F_tibia.attach(6);

  // LEG 1
  A_coxa.write(90, SPEED);
  A_coxa.wait();

  A_femur.write(90, SPEED);
  A_femur.wait();

  A_tibia.write(90, SPEED);
  A_tibia.wait();

  // LEG 2
  B_coxa.write(90, SPEED);
  B_coxa.wait();

  B_femur.write(90, SPEED);
  B_femur.wait();

  B_tibia.write(90, SPEED);
  B_tibia.wait();

  // LEG 3
  C_coxa.write(90, SPEED);
  C_coxa.wait();

  C_femur.write(90, SPEED);
  C_femur.wait();

  C_tibia.write(90, SPEED);
  C_tibia.wait();

  // LEG 4
  D_coxa.write(90, SPEED);
  D_coxa.wait();

  D_femur.write(90, SPEED);
  D_femur.wait();

  D_tibia.write(90, SPEED);
  D_tibia.wait();

  // LEG 5
  E_coxa.write(90, SPEED);
  E_coxa.wait();

  E_femur.write(90, SPEED);
  E_femur.wait();

  E_tibia.write(90, SPEED);
  E_tibia.wait();

  // LEG 6
  F_coxa.write(90, SPEED);
  F_coxa.wait();

  F_femur.write(90, SPEED);
  F_femur.wait();

  F_tibia.write(90, SPEED);
  F_tibia.wait();

}

void loop()
{
  for (int i = 0; i <= 2; i++) {
    Deploy();
  }
}
void tibia() {
  A_tibia.write(DEPLOY_TIBIA, DEPLOY_SPEED, true);
  A_tibia.wait();

  B_tibia.write(DEPLOY_TIBIA, DEPLOY_SPEED, true);
  B_tibia.wait();

  C_tibia.write(DEPLOY_TIBIA, DEPLOY_SPEED, true);
  C_tibia.wait();

  D_tibia.write(DEPLOY_TIBIA, DEPLOY_SPEED, true);
  D_tibia.wait();

  E_tibia.write(DEPLOY_TIBIA, DEPLOY_SPEED, true);
  E_tibia.wait();

  F_tibia.write(DEPLOY_TIBIA, DEPLOY_SPEED, true);
  F_tibia.wait();
}

void Deploy(){
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
  A_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  A_coxa.wait();

  C_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  E_coxa.wait();

  D_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  D_coxa.wait();

  F_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  B_coxa.wait();

};
void Deploy2() {

  A_femur.write(Rise, DEPLOY_SPEED, true);
  A_femur.wait();

  C_femur.write(Lower, DEPLOY_SPEED, true);
  C_femur.wait();

  E_femur.write(Lower, DEPLOY_SPEED, true);
  E_femur.wait();

  D_femur.write(Rise, DEPLOY_SPEED, true);
  D_femur.wait();

  F_femur.write(Rise, DEPLOY_SPEED, true);
  F_femur.wait();

  B_femur.write(Rise, DEPLOY_SPEED, true);
  B_femur.wait();

};

void Deploy3() {
  A_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  A_coxa.wait();

  C_coxa.write(COXA_CCW,DEPLOY_SPEED, true);
  C_coxa.wait();

  E_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  F_coxa.wait();

  B_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  B_coxa.wait();

};
void Deploy4() {
  A_femur.write(Rise, DEPLOY_SPEED, true);
  A_femur.wait();

  C_femur.write(Rise, DEPLOY_SPEED, true);
  C_femur.wait();

  E_femur.write(Rise, DEPLOY_SPEED, true);
  E_femur.wait();

  D_femur.write(Lower, DEPLOY_SPEED, true);
  D_femur.wait();

  F_femur.write(Lower, DEPLOY_SPEED, true);
  F_femur.wait();

  B_femur.write(Lower, DEPLOY_SPEED, true);
  B_femur.wait();

};

void Deploy5() {
  A_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  A_coxa.wait();

  C_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  E_coxa.wait();

  D_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  D_coxa.wait();

  F_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  B_coxa.wait();

};
void Deploy6() {
  A_femur.write(Lower, DEPLOY_SPEED, true);
  A_femur.wait();

  C_femur.write(Lower, DEPLOY_SPEED, true);
  C_femur.wait();

  E_femur.write(Lower, DEPLOY_SPEED, true);
  E_femur.wait();

  D_femur.write(Rise, DEPLOY_SPEED, true);
  D_femur.wait();

  F_femur.write(Rise, DEPLOY_SPEED, true);
  F_femur.wait();

  B_femur.write(Rise, DEPLOY_SPEED, true);
  B_femur.wait();

};

void Deploy7() {
  A_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  C_coxa.wait();

  E_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, DEPLOY_SPEED, true);
  F_coxa.wait();

  B_coxa.write(COXA_CW, DEPLOY_SPEED, true);
  B_coxa.wait();

};
void Deploy8() {
  A_femur.write(Rise, DEPLOY_SPEED, true);
  A_femur.wait();

  C_femur.write(Rise, DEPLOY_SPEED, true);
  C_femur.wait();

  E_femur.write(Rise, DEPLOY_SPEED, true);
  E_femur.wait();

  D_femur.write(Lower, DEPLOY_SPEED, true);
  D_femur.wait();

  F_femur.write(Lower, DEPLOY_SPEED, true);
  F_femur.wait();

  B_femur.write(Lower, DEPLOY_SPEED, true);
  B_femur.wait();

};


// Main code here
