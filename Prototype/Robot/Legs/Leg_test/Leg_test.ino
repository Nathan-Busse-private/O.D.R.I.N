#include <Servo.h>


 #define TIBIA 25
 #define DELAY 150
 
 #define CW 70
 #define CCW 105

 #define UP 92
 #define DOWN 125

// ~~~~~~~~~~~~~~~~~~~~ //

Servo A_COX;
Servo A_FEM;
Servo A_TIB;

Servo B_COX;
Servo B_FEM;
Servo B_TIB;

Servo C_COX;
Servo C_FEM;
Servo C_TIB;

Servo D_COX;
Servo D_FEM;
Servo D_TIB;

Servo E_COX;
Servo E_FEM;
Servo E_TIB;

Servo F_COX;
Servo F_FEM;
Servo F_TIB;

int numtimes = 3;

//NewSoftSerial mySerial(rxPin, txPin);

void setup()// run once, when the sketch starts
{
 // mySerial.begin(9600);
  digitalWrite(2, OUTPUT);
  digitalWrite(3, OUTPUT);
  digitalWrite(4, OUTPUT);
  digitalWrite(5, OUTPUT);
  digitalWrite(6, OUTPUT);
  digitalWrite(7, OUTPUT);
  digitalWrite(8, OUTPUT);
  digitalWrite(9, OUTPUT);
  digitalWrite(10, OUTPUT);
  digitalWrite(11, OUTPUT);
  digitalWrite(12, OUTPUT);
  digitalWrite(13, OUTPUT); 
  digitalWrite(14, OUTPUT); 
  digitalWrite(15, OUTPUT); 
  digitalWrite(16, OUTPUT); 
  digitalWrite(17, OUTPUT); 
  digitalWrite(18, OUTPUT); 

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);

A_COX.attach(4);
A_FEM.attach(5);
A_TIB.attach (6);

B_COX.attach(7);
B_FEM.attach(8);
B_TIB.attach(9);

C_COX.attach(10);
C_FEM.attach(11);
C_TIB.attach(12);

D_COX.attach(14);
D_FEM.attach(15);
D_TIB.attach(16);

E_COX.attach(17);
E_FEM.attach(18);
E_TIB.attach(19);

F_COX.attach(20);
F_FEM.attach(21);
F_TIB.attach(20);

}
void loop()
{
  for (int i=0; i<=4; i++){  
    walkfwd();
  }
  for (int j=0; j<=4; j++){  
    walkbwd();
  }
  for (int k=0; k<=2; k++){  
    turnleft();  
  }
  for (int l=0; l<=2; l++){  
    turnright();  
  }  
}

void tibia() {
  A_TIB.write(TIBIA);
  B_TIB.write(TIBIA);
  C_TIB.write(TIBIA);
  D_TIB.write(TIBIA);
  E_TIB.write(TIBIA);
  F_TIB.write(TIBIA);
}


// ~~~~~~~~~~fwd~~~~~~~~~~ //

void f1() { 
  // [COXA] changed
  A_COX.write(CW);
  C_COX.write(CW);
  E_COX.write(CCW);
  
  D_COX.write(CW);
  F_COX.write(CW);
  B_COX.write(CCW);

  delay(DELAY);
}

void f2() { 
  // [FEMUR] changed
  A_FEM.write(DOWN);
  C_FEM.write(DOWN);
  E_FEM.write(DOWN);
  
  D_FEM.write(UP);
  F_FEM.write(UP);
  B_FEM.write(UP);

  delay(DELAY);
}

void f3() { 
  // [COXA] changed
  A_COX.write(CCW);
  C_COX.write(CCW);
  E_COX.write(CW);
  
  D_COX.write(CCW);
  F_COX.write(CCW);
  B_COX.write(CW);

  delay(DELAY);
}

void f4() { 
  // [FEMUR] changed
  A_FEM.write(UP);
  C_FEM.write(UP);
  E_FEM.write(UP);
  
  D_FEM.write(DOWN);
  F_FEM.write(DOWN);
  B_FEM.write(DOWN);

  delay(DELAY);
}

// ~~~~~~~~~bwd~~~~~~~~~~~ //


void b1() { 
  // [COXA] changed
  A_COX.write(CCW);
  C_COX.write(CCW);
  E_COX.write(CW);
  
  D_COX.write(CCW);
  F_COX.write(CCW);
  B_COX.write(CW);

  delay(DELAY);
}

void b2() { 
  // [FEMUR] changed
  A_FEM.write(DOWN);
  C_FEM.write(DOWN);
  E_FEM.write(DOWN);
  
  D_FEM.write(UP);
  F_FEM.write(UP);
  B_FEM.write(UP);

  delay(DELAY);
}

void b3() { 
  // [COXA] changed
  A_COX.write(CW);
  C_COX.write(CW);
  E_COX.write(CCW);
  
  D_COX.write(CW);
  F_COX.write(CW);
  B_COX.write(CCW);

  delay(DELAY);
}

void b4() { 
  // [FEMUR] changed
  A_FEM.write(UP);
  C_FEM.write(UP);
  E_FEM.write(UP);
  
  D_FEM.write(DOWN);
  F_FEM.write(DOWN);
  B_FEM.write(DOWN);

  delay(DELAY);
}

// ~~~~~~~~~left~~~~~~~~~~~ //

void l1() { 
  // [COXA] changed
  A_COX.write(CCW);
  C_COX.write(CCW);
  E_COX.write(CCW);
  
  D_COX.write(CW);
  F_COX.write(CW);
  B_COX.write(CW);

  delay(DELAY);
}

void l2() { 
  // [FEMUR] changed
  A_FEM.write(DOWN);
  C_FEM.write(DOWN);
  E_FEM.write(DOWN);
  
  D_FEM.write(UP);
  F_FEM.write(UP);
  B_FEM.write(UP);

  delay(DELAY);
}

void l3() { 
  // [COXA] changed
  A_COX.write(CW);
  C_COX.write(CW);
  E_COX.write(CW);
  
  D_COX.write(CCW);
  F_COX.write(CCW);
  B_COX.write(CCW);

  delay(DELAY);
}

void l4() { 
  // [FEMUR] changed
  A_FEM.write(UP);
  C_FEM.write(UP);
  E_FEM.write(UP);
  
  D_FEM.write(DOWN);
  F_FEM.write(DOWN);
  B_FEM.write(DOWN);

  delay(DELAY);
}

// ~~~~~~~~~right~~~~~~~~~~~ //

void r1() { 
  // [COXA] changed
  A_COX.write(CW);
  C_COX.write(CW);
  E_COX.write(CW);
  
  D_COX.write(CCW);
  F_COX.write(CCW);
  B_COX.write(CCW);

  delay(DELAY);
}

void r2() { 
  // [FEMUR] changed
  A_FEM.write(DOWN);
  C_FEM.write(DOWN);
  E_FEM.write(DOWN);
  
  D_FEM.write(UP);
  F_FEM.write(UP);
  B_FEM.write(UP);

  delay(DELAY);
}

void r3() { 
  // [COXA] changed
  A_COX.write(CCW);
  C_COX.write(CCW);
  E_COX.write(CCW);
  
  D_COX.write(CW);
  F_COX.write(CW);
  B_COX.write(CW);

  delay(DELAY);
}

void r4() { 
  // [FEMUR] changed
  A_FEM.write(UP);
  C_FEM.write(UP);
  E_FEM.write(UP);
  
  D_FEM.write(DOWN);
  F_FEM.write(DOWN);
  B_FEM.write(DOWN);

  delay(DELAY);
}

// ~~~~~~~~~~~~~~~~~~~~ //


void walkbwd() {
  tibia();
  b1();
  b2();
  b3();
  b4();  
}
void walkfwd() {
  tibia();
  f1();
  f2();
  f3();
  f4();
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

// ~~~~~~~~~~~~~~~~~~~~ //


//Send a Set Target command to the Maestro.
//Target is in units of quarter microseconds, so the normal range is 4000 to 8000.
void settarget(unsigned char servo, unsigned int target)
{
  target = map(target, 0, 180, 2400, 9500);
/*  mySerial.print(0xAA,BYTE); //start byte
  mySerial.print(0x0C,BYTE) ; //device id
  mySerial.print(0x04,BYTE); //command number
  mySerial.print(servo,BYTE); //servo number
  mySerial.print(target & 0x7F, BYTE);
  mySerial.print((target >> 7) & 0x7F,BYTE);

  */
}
