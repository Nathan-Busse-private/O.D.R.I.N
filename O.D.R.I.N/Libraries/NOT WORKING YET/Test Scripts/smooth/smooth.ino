#include <ServoEasing.hpp>


//#include <ServoEasing.h>


//#define SPEED 100

#define TIBIA 45

#define COXA_CCW 115
#define COXA_CW 60

#define AC_UP 100
#define AC_DOWN 92

int UP = AC_UP;
int DOWN = AC_DOWN;

ServoEasing A_coxa;
ServoEasing A_femur;
ServoEasing A_tibia;



ServoEasing C_coxa;
ServoEasing C_femur;
ServoEasing C_tibia;

ServoEasing D_coxa;
ServoEasing D_femur;
ServoEasing D_tibia;

ServoEasing F_coxa;
ServoEasing F_femur;
ServoEasing F_tibia;

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
  A_coxa.write(90);
  A_coxa.wait();

  A_femur.write(90);
  A_femur.wait();

  A_tibia.write(90);
  A_tibia.wait();

  

  // LEG 2
  C_coxa.write(90);
  C_coxa.wait();

  C_femur.write(90);
  C_femur.wait();

  C_tibia.write(90);
  C_tibia.wait();

  // LEG 3
  D_coxa.write(90);
  D_coxa.wait();

  D_femur.write(90);
  D_femur.wait();

  D_tibia.write(90);
  D_tibia.wait();

  

  // LEG 4
  F_coxa.write(90);
  F_coxa.wait();

  F_femur.write(90);
  F_femur.wait();

  F_tibia.write(90);
  F_tibia.wait();

*/
}

void loop()
{
  for(int j=120; j>=40, j-=1, j++;) {
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
  A_tibia.easeTo(TIBIA);
  //A_tibia.wait();

 

  C_tibia.easeTo(TIBIA);
 // C_tibia.wait();

  D_tibia.easeTo(TIBIA);
  //D_tibia.wait();

  

  F_tibia.easeTo(TIBIA);
  //F_tibia.wait();

  delay(100);
}

void tri1() {
  A_coxa.easeTo(COXA_CW);
  //A_coxa.wait();

  C_coxa.easeTo(COXA_CW);
  //C_coxa.wait();

 

  D_coxa.easeTo(COXA_CW);
  //D_coxa.wait();

  F_coxa.easeTo(COXA_CW);
  //F_coxa.wait();

    delay(100);


};
void tri2() {
  A_femur.easeTo(DOWN);
  //A_femur.wait();

  C_femur.easeTo(DOWN);
  //C_femur.wait();

  

  D_femur.easeTo(UP);
  //D_femur.wait();

  F_femur.easeTo(UP);
  //F_femur.wait();

    delay(100);


};

void tri3() {
  A_coxa.easeTo(COXA_CCW);
  //A_coxa.wait();

  C_coxa.easeTo(COXA_CCW);
  //C_coxa.wait();

  

  D_coxa.easeTo(COXA_CCW);
  //D_coxa.wait();

  F_coxa.easeTo(COXA_CCW);
  //F_coxa.wait();

    delay(100);


};
void tri4() {
  A_femur.easeTo(UP);
  //A_femur.wait();

  C_femur.easeTo(UP);
  //C_femur.wait();

  

  D_femur.easeTo(DOWN);
  //D_femur.wait();

  F_femur.easeTo(DOWN);
  //F_femur.wait();

   delay(100);


};
