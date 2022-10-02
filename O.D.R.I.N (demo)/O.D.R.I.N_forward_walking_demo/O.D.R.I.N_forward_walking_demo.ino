#include <TimerFive.h>

#include <TimerOne.h>

#include <OdrinServo.h>



#define SPEED 70

#define TIBIA 45

#define COXA_CCW 115
#define COXA_CW 60

#define AC_UP 100
#define AC_DOWN 92

int UP = AC_UP;
int DOWN = AC_DOWN;

OdrinServo A_coxa;
OdrinServo A_femur;
OdrinServo A_tibia;

OdrinServo B_coxa;
OdrinServo B_femur;
OdrinServo B_tibia;

OdrinServo C_coxa;
OdrinServo C_femur;
OdrinServo C_tibia;

OdrinServo D_coxa;
OdrinServo D_femur;
OdrinServo D_tibia;

OdrinServo E_coxa;
OdrinServo E_femur;
OdrinServo E_tibia;

OdrinServo F_coxa;
OdrinServo F_femur;
OdrinServo F_tibia;

void setup()
{
  // LEG 1
  analogWrite(40, OUTPUT);
  analogWrite(41, OUTPUT);
  analogWrite(42, OUTPUT);

  // LEG 2
  analogWrite(47, OUTPUT);
  analogWrite(48, OUTPUT);
  analogWrite(49, OUTPUT);

  // LEG 3
  analogWrite(51, OUTPUT);
  analogWrite(52, OUTPUT);
  analogWrite(53, OUTPUT);

  // LEG 4
  analogWrite(36, OUTPUT);
  analogWrite(37, OUTPUT);
  analogWrite(38, OUTPUT);

  // LEG 5
  analogWrite(30, OUTPUT);
  analogWrite(31, OUTPUT);
  analogWrite(32, OUTPUT);

  // LEG 6
  analogWrite(8, OUTPUT);
  analogWrite(7, OUTPUT);
  analogWrite(6, OUTPUT);

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
  for (int i = 0; i <= 5; i++) {
    walkfwd();
  }
  }

void walkfwd() {
  tibia();
  tri1();
  tri2();
  tri3();
  tri4();

  

}

void tibia() {
  A_tibia.slowmove(TIBIA, SPEED);
  A_tibia.wait();

  B_tibia.slowmove(TIBIA, SPEED);
  B_tibia.wait();

  C_tibia.slowmove(TIBIA, SPEED);
  C_tibia.wait();

  D_tibia.slowmove(TIBIA, SPEED);
  D_tibia.wait();

  E_tibia.slowmove(TIBIA, SPEED);
  E_tibia.wait();

  F_tibia.slowmove(TIBIA, SPEED);
  F_tibia.wait();
}

void tri1() {
  A_coxa.slowmove(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.slowmove(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.slowmove(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.slowmove(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.slowmove(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.slowmove(COXA_CCW, SPEED);
  B_coxa.wait();

};
void tri2() {
  A_femur.slowmove(DOWN, SPEED);
  A_femur.wait();

  C_femur.slowmove(DOWN, SPEED);
  C_femur.wait();

  E_femur.slowmove(DOWN, SPEED);
  E_femur.wait();

  D_femur.slowmove(UP, SPEED);
  D_femur.wait();

  F_femur.slowmove(UP, SPEED);
  F_femur.wait();

  B_femur.slowmove(UP, SPEED);
  B_femur.wait();

};

void tri3() {
  A_coxa.slowmove(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.slowmove(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.slowmove(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.slowmove(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.slowmove(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.slowmove(COXA_CW, SPEED);
  B_coxa.wait();

};
void tri4() {
  A_femur.slowmove(UP, SPEED);
  A_femur.wait();

  C_femur.slowmove(UP, SPEED);
  C_femur.wait();

  E_femur.slowmove(UP, SPEED);
  E_femur.wait();

  D_femur.slowmove(DOWN, SPEED);
  D_femur.wait();

  F_femur.slowmove(DOWN, SPEED);
  F_femur.wait();

  B_femur.slowmove(DOWN, SPEED);
  B_femur.wait();

};
