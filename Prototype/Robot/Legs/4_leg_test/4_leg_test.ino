#include <Servo.h>

#define TIBIA 45
#define DELAY 600

#define COXA_CCW 70
#define COXA_CW 105

/*
  ~front~
  A  D
  B  E
  C  F
  ~back~
*/

#define AC_UP 92
#define AC_DOWN 125

int UP = AC_UP;
int DOWN = AC_DOWN;

Servo E_coxa;
Servo E_femur;
Servo E_tibia;

Servo B_coxa;
Servo B_femur;
Servo B_tibia;

Servo AC_coxa;
Servo AC_femur;
Servo AC_tibia;

Servo DF_coxa;
Servo DF_femur;
Servo DF_tibia;

void setup()
{
  digitalWrite(48, OUTPUT);
  digitalWrite(47, OUTPUT);
  digitalWrite(46, OUTPUT);

  digitalWrite(60, OUTPUT);
  digitalWrite(59, OUTPUT);
  digitalWrite(58, OUTPUT);

  digitalWrite(56, OUTPUT);
  digitalWrite(55, OUTPUT);
  digitalWrite(54, OUTPUT);

  digitalWrite(32, OUTPUT);
  digitalWrite(31, OUTPUT);
  digitalWrite(30, OUTPUT);

  pinMode(48, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(46, OUTPUT);

  pinMode(60, OUTPUT);
  pinMode(59, OUTPUT);
  pinMode(58, OUTPUT);

  pinMode(56, OUTPUT);
  pinMode(55, OUTPUT);
  pinMode(54, OUTPUT);

  pinMode(32, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(30, OUTPUT);

  AC_coxa.attach(48);
  AC_femur.attach(47);
  AC_tibia.attach(46);

  B_coxa.attach(60);
  B_femur.attach(59);
  B_tibia.attach(58);

  DF_coxa.attach(56);
  DF_femur.attach(55);
  DF_tibia.attach(54);

  E_coxa.attach(32);
  E_femur.attach(31);
  E_tibia.attach(30);

  // configure

  AC_coxa.write(90);
  AC_femur.write(90);
  AC_tibia.write(90);
  //delay(DELAY);

  B_coxa.write(90);
  B_femur.write(90);
  B_tibia.write(90);
  //delay(DELAY);

  DF_coxa.write(90);
  DF_femur.write(90);
  DF_tibia.write(90);
  //delay(DELAY);

  E_coxa.write(90);
  E_femur.write(90);
  E_tibia.write(90);
  //delay(DELAY);
  delay(15000);

}

void loop()
{
  for (int i = 0; i <= 2; i++) {
    walkfwd();
  }
  for (int j = 0; j <= 2; j++) {
    walkbwd();
  }
  for (int k = 0; k <= 2; k++) {
    turnleft();
  }
  for (int l = 0; l <= 2; l++) {
    turnright();
  }

}
void walkbwd() {
  tibia();
  b1();
  b2();
  b3();
  b4();
}
void walkfwd() {
  tibia();
  tri1();
  tri2();
  tri3();
  tri4();
}

void turnleft() {
  tibia();
  l1();
  l2();
  l3();
  l4();
}

void turnright() {
  tibia();
  r1();
  r2();
  r3();
  r4();
}
void tibia() {
  AC_tibia.write(TIBIA);
  B_tibia.write(TIBIA);
  DF_tibia.write(TIBIA);
  E_tibia.write(TIBIA);
}

void tri1() {
  AC_coxa.write(COXA_CW);
  E_coxa.write(COXA_CCW);

  DF_coxa.write(COXA_CW);
  B_coxa.write(COXA_CCW);

  delay(DELAY);
};
void tri2() {
  AC_femur.write(AC_DOWN);
  E_femur.write(DOWN);

  DF_femur.write(UP);
  B_femur.write(UP);

  delay(DELAY);
};

void tri3() {
  AC_coxa.write(COXA_CCW);
  E_coxa.write(COXA_CW);

  DF_coxa.write(COXA_CCW);
  B_coxa.write(COXA_CW);

  delay(DELAY);
};
void tri4() {
  AC_femur.write(AC_UP);
  E_femur.write(UP);

  DF_femur.write(DOWN);
  B_femur.write(DOWN);

  delay(DELAY);
};

void b1() {
  AC_coxa.write(COXA_CCW);
  E_coxa.write(COXA_CW);

  DF_coxa.write(COXA_CCW);
  B_coxa.write(COXA_CW);

  delay(DELAY);
};
void b2() {
  AC_femur.write(AC_DOWN);
  E_femur.write(DOWN);

  DF_femur.write(UP);
  B_femur.write(UP);

  delay(DELAY);
};

void b3() {
  AC_coxa.write(COXA_CW);
  E_coxa.write(COXA_CCW);

  DF_coxa.write(COXA_CW);
  B_coxa.write(COXA_CCW);

  delay(DELAY);
};
void b4() {
  AC_femur.write(AC_UP);
  E_femur.write(UP);

  DF_femur.write(DOWN);
  B_femur.write(DOWN);

  delay(DELAY);
};

void l1() {
  AC_coxa.write(COXA_CCW);
  E_coxa.write(COXA_CCW);

  DF_coxa.write(COXA_CW);
  B_coxa.write(COXA_CW);

  delay(DELAY);
};
void l2() {
  AC_femur.write(DOWN);
  E_femur.write(DOWN);

  DF_femur.write(UP);
  B_femur.write(UP);

  delay(DELAY);
};

void l3() {
  AC_coxa.write(COXA_CW);
  E_coxa.write(COXA_CW);

  DF_coxa.write(COXA_CCW);
  B_coxa.write(COXA_CCW);

  delay(DELAY);
};
void l4() {
  AC_femur.write(UP);
  E_femur.write(UP);

  DF_femur.write(DOWN);
  B_femur.write(DOWN);

  delay(DELAY);
};

void r1() {
  AC_coxa.write(COXA_CW);
  E_coxa.write(COXA_CW);

  DF_coxa.write(COXA_CCW);
  B_coxa.write(COXA_CCW);

  delay(DELAY);
};
void r2() {
  AC_femur.write(DOWN);
  E_femur.write(DOWN);

  DF_femur.write(UP);
  B_femur.write(UP);

  delay(DELAY);
};

void r3() {
  AC_coxa.write(COXA_CCW);
  E_coxa.write(COXA_CCW);

  DF_coxa.write(COXA_CW);
  B_coxa.write(COXA_CW);

  delay(DELAY);
};
void r4() {
  AC_femur.write(UP);
  E_femur.write(UP);

  DF_femur.write(DOWN);
  B_femur.write(DOWN);

  delay(DELAY);
};
