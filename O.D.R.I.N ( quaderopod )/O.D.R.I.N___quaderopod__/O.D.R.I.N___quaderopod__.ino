
#include <OdrinServo.h>

#define SPEED 100

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



OdrinServo C_coxa;
OdrinServo C_femur;
OdrinServo C_tibia;

OdrinServo D_coxa;
OdrinServo D_femur;
OdrinServo D_tibia;

OdrinServo F_coxa;
OdrinServo F_femur;
OdrinServo F_tibia;

void setup()
{
  // LEG 1
  digitalWrite(2, OUTPUT);
  digitalWrite(3, OUTPUT);
  digitalWrite(4, OUTPUT);

  // LEG 2
  digitalWrite(5, OUTPUT);
  digitalWrite(6, OUTPUT);
  digitalWrite(7, OUTPUT);

  // LEG 3
  digitalWrite(8, OUTPUT);
  digitalWrite(9, OUTPUT);
  digitalWrite(10, OUTPUT);

 

  // LEG 4
  digitalWrite(11, OUTPUT);
  digitalWrite(12, OUTPUT);
  digitalWrite(13, OUTPUT);

  // LEG 1
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

 

  // LEG 2
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  // LEG 3
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

 
  // LEG 4
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT); 
  pinMode(13, OUTPUT);

  // LEG 1
  A_coxa.attach(2);
  A_femur.attach(3);
  A_tibia.attach(4);



  // LEG 2
  C_coxa.attach(5);
  C_femur.attach(6);
  C_tibia.attach(7);

  // LEG 3
  D_coxa.attach(8);
  D_femur.attach(9);
  D_tibia.attach(10);

 
  // LEG 4
  F_coxa.attach(11);
  F_femur.attach(12);
  F_tibia.attach(13);

/*

  // LEG 1
  A_coxa.write(90, SPEED);
  A_coxa.wait();

  A_femur.write(90, SPEED);
  A_femur.wait();

  A_tibia.write(90, SPEED);
  A_tibia.wait();

  

  // LEG 2
  C_coxa.write(90, SPEED);
  C_coxa.wait();

  C_femur.write(90, SPEED);
  C_femur.wait();

  C_tibia.write(90, SPEED);
  C_tibia.wait();

  // LEG 3
  D_coxa.write(90, SPEED);
  D_coxa.wait();

  D_femur.write(90, SPEED);
  D_femur.wait();

  D_tibia.write(90, SPEED);
  D_tibia.wait();

  

  // LEG 4
  F_coxa.write(90, SPEED);
  F_coxa.wait();

  F_femur.write(90, SPEED);
  F_femur.wait();

  F_tibia.write(90, SPEED);
  F_tibia.wait();

*/
}

void loop()
{
  for (int i = 0; i < 4; i++) {
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

 

  C_tibia.slowmove(TIBIA, SPEED);
  C_tibia.wait();

  D_tibia.slowmove(TIBIA, SPEED);
  D_tibia.wait();

  

  F_tibia.slowmove(TIBIA, SPEED);
  F_tibia.wait();
}

void tri1() {
  A_coxa.slowmove(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.slowmove(COXA_CW, SPEED);
  C_coxa.wait();

 

  D_coxa.slowmove(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.slowmove(COXA_CW, SPEED);
  F_coxa.wait();

  

};
void tri2() {
  A_femur.slowmove(DOWN, SPEED);
  A_femur.wait();

  C_femur.slowmove(DOWN, SPEED);
  C_femur.wait();

  

  D_femur.slowmove(UP, SPEED);
  D_femur.wait();

  F_femur.slowmove(UP, SPEED);
  F_femur.wait();

  

};

void tri3() {
  A_coxa.slowmove(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.slowmove(COXA_CCW, SPEED);
  C_coxa.wait();

  

  D_coxa.slowmove(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.slowmove(COXA_CCW, SPEED);
  F_coxa.wait();

  

};
void tri4() {
  A_femur.slowmove(UP, SPEED);
  A_femur.wait();

  C_femur.slowmove(UP, SPEED);
  C_femur.wait();

  

  D_femur.slowmove(DOWN, SPEED);
  D_femur.wait();

  F_femur.slowmove(DOWN, SPEED);
  F_femur.wait();

 

};
