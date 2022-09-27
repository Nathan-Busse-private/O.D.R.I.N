#include <SoftwareSerial.h>      // We use software serial on pins D12 and D8 for HC06
SoftwareSerial Bluetooth(12, 9); // Arduino RX 12 and TX 9 -> HC-06 Bluetooth TX RX
#include <OdrinServo.h>               //We will use servo library

//Variables
int Received = 0;             //here we store the received byte number from Bluetooth
int DELAY = 5;                //Delay in ms for the main loop, the bigger, the slower will the robot move
int MODE = 0;                 //Start mode is 0, so all motors -> home position
bool Impair_start = false;    //In order to add phase rotation between legs, we use this variable
int FM1 = 0;                  //The leg movement loop has different stages
int FM2 = 0;                  //Each of these variables will be used in those stages
int FM3 = 0;                  //We use these as counters to count degrees
int FM4 = 0;                  //...
int FM5 = 0;                  //...
int FM6 = 0;                  //...
int FM7 = 0;                  //...
int FM8 = 0;                  //...


/*/////////////////Initial home position in degrees//////////////////
The first leg is the front left leg as seen from the front
Thew first motor of each leg is the one closer to the robot body*/
int home_A_coxa = 90; 
int home_A_femur = 90; 
int home_A_tibia = 90;

int home_B_coxa = 90;
int home_B_femur = 90;
int home_B_tibia = 90;

int home_C_coxa = 90;
int home_C_femur = 90;
int home_C_tibia = 90;

int home_D_coxa = 90;
int home_D_femur = 90;
int home_D_tibia = 90;

int home_E_coxa = 90;
int home_E_femur = 90;
int home_E_tibia = 90;

int home_F_coxa = 90;
int home_F_femur = 90;
int home_F_tibia = 90;

int SPEED = 150; //Map delay from 5 to 80 ms

/*/////////////////////////////////////////////////////////////////*/


/*//////////////////////Declare the Servos/////////////////////////*/
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

int LED = 17;
int bat = A1;
/*/////////////////////////////////////////////////////////////////*/ 


void setup() {
  Serial.begin(9600);     //We use the Arduino monitopr for debug...
  Bluetooth.begin(9600);  // My default baud rate of the HC06, yours can be different
  pinMode(LED, OUTPUT);
  pinMode(bat, INPUT);
  digitalWrite(LED, LOW);
  
  //Select digital pins of the MEGA for each motro
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
  E_tibia.attach(32);

   // LEG 6
  F_coxa.attach(8);
  F_femur.attach(7);
  F_tibia.attach(6);
  
  /*/////////////////////////////////////////////////////////////////*/ 
  
  set_home_pos();       //Home all motors
}

void loop() {
  /*Battery is 12.6V fully charged. We want to enable the LED when battery is below 8.5V.
  Divider is 1k/3K so 0.33 * 8.5 = 2.83 volts -> in 10 bits = 580
  */
  if(analogRead(bat) < 580)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }

  
  if(Bluetooth.available()>0)           //If we receive somethin, we enter this loop
  {
    Received = Bluetooth.read();        //We store the received byte number
    //Serial.println(Received);         //Print for debug...
    if (Received == 0)                  //If we receive the "0" number, mode = 1
    {
      MODE = 0;               //Change mode to 0 (home position)
      Impair_start = false;   //Reset variables   
      FM1 = 0;                //Reset values...
      FM2 = 0;                //Reset values...
      FM3 = 0;                //Reset values...
      FM4 = 0;                //Reset values...
      FM5 = 0;                //Reset values...
      FM6 = 0;                //Reset values...
      FM7 = 0;                //Reset values...
      FM8 = 0;                //Reset values...
    }
    if (Received == 1)        //If we receive a 1, change mode to 1 and so on...
    {
      MODE = 1;
    }
    if (Received == 2)
    {
      MODE = 2;
    }
    if (Received == 3)
    {
      MODE = 3;
    }
    if (Received == 4)
    {
      MODE = 4;
    }
    if (Received == 5)
    {
      MODE = 5;
    }
    if (Received == 6)
    {
      MODE = 6;
    }
    /*If the received number is higher than 11, then we receive the values from slider
    this will change the speed of movement by changing the delay of the loop*/
    if (Received >= 12)
    {
      
    }
   }

  

  //Home position
  if(MODE == 0){
    set_home_pos();
  }

  //Move Forward
  if(MODE == 1){
    move_frwd();
  }

  //Move Backwards
  if(MODE == 2){
    move_bwd();
  }
  
  //Move Right
  if(MODE == 3){
    move_right();
  }
   
  //Move Left
  if(MODE == 4){
    move_left();
  }

  //Rotate Left
  if(MODE == 5){
    rotate_left();
  }

  //Rotate Right
  if(MODE == 6){
    rotate_right();
  }
 
       //Add delay of the loop, this will control the speed
}



/////////////////////////////SET HOME POSITION
void set_home_pos()
{
  A_coxa.slowmove(home_A_coxa, SPEED); 
  A_coxa.wait();
  
  A_femur.slowmove(home_A_femur, SPEED); 
  A_femur.wait();

  
  A_tibia.slowmove(home_A_tibia, SPEED); 
  A_tibia.wait();

  B_coxa.slowmove(home_B_coxa, SPEED); 
  B_coxa.wait();
  
  B_femur.slowmove(home_B_femur, SPEED); 
  B_tibia.slowmove(home_B_tibia, SPEED); 

  C_coxa.slowmove(home_C_coxa, SPEED); 
  C_femur.slowmove(home_C_femur, SPEED); 
  C_tibia.slowmove(home_C_tibia, SPEED); 

  A_coxa.slowmove(home_A_coxa, SPEED); 
  D_femur.slowmove(home_D_femur, SPEED); 
  D_tibia.slowmove(home_D_tibia, SPEED); 

  E_coxa.slowmove(home_E_coxa, SPEED); 
  E_femur.slowmove(home_E_femur, SPEED); 
  E_tibia.slowmove(home_E_tibia, SPEED); 

  F_coxa.slowmove(home_F_coxa, SPEED); 
  F_femur.slowmove(home_F_femur, SPEED); 
  F_tibia.slowmove(home_F_tibia, SPEED); 
}




/////////////////////////////MOVE FORWARD
void move_frwd(){
  //Impair Lift 10 deg
  if (FM1 <=10){
    A_femur.slowmove(home_A_femur - FM1, SPEED); 
    A_tibia.slowmove(home_A_tibia - FM1, SPEED);
    C_femur.slowmove(home_C_femur - FM1, SPEED); 
    C_tibia.slowmove(home_C_tibia - FM1, SPEED);
    E_femur.slowmove(home_E_femur - FM1, SPEED); 
    E_tibia.slowmove(home_E_tibia - FM1, SPEED);
    FM1++;
  }  
      
  //Impair rote fwd 30 deg
  if (FM2 <= 30)
  {
    A_coxa.slowmove(home_A_coxa - FM2, SPEED); 
    C_coxa.slowmove(home_C_coxa - FM2, SPEED); 
    E_coxa.slowmove(home_E_coxa + FM2, SPEED); 
    FM2++;
  }
  
  //Impair touch ground -10 deg
  if (FM2 > 20 && FM3 <=10){
    A_femur.slowmove(home_A_femur + FM3, SPEED); 
    A_tibia.slowmove(home_A_tibia + FM3, SPEED);
    C_femur.slowmove(home_C_femur + FM3, SPEED); 
    C_tibia.slowmove(home_C_tibia + FM3, SPEED);
    E_femur.slowmove(home_E_femur + FM3, SPEED); 
    E_tibia.slowmove(home_E_tibia + FM3, SPEED);
    FM3++;
  } 
  
  //Impair rotate bwd -30 deg  
  if (FM2 >= 30)
  {
    A_coxa.slowmove(home_A_coxa + FM4, SPEED); 
    C_coxa.slowmove(home_C_coxa + FM4, SPEED); 
    E_coxa.slowmove(home_E_coxa - FM4, SPEED); 
    FM4++;
    Impair_start = true;      
  }
  if(FM4 >= 30) {
    FM1 = 0;
    FM2 = 0;
    FM3 = 0;
    FM4 = 0;
  }
  
//////////////////////////////////

  if (Impair_start){
    //Pair Lift 10 deg
    if (FM5 <=10){
      B_femur.slowmove(home_B_femur - FM5, SPEED); 
      B_tibia.slowmove(home_B_tibia - FM5, SPEED);
      D_femur.slowmove(home_D_femur - FM5, SPEED); 
      D_tibia.slowmove(home_D_tibia - FM5, SPEED);
      F_femur.slowmove(home_F_femur - FM5, SPEED); 
      F_tibia.slowmove(home_F_tibia - FM5, SPEED);
      FM5++;
    }  
    //Pair rote fwd 30 deg
    if (FM6 <= 30)
    {
      B_coxa.slowmove(home_B_coxa - FM6, SPEED); 
      A_coxa.slowmove(home_A_coxa + FM6, SPEED); 
      F_coxa.slowmove(home_F_coxa + FM6, SPEED); 
      FM6++;
    }
  
    //Pair touch ground -10 deg
    if (FM6 > 20 && FM7 <=10){
      B_femur.slowmove(home_B_femur + FM7, SPEED); 
      B_tibia.slowmove(home_B_tibia + FM7, SPEED);
      D_femur.slowmove(home_D_femur + FM7, SPEED); 
      D_tibia.slowmove(home_D_tibia + FM7, SPEED);
      F_femur.slowmove(home_F_femur + FM7, SPEED); 
      F_tibia.slowmove(home_F_tibia + FM7, SPEED);
      FM7++;
    } 
  
    //Pair rotate bwd -30 deg  
    if (FM6 >= 30)
    {
      B_coxa.slowmove(home_B_coxa + FM8, SPEED); 
      A_coxa.slowmove(home_A_coxa - FM8, SPEED); 
      F_coxa.slowmove(home_F_coxa - FM8, SPEED); 
      FM8++;      
    }
    if(FM8 >= 30) {
      Impair_start = false;
      FM5 = 0;
      FM6 = 0;
      FM7 = 0;
      FM8 = 0;
    }    
  } 
}//End Move Forward


/////////////////////////////MOVE Backwards
void move_bwd(){ 
  //Impair Lift 10 deg
  if (FM1 <=10){
    A_femur.slowmove(home_A_femur - FM1, SPEED); 
    A_tibia.slowmove(home_A_tibia - FM1, SPEED);
    C_femur.slowmove(home_C_femur - FM1, SPEED); 
    C_tibia.slowmove(home_C_tibia - FM1, SPEED);
    E_femur.slowmove(home_E_femur - FM1, SPEED); 
    E_tibia.slowmove(home_E_tibia - FM1, SPEED);
    FM1++;
  }  
    
  //Impair rote fwd 30 deg
  if (FM2 <= 30)
  {
    A_coxa.slowmove(home_A_coxa + FM2, SPEED); 
    C_coxa.slowmove(home_C_coxa + FM2, SPEED); 
    E_coxa.slowmove(home_E_coxa - FM2, SPEED); 
    FM2++;
  }
  
  //Impair touch ground -10 deg
  if (FM2 > 20 && FM3 <=10){
    A_femur.slowmove(home_A_femur + FM3, SPEED); 
    A_tibia.slowmove(home_A_tibia + FM3, SPEED);
    C_femur.slowmove(home_C_femur + FM3, SPEED); 
    C_tibia.slowmove(home_C_tibia + FM3, SPEED);
    E_femur.slowmove(home_E_femur + FM3, SPEED); 
    E_tibia.slowmove(home_E_tibia + FM3, SPEED);
    FM3++;
  } 
  
  //Impair rotate bwd -30 deg  
  if (FM2 >= 30)
  {
    A_coxa.slowmove(home_A_coxa - FM4, SPEED); 
    C_coxa.slowmove(home_C_coxa - FM4, SPEED); 
    E_coxa.slowmove(home_E_coxa + FM4, SPEED); 
    FM4++;
    Impair_start = true;
  }
  if(FM4 >= 30) {
    FM1 = 0;
    FM2 = 0;
    FM3 = 0;
    FM4 = 0;
  }
  
//////////////////////////////////

  if (Impair_start){
    //Pair Lift 10 deg
    if (FM5 <=10){
      B_femur.slowmove(home_B_femur - FM5, SPEED); 
      B_tibia.slowmove(home_B_tibia - FM5, SPEED);
      D_femur.slowmove(home_D_femur - FM5, SPEED); 
      D_tibia.slowmove(home_D_tibia - FM5, SPEED);
      F_femur.slowmove(home_F_femur - FM5, SPEED); 
      F_tibia.slowmove(home_F_tibia - FM5, SPEED);
      FM5++;
    }  
    //Pair rote fwd 30 deg
    if (FM6 <= 30)
    {
      B_coxa.slowmove(home_B_coxa + FM6, SPEED); 
      A_coxa.slowmove(home_A_coxa - FM6, SPEED); 
      F_coxa.slowmove(home_F_coxa - FM6, SPEED); 
      FM6++;
    }
  
    //Pair touch ground -10 deg
    if (FM6 > 20 && FM7 <=10){
      B_femur.slowmove(home_B_femur + FM7, SPEED); 
      B_tibia.slowmove(home_B_tibia + FM7, SPEED);
      D_femur.slowmove(home_D_femur + FM7, SPEED); 
      D_tibia.slowmove(home_D_tibia + FM7, SPEED);
      F_femur.slowmove(home_F_femur + FM7, SPEED); 
      F_tibia.slowmove(home_F_tibia + FM7, SPEED);
      FM7++;
    } 
  
    //Pair rotate bwd -30 deg  
    if (FM6 >= 30)
    {
      B_coxa.slowmove(home_B_coxa - FM8, SPEED); 
      A_coxa.slowmove(home_A_coxa + FM8, SPEED); 
      F_coxa.slowmove(home_F_coxa + FM8, SPEED); 
      FM8++;      
    }
    if(FM8 >= 30) {
      FM5 = 0;
      FM6 = 0;
      FM7 = 0;
      FM8 = 0;
    }    
  } 
}//End Move Backwards



/////////////////////////////Rotate Left
void rotate_left(){
  //Impair Lift 10 deg
  if (FM1 <=10){
    A_femur.slowmove(home_A_femur - FM1, SPEED); 
    A_tibia.slowmove(home_A_tibia - FM1, SPEED);
    C_femur.slowmove(home_C_femur - FM1, SPEED); 
    C_tibia.slowmove(home_C_tibia - FM1, SPEED);
    E_femur.slowmove(home_E_femur - FM1, SPEED); 
    E_tibia.slowmove(home_E_tibia - FM1, SPEED);
    FM1++;
  }  
      
  //Impair rote fwd 30 deg
  if (FM2 <= 30)
  {
    A_coxa.slowmove(home_A_coxa - FM2, SPEED); 
    C_coxa.slowmove(home_C_coxa - FM2, SPEED); 
    E_coxa.slowmove(home_E_coxa - FM2, SPEED); 
    FM2++;
  }
  
  //Impair touch ground -10 deg
  if (FM2 > 20 && FM3 <=10){
    A_femur.slowmove(home_A_femur + FM3, SPEED); 
    A_tibia.slowmove(home_A_tibia + FM3, SPEED);
    C_femur.slowmove(home_C_femur + FM3, SPEED); 
    C_tibia.slowmove(home_C_tibia + FM3, SPEED);
    E_femur.slowmove(home_E_femur + FM3, SPEED); 
    E_tibia.slowmove(home_E_tibia + FM3, SPEED);
    FM3++;
  } 
  
  //Impair rotate bwd -30 deg  
  if (FM2 >= 30)
  {
    A_coxa.slowmove(home_A_coxa + FM4, SPEED); 
    C_coxa.slowmove(home_C_coxa + FM4, SPEED); 
    E_coxa.slowmove(home_E_coxa + FM4, SPEED); 
    FM4++;
    Impair_start = true;      
  }
  if(FM4 >= 30) {
    FM1 = 0;
    FM2 = 0;
    FM3 = 0;
    FM4 = 0;
  }
  
//////////////////////////////////

  if (Impair_start){
    //Pair Lift 10 deg
    if (FM5 <=10){
      B_femur.slowmove(home_B_femur - FM5, SPEED); 
      B_tibia.slowmove(home_B_tibia - FM5, SPEED);
      D_femur.slowmove(home_D_femur - FM5, SPEED); 
      D_tibia.slowmove(home_D_tibia - FM5, SPEED);
      F_femur.slowmove(home_F_femur - FM5, SPEED); 
      F_tibia.slowmove(home_F_tibia - FM5, SPEED);
      FM5++;
    }  
    //Pair rote fwd 30 deg
    if (FM6 <= 30)
    {
      B_coxa.slowmove(home_B_coxa - FM6, SPEED); 
      A_coxa.slowmove(home_A_coxa - FM6, SPEED); 
      F_coxa.slowmove(home_F_coxa - FM6, SPEED); 
      FM6++;
    }
  
    //Pair touch ground -10 deg
    if (FM6 > 20 && FM7 <=10){
      B_femur.slowmove(home_B_femur + FM7, SPEED); 
      B_tibia.slowmove(home_B_tibia + FM7, SPEED);
      D_femur.slowmove(home_D_femur + FM7, SPEED); 
      D_tibia.slowmove(home_D_tibia + FM7, SPEED);
      F_femur.slowmove(home_F_femur + FM7, SPEED); 
      F_tibia.slowmove(home_F_tibia + FM7, SPEED);
      FM7++;
    } 
  
    //Pair rotate bwd -30 deg  
    if (FM6 >= 30)
    {
      B_coxa.slowmove(home_B_coxa + FM8, SPEED); 
      A_coxa.slowmove(home_A_coxa + FM8, SPEED); 
      F_coxa.slowmove(home_F_coxa + FM8, SPEED); 
      FM8++;      
    }
    if(FM8 >= 30) {
      Impair_start = false;
      FM5 = 0;
      FM6 = 0;
      FM7 = 0;
      FM8 = 0;
    }    
  } 
}//End Rotate Left


/////////////////////////////Rotate Right
void rotate_right(){ 
  //Impair Lift 10 deg
  if (FM1 <=10){
    A_femur.slowmove(home_A_femur - FM1, SPEED); 
    A_tibia.slowmove(home_A_tibia - FM1, SPEED);
    C_femur.slowmove(home_C_femur - FM1, SPEED); 
    C_tibia.slowmove(home_C_tibia - FM1, SPEED);
    E_femur.slowmove(home_E_femur - FM1, SPEED); 
    E_tibia.slowmove(home_E_tibia - FM1, SPEED);
    FM1++;
  }  
    
  //Impair rote fwd 30 deg
  if (FM2 <= 30)
  {
    A_coxa.slowmove(home_A_coxa + FM2, SPEED); 
    C_coxa.slowmove(home_C_coxa + FM2, SPEED); 
    E_coxa.slowmove(home_E_coxa + FM2, SPEED); 
    FM2++;
  }
  
  //Impair touch ground -10 deg
  if (FM2 > 20 && FM3 <=10){
    A_femur.slowmove(home_A_femur + FM3, SPEED); 
    A_tibia.slowmove(home_A_tibia + FM3, SPEED);
    C_femur.slowmove(home_C_femur + FM3, SPEED); 
    C_tibia.slowmove(home_C_tibia + FM3, SPEED);
    E_femur.slowmove(home_E_femur + FM3, SPEED); 
    E_tibia.slowmove(home_E_tibia + FM3, SPEED);
    FM3++;
  } 
  
  //Impair rotate bwd -30 deg  
  if (FM2 >= 30)
  {
    A_coxa.slowmove(home_A_coxa - FM4, SPEED); 
    C_coxa.slowmove(home_C_coxa - FM4, SPEED); 
    E_coxa.slowmove(home_E_coxa - FM4, SPEED); 
    FM4++;
    Impair_start = true;
  }
  if(FM4 >= 30) {
    FM1 = 0;
    FM2 = 0;
    FM3 = 0;
    FM4 = 0;
  }
  
//////////////////////////////////

  if (Impair_start){
    //Pair Lift 10 deg
    if (FM5 <=10){
      B_femur.slowmove(home_B_femur - FM5, SPEED); 
      B_tibia.slowmove(home_B_tibia - FM5, SPEED);
      D_femur.slowmove(home_D_femur - FM5, SPEED); 
      D_tibia.slowmove(home_D_tibia - FM5, SPEED);
      F_femur.slowmove(home_F_femur - FM5, SPEED); 
      F_tibia.slowmove(home_F_tibia - FM5, SPEED);
      FM5++;
    }  
    //Pair rote fwd 30 deg
    if (FM6 <= 30)
    {
      B_coxa.slowmove(home_B_coxa + FM6, SPEED); 
      A_coxa.slowmove(home_A_coxa + FM6, SPEED); 
      F_coxa.slowmove(home_F_coxa + FM6, SPEED); 
      FM6++;
    }
  
    //Pair touch ground -10 deg
    if (FM6 > 20 && FM7 <=10){
      B_femur.slowmove(home_B_femur + FM7, SPEED); 
      B_tibia.slowmove(home_B_tibia + FM7, SPEED);
      D_femur.slowmove(home_D_femur + FM7, SPEED); 
      D_tibia.slowmove(home_D_tibia + FM7, SPEED);
      F_femur.slowmove(home_F_femur + FM7, SPEED); 
      F_tibia.slowmove(home_F_tibia + FM7, SPEED);
      FM7++;
    } 
  
    //Pair rotate bwd -30 deg  
    if (FM6 >= 30)
    {
      B_coxa.slowmove(home_B_coxa - FM8, SPEED); 
      A_coxa.slowmove(home_D_coxa - FM8, SPEED); 
      F_coxa.slowmove(home_F_coxa - FM8, SPEED); 
      FM8++;      
    }
    if(FM8 >= 30) {
      FM5 = 0;
      FM6 = 0;
      FM7 = 0;
      FM8 = 0;
    }    
  } 
}//End Rotate Right


/////////////////////////////Move Right
void move_right(){
  //Impair Motor 2 -20 Motor 3 +20
  if (FM1 <= 20){    
    A_femur.slowmove(home_A_femur + FM1, SPEED); 
    A_tibia.slowmove(home_A_tibia + FM1, SPEED); 

    B_femur.slowmove(home_B_femur + FM1, SPEED); 
    B_tibia.slowmove(home_B_tibia - FM1*2, SPEED);
        
    C_femur.slowmove(home_C_femur + FM1, SPEED);     
    C_tibia.slowmove(home_C_tibia + FM1, SPEED); 

    D_femur.slowmove(home_D_femur - FM1, SPEED); 
    D_tibia.slowmove(home_D_tibia + FM1*2, SPEED);
    
    E_femur.slowmove(home_E_femur + FM1, SPEED);     
    E_tibia.slowmove(home_E_tibia - FM1, SPEED); 
  
    F_femur.slowmove(home_F_femur - FM1, SPEED); 
    F_tibia.slowmove(home_F_tibia + FM1*2, SPEED);  
    FM1++;
  }  

  if(FM1 >= 20 && FM2 <= 20){
     B_femur.slowmove(home_B_femur + FM1   + FM2, SPEED); 
     B_tibia.slowmove(home_B_tibia - FM1*2 + FM2*2, SPEED);

     D_femur.slowmove(home_D_femur - FM1   + FM2, SPEED); 
     D_tibia.slowmove(home_D_tibia + FM1*2 - FM2*2, SPEED);

     F_femur.slowmove(home_F_femur - FM1   + FM2, SPEED); 
     F_tibia.slowmove(home_F_tibia + FM1*2 - FM2*2, SPEED);
     FM2++;
  }

   if(FM2 >= 20 && FM3 <= 20){
    A_femur.slowmove(home_A_femur + FM1 - FM3, SPEED); 
    A_tibia.slowmove(home_A_tibia + FM1 - FM1, SPEED); 
   
            
    C_femur.slowmove(home_C_femur + FM1 - FM3, SPEED);     
    C_tibia.slowmove(home_C_tibia + FM1 - FM3, SPEED); 

    
    E_femur.slowmove(home_E_femur + FM1 - FM3, SPEED);     
    E_tibia.slowmove(home_E_tibia - FM1 + FM3, SPEED); 
  
    FM3++;
  }

  if(FM3 >= 20){
    FM1 = 0;
    FM2 = 0;
    FM3 = 0;
  }

}




/////////////////////////////Move Left
void move_left(){
  //Impair Motor 2 -20 Motor 3 +20
  if (FM1 <= 20){    
    D_femur.slowmove(home_D_femur + FM1, SPEED); 
    D_tibia.slowmove(home_D_tibia + FM1, SPEED); 

    E_femur.slowmove(home_E_femur + FM1, SPEED); 
    E_tibia.slowmove(home_E_tibia - FM1*2, SPEED);
        
    F_femur.slowmove(home_F_femur + FM1, SPEED);     
    F_tibia.slowmove(home_F_tibia + FM1, SPEED); 

    C_femur.slowmove(home_D_tibia - FM1, SPEED); 
    C_tibia.slowmove(home_D_tibia + FM1*2, SPEED);
    
    B_femur.slowmove(home_B_femur + FM1, SPEED);     
    B_tibia.slowmove(home_B_tibia - FM1, SPEED); 
  
    A_femur.slowmove(home_A_femur - FM1, SPEED); 
    A_tibia.slowmove(home_A_tibia + FM1*2, SPEED);  
    FM1++;
  }  

  if(FM1 >= 20 && FM2 <= 20){
     E_femur.slowmove(home_E_femur + FM1   + FM2, SPEED); 
     E_tibia.slowmove(home_E_tibia - FM1*2 + FM2*2, SPEED);

     C_femur.slowmove(home_C_femur - FM1   + FM2, SPEED); 
     C_tibia.slowmove(home_C_tibia + FM1*2 - FM2*2, SPEED);

     A_femur.slowmove(home_A_femur - FM1   + FM2, SPEED); 
     A_tibia.slowmove(home_A_tibia + FM1*2 - FM2*2, SPEED);
     FM2++;
  }

   if(FM2 >= 20 && FM3 <= 20){
    F_femur.slowmove(home_F_femur + FM1 - FM3, SPEED); 
    F_tibia.slowmove(home_F_tibia + FM1 - FM1, SPEED); 
   
            
    D_femur.slowmove(home_D_femur + FM1 - FM3, SPEED);     
    D_tibia.slowmove(home_D_tibia + FM1 - FM3, SPEED); 

    
    B_femur.slowmove(home_B_femur + FM1 - FM3, SPEED);     
    B_tibia.slowmove(home_B_tibia - FM1 + FM3, SPEED); 
  
    FM3++;
  }
  if(FM3 >= 20){
    FM1 = 0;
    FM2 = 0;
    FM3 = 0;
  }
}
