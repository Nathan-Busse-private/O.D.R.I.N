// Below are the ID arrays of servos. You must set the IDs of the servo according
//to the documents :
//IDs of the servos of the left front leg: 0, 1, 2 (inner, middle, outer)
//IDs of the servos of the left middle leg: 10, 11, 12(inner, middle, outer)
//IDs of the servos of the left back leg: 20, 21, 22 (inner, middle, outer)
//IDs of the servos of the right back leg: 30, 31, 32(inner, middle, outer)
//IDs of the servos of the right middle leg: 40, 41, 42 (inner, middle, outer)
//IDs of the servos of the right front leg: 50, 51, 52(inner, middle, outer)

//#include <CDS5500_2Serials.h>
#include <Hexapod_Servo.h>
#include <ServoConsole.h>

int axisA[] = {0, 20, 40};
int axisB[] = {10, 30, 50};
int hipA[] = {1, 21, 41};
int hipB[] = {11, 31, 51};
int legA[] = {2, 22, 32};
int legB[] = {12, 32, 52};
int axis[] = {0, 10, 20, 30, 40, 50};
int hips[] = {1, 11, 21, 31, 41, 51};
int legs[] = {2, 12, 22, 32 ,42, 52};
// servo controller
ServoConsole console;

void setup(){
  Serial.begin(115200); //For printing out data, or debugging.
  Serial2.begin(1000000); // Used for control servos on left side.
  Serial1.begin(1000000);// Used for control servos on right side.
}

void loop(){
   console.Move(legs, 6, 170, 511); //Legs move to 170 for standing up
   console.Move(hips,6, 480, 511); // hips move to 480 for standing up
   console.Move(axisA, 3, 130, 511); // axis group A move to 130. Prepare for walking
   console.Move(axisB, 3, 70, 511); // axis group B move 70. Prepare for walking
   delay(1000); // waits for their moving

   while(1){
     walk();
     //walking loop
   }
}

void walk(){
  delay(500);
  console.MoveUp(hipB, 3, 100, 500); //hips group B move up 100
  console.MoveUp(axisB, 3, 60, 300);// axis group B move forward 60
  console.MoveDown(axisA, 3, 60, 300);// axis group A move backward 60
  delay(500);// waits for movement
  console.MoveDown(hipB, 3, 100, 500);//hips group B move down 100
  delay(500);// waits for movement
  console.MoveUp(hipA, 3, 100, 500);//hips group A move up 100
  console.MoveDown(axisB, 3, 60, 300);// axis group B move backward 60
  console.MoveUp(axisA, 3, 60, 300);// axis group A move forward 60
  delay(500);// waits for movement
  console.MoveDown(hipA,3, 100, 500);//hips group A move down 100
}