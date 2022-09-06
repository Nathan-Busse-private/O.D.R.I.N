#include <HexaServo.h>

#define SPEED 130

#define TIBIA 45

#define COXA_CCW 70
#define COXA_CW 115

#define AC_UP 100
#define AC_DOWN 92

int UP = AC_UP;
int DOWN = AC_DOWN;

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
    walkfwd();
  }

  for (int j = 0; j <= 2; j++) {
    walkback();
  }
  for (int k = 0; k <= 2; k++) {
    walkleft();
    {
      for (int l = 0; l <= 2; l++) {
        walkright();
      }
    }
  }
}
void walkfwd() {
  tibia();
  tri1();
  tri2();
  tri3();
  tri4();

  tri5();
  tri6();
  tri7();
  tri8();

  tri9();
  tri10();
  tri11();
  tri12();

}

void walkback() {
  tibia();
  b1();
  b2();
  b3();
  b4();

  b5();
  b6();
  b7();
  b8();

  b9();
  b10();
  b11();
  b12();
}

void walkleft() {
  tibia();
  l1();
  l2();
  l3();
  l4();

  l5();
  l6();
  l7();
  l8();

  l9();
  l10();
  l11();
  l12();
}

void walkright() {
  tibia();
  r1();
  r2();
  r3();
  r4();

  r5();
  r6();
  r7();
  r8();

  r9();
  r10();
  r11();
  r12();
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

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

};
void tri2() {
  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

};

void tri3() {
  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();

};
void tri4() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

};

void tri5() {
  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

};
void tri6() {
  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

};

void tri7() {
  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();

};
void tri8() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

};

void tri9() {
  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

};
void tri10() {
  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

};

void tri11() {
  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();

};
void tri12() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

};

//----------------------------Back------------------------------

void b1() {
  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();

}

void b2() {

  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

}

void b3() {

  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void b4() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

}

void b5() {
  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();

}

void b6() {

  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

}

void b7() {

  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void b8() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

}

void b9() {
  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();

}

void b10() {

  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

}

void b11() {

  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void b12() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

}


//-------------------Left-----------------------

void l1() {
  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();

}

void l2() {

  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

}

void l3() {

  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void l4() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

}

void l5() {
  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();

}

void l6() {

  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

}

void l7() {

  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void l8() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

}

void l9() {
  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();

}

void l10() {

  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

}

void l11() {

  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void l12() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

}

//----------------Right-------------------

void r1() {
  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void r2() {

  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

}

void r3() {

  A_coxa.write(COXA_CCW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CCW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CCW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CW, SPEED);
  B_coxa.wait();

}

void r4() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

}

void r5() {
  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void r6() {

  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

}

void r7() {

  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void r8() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();

}

void r9() {
  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void r10() {

  A_femur.write(AC_DOWN, SPEED);
  A_femur.wait();

  C_femur.write(DOWN, SPEED);
  C_femur.wait();

  E_femur.write(DOWN, SPEED);
  E_femur.wait();

  D_femur.write(UP, SPEED);
  D_femur.wait();

  F_femur.write(UP, SPEED);
  F_femur.wait();

  B_femur.write(UP, SPEED);
  B_femur.wait();

}

void r11() {

  A_coxa.write(COXA_CW, SPEED);
  A_coxa.wait();

  C_coxa.write(COXA_CW, SPEED);
  C_coxa.wait();

  E_coxa.write(COXA_CW, SPEED);
  E_coxa.wait();

  D_coxa.write(COXA_CCW, SPEED);
  D_coxa.wait();

  F_coxa.write(COXA_CCW, SPEED);
  F_coxa.wait();

  B_coxa.write(COXA_CCW, SPEED);
  B_coxa.wait();

}

void r12() {
  A_femur.write(AC_UP, SPEED);
  A_femur.wait();

  C_femur.write(UP, SPEED);
  C_femur.wait();

  E_femur.write(UP, SPEED);
  E_femur.wait();

  D_femur.write(DOWN, SPEED);
  D_femur.wait();

  F_femur.write(DOWN, SPEED);
  F_femur.wait();

  B_femur.write(DOWN, SPEED);
  B_femur.wait();


}

void Srop(){

  //  caliberate servo to 90 degrees

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


  // detach servos

  // LEG 1
  A_coxa.detach();
  A_coxa.wait();

  A_femur.detach();
  A_femur.wait();

  A_tibia.detach();
  A_tibia.wait();

  // LEG 2
  B_coxa.detach();
  B_coxa.wait();

  B_femur.detach();
  B_femur.wait();

  B_tibia.detach();
  B_tibia.wait();

  // LEG 3
  C_coxa.detach();
  C_coxa.wait();

  C_femur.detach();
  C_femur.wait();

  C_tibia.detach();
  C_tibia.wait();

  // LEG 4
  D_coxa.detach();
  D_coxa.wait();

  D_femur.detach();
  D_femur.wait();

  D_tibia.detach();
  D_tibia.wait();

  // LEG 5
  E_coxa.detach();
  E_coxa.wait();

  E_femur.detach();
  E_femur.wait();

  E_tibia.detach();
  E_tibia.wait();

  // LEG 6
  F_coxa.detach();
  F_coxa.wait();

  F_femur.detach();
  F_femur.wait();

  F_tibia.detach();
  F_tibia.wait();
  
  
}
