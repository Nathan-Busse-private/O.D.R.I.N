#include <VarSpeedServo.h>

//#include <Servo.h>

#define SPEED 255


#define TIBIA 45
//#define DELAY 3000

#define COXA_CCW 80
#define COXA_CW 115

/*
  ~front~
  A  D
  B  E
  C  F
  ~back~
*/

#define AC_UP 100
#define AC_DOWN 92



int UP = AC_UP;
int DOWN = AC_DOWN;

VarSpeedServo A_coxa;
VarSpeedServo A_femur;
VarSpeedServo A_tibia;

VarSpeedServo B_coxa;
VarSpeedServo B_femur;
VarSpeedServo B_tibia;

VarSpeedServo C_coxa;
VarSpeedServo C_femur;
VarSpeedServo C_tibia;

VarSpeedServo D_coxa;
VarSpeedServo D_femur;
VarSpeedServo D_tibia;

VarSpeedServo E_coxa;
VarSpeedServo E_femur;
VarSpeedServo E_tibia;

VarSpeedServo F_coxa;
VarSpeedServo F_femur;
VarSpeedServo F_tibia;

void setup()
{
  // LEG 1
  digitalWrite(48, OUTPUT);
  digitalWrite(47, OUTPUT);
  digitalWrite(46, OUTPUT);

  // LEG 2
  digitalWrite(62, OUTPUT);
  digitalWrite(61, OUTPUT);
  digitalWrite(60, OUTPUT);

  // LEG 3
  digitalWrite(56, OUTPUT);
  digitalWrite(55, OUTPUT);
  digitalWrite(54, OUTPUT);

  // LEG 4
  digitalWrite(45, OUTPUT);
  digitalWrite(44, OUTPUT);
  digitalWrite(43, OUTPUT);

  // LEG 5
  digitalWrite(41, OUTPUT);
  digitalWrite(40, OUTPUT);
  digitalWrite(39, OUTPUT);

  // LEG 6
  digitalWrite(8, OUTPUT);
  digitalWrite(7, OUTPUT);
  digitalWrite(6, OUTPUT);


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

  // configure


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

  //delay(5000);

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
//delay(DELAY);

  //delay(10000);

}

void loop()
{
  for (int i = 0; i <= 2; i++) {
    walkfwd();
  }
 




  /*
    b5();
    b6();
  */
}
void walkfwd() {
  tibia();
  tri1();
  tri2();
  tri3();
  tri4();
  /*
    tri5();
    tri6();
  */
}


void tibia() {
  A_tibia.write(TIBIA, SPEED);
  A_tibia.wait();

  B_tibia.write(TIBIA, SPEED);
  B_tibia.wait();

  C_tibia.write(TIBIA, SPEED);
  C_tibia.wait();

  D_tibia.write(TIBIA, SPEED);
  D_tibia.wait();

  E_tibia.write(TIBIA, SPEED);
  E_tibia.wait();

  F_tibia.write(TIBIA, SPEED);
  F_tibia.wait();
}

void tri1() {
  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();
  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  //delay(DELAY);
};
void tri2() {
  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

  /*
    E_femur.write(AC_DOWN);
    F_femur.write(DOWN);
  */


  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  //delay(DELAY);
};

void tri3() {
  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();


  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  //delay(DELAY);
};
void tri4() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();


  C_femur.write(UP, SPEED);
  C_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  /*
    D_femur.write(DOWN);
    B_femur.write(DOWN);
  */

  //delay(DELAY);
};
