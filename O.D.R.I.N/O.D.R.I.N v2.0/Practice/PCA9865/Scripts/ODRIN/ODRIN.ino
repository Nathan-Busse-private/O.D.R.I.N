#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
#include <math.h>
#include <avr/pgmspace.h>
#include <SoftwareSerial.h> 

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

#define MIN_PULSE_WIDTH       1000
#define MAX_PULSE_WIDTH       2000
#define DEFAULT_PULSE_WIDTH   1500
#define FREQUENCY             50
#define   M_PI   3.14159265358979323846 /* pi */
#define   atanf   atan

SoftwareSerial MyBlue(2, 3); // RX | TX 
Servo myservo16;  // create servo object to control a servo
Servo myservo17;  // create servo object to control a servo
  int angle16 = 0;
  int angle17 = 0;
  int i=0, j=0, k=0, l=0, m=0;
  int leg=0;
  int loc0=0, loc1=0, loc2=0;
  double a = 42, b = 84, c = 36;
  double x=0, y=0, z=0, xp=0, yp=0, lr=0, ar=0, at=0, az=0;
  int a0=0, a1=0, a2=0, dir=true;
  unsigned long currentMillis;
  unsigned long StartMillis;
  int flag = 0; 
  int waveSeq[6]={2, 1, 0, 3, 4, 5};
  int rippleSeq[6]={2, 5, 1, 3, 0, 5};
  int legNum = 0;


//The nullpunkt for each servo in ms
int ms[6][3]={
  {1550, 1550, 1450},
  {1550, 1600, 1450},
  {1600, 1450, 1400},
  {1550, 1500, 1400},
  {1600, 1450, 1500},
  {1500, 1500, 1500}
  };

// x, y, z coordinates of nodes of each leg
int legCenters[6][3] = {
  {40.36, 70.36, 0},
  {55.25, 0, 0},
  {40.36, -70.36, 0},
  {-40.36, -70.36, 0},
  {-55.25, 0, 0},
  {-40.36, 70.36, 0},
};

int legAngles[6] = {45, 0, 315, 225, 180, 135};


// default x, y, z coordinates of tips of each leg
int legTipsDefault[6][3] = {
  {95.52,   125.52,   -62},
  {133.25,  0,        -62},
  {95.52,   -125.52,  -62},
  {-95.52,  -125.52,  -62},
  {-133.25, 0,        -62},
  {-95.52,  125.52,   -62}
  };

// "current" x, y, z coordinates of tips of each leg
int legTipsLoc[6][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0}
  };

/*int fwdTable[40][3] = {
  {0, -40, 0},  
  {8, -38, 12},  
  {24, -32, 24},  
  {32, -24, 32},  
  {38, -12, 38},
  {40, 0, 40},  
  {38, 12, 38},  
  {32, 24, 32},  
  {24, 32, 24},  
  {12, 38, 12},
  {0, 40, 0},  
  {0, 32, 0},  
  {0, 24, 0},  
  {0, 16, 0},  
  {0, 8, 0},
  {0, 0, 0},  
  {0, -8, 0},  
  {0, -16, 0},  
  {0, -24, 0},  
  {0, -32, 0},
  {0, -40, 0},  
  {12, -38, 12},  
  {24, -32, 24},  
  {32, -24, 32},  
  {38, -12, 38},
  {40, 0, 40},  
  {38, 12, 38},  
  {32, 24, 32},  
  {24, 32, 24},  
  {12, 38, 12},
  {0, 40, 0},  
  {0, 32, 0},  
  {0, 24, 0},  
  {0, 16, 0},  
  {0, 8, 0},
  {0, 0, 0},  
  {0, -8, 0},  
  {0, -16, 0},  
  {0, -24, 0},  
  {0, -32, 0}
};*/

int fwdTable[40][3] = {
  {0, -20, 0},  {6, -19, 6},  {12, -16, 12},  {16, -12, 16},  {19, -6, 19},
  {20, 0, 20},  {19, 6, 19},  {16, 12, 16},  {12, 16, 12},  {6, 19, 6},
  {0, 20, 0},  {0, 16, 0},  {0, 12, 0},  {0, 8, 0},  {0, 4, 0},
  {0, 0, 0},  {0, -4, 0},  {0, -8, 0},  {0, -12, 0},  {0, -16, 0},
  {0, -20, 0},  {6, -19, 6},  {12, -16, 12},  {16, -12, 16},  {19, -6, 19},
  {20, 0, 20},  {19, 6, 19},  {16, 12, 16},  {12, 16, 12},  {6, 19, 6},
  {0, 20, 0},  {0, 16, 0},  {0, 12, 0},  {0, 8, 0},  {0, 4, 0},
  {0, 0, 0},  {0, -4, 0},  {0, -8, 0},  {0, -12, 0},  {0, -16, 0}
};


// Forward/backward waving
const int danceTable1[6][32][3] PROGMEM = {
  {{0.00, -12.00, 0.00},{0.00, -13.72, -3.46},{0.00, -15.02, -6.76},{0.00, -15.82, -9.83},{0.00, -16.08, -12.59},{0.00, -15.75, -14.95},{0.00, -14.83, -16.84},{0.00, -13.31, -18.17},{0.00, -11.24, -18.87},{0.00, -8.69, -18.89},{0.00, -5.74, -18.16},{0.00, -2.53, -16.69},{0.00, 0.79, -14.47},{0.00, 4.06, -11.57},{0.00, 7.12, -8.09},{0.00, 9.81, -4.18},{0.00, 12.00, 0.00},{0.00, 13.60, 4.24},{0.00, 14.56, 8.32},{0.00, 14.87, 12.05},{0.00, 14.53, 15.24},{0.00, 13.62, 17.74},{0.00, 12.19, 19.47},{0.00, 10.34, 20.35},{0.00, 8.15, 20.40},{0.00, 5.71, 19.64},{0.00, 3.10, 18.14},{0.00, 0.40, 16.01},{0.00, -2.33, 13.35},{0.00, -5.01, 10.31},{0.00, -7.57, 6.99},{0.00, -9.92, 3.51}},
  {{0.00, -12.00, 0.00},{0.00, -13.66, 0.39},{0.00, -14.79, 0.78},{0.00, -15.34, 1.11},{0.00, -15.31, 1.32},{0.00, -14.68, 1.40},{0.00, -13.51, 1.32},{0.00, -11.83, 1.09},{0.00, -9.70, 0.76},{0.00, -7.20, 0.38},{0.00, -4.42, -0.01},{0.00, -1.46, -0.34},{0.00, 1.56, -0.56},{0.00, 4.54, -0.63},{0.00, 7.34, -0.55},{0.00, 9.86, -0.33},{0.00, 12.00, 0.00},{0.00, 13.66, 0.39},{0.00, 14.79, 0.78},{0.00, 15.34, 1.11},{0.00, 15.31, 1.32},{0.00, 14.68, 1.40},{0.00, 13.51, 1.32},{0.00, 11.83, 1.09},{0.00, 9.70, 0.76},{0.00, 7.20, 0.38},{0.00, 4.42, -0.01},{0.00, 1.46, -0.34},{0.00, -1.56, -0.56},{0.00, -4.54, -0.63},{0.00, -7.34, -0.55},{0.00, -9.86, -0.33}},
  {{0.00, -12.00, 0.00},{0.00, -13.60, 4.24},{0.00, -14.56, 8.32},{0.00, -14.87, 12.05},{0.00, -14.53, 15.24},{0.00, -13.62, 17.74},{0.00, -12.19, 19.47},{0.00, -10.34, 20.35},{0.00, -8.15, 20.40},{0.00, -5.71, 19.64},{0.00, -3.10, 18.14},{0.00, -0.40, 16.01},{0.00, 2.33, 13.35},{0.00, 5.01, 10.31},{0.00, 7.57, 6.99},{0.00, 9.92, 3.51},{0.00, 12.00, 0.00},{0.00, 13.72, -3.46},{0.00, 15.02, -6.76},{0.00, 15.82, -9.83},{0.00, 16.08, -12.59},{0.00, 15.75, -14.95},{0.00, 14.83, -16.84},{0.00, 13.31, -18.17},{0.00, 11.24, -18.87},{0.00, 8.69, -18.89},{0.00, 5.74, -18.16},{0.00, 2.53, -16.69},{0.00, -0.79, -14.47},{0.00, -4.06, -11.57},{0.00, -7.12, -8.09},{0.00, -9.81, -4.18}},
  {{0.00, -12.00, 0.00},{0.00, -13.60, 4.24},{0.00, -14.56, 8.32},{0.00, -14.87, 12.05},{0.00, -14.53, 15.24},{0.00, -13.62, 17.74},{0.00, -12.19, 19.47},{0.00, -10.34, 20.35},{0.00, -8.15, 20.40},{0.00, -5.71, 19.64},{0.00, -3.10, 18.14},{0.00, -0.40, 16.01},{0.00, 2.33, 13.35},{0.00, 5.01, 10.31},{0.00, 7.57, 6.99},{0.00, 9.92, 3.51},{0.00, 12.00, 0.00},{0.00, 13.72, -3.46},{0.00, 15.02, -6.76},{0.00, 15.82, -9.83},{0.00, 16.08, -12.59},{0.00, 15.75, -14.95},{0.00, 14.83, -16.84},{0.00, 13.31, -18.17},{0.00, 11.24, -18.87},{0.00, 8.69, -18.89},{0.00, 5.74, -18.16},{0.00, 2.53, -16.69},{0.00, -0.79, -14.47},{0.00, -4.06, -11.57},{0.00, -7.12, -8.09},{0.00, -9.81, -4.18}},
  {{0.00, -12.00, 0.00},{0.00, -13.66, 0.39},{0.00, -14.79, 0.78},{0.00, -15.34, 1.11},{0.00, -15.31, 1.32},{0.00, -14.68, 1.40},{0.00, -13.51, 1.32},{0.00, -11.83, 1.09},{0.00, -9.70, 0.76},{0.00, -7.20, 0.38},{0.00, -4.42, -0.01},{0.00, -1.46, -0.34},{0.00, 1.56, -0.56},{0.00, 4.54, -0.63},{0.00, 7.34, -0.55},{0.00, 9.86, -0.33},{0.00, 12.00, 0.00},{0.00, 13.66, 0.39},{0.00, 14.79, 0.78},{0.00, 15.34, 1.11},{0.00, 15.31, 1.32},{0.00, 14.68, 1.40},{0.00, 13.51, 1.32},{0.00, 11.83, 1.09},{0.00, 9.70, 0.76},{0.00, 7.20, 0.38},{0.00, 4.42, -0.01},{0.00, 1.46, -0.34},{0.00, -1.56, -0.56},{0.00, -4.54, -0.63},{0.00, -7.34, -0.55},{0.00, -9.86, -0.33}},
  {{0.00, -12.00, 0.00},{0.00, -13.72, -3.46},{0.00, -15.02, -6.76},{0.00, -15.82, -9.83},{0.00, -16.08, -12.59},{0.00, -15.75, -14.95},{0.00, -14.83, -16.84},{0.00, -13.31, -18.17},{0.00, -11.24, -18.87},{0.00, -8.69, -18.89},{0.00, -5.74, -18.16},{0.00, -2.53, -16.69},{0.00, 0.79, -14.47},{0.00, 4.06, -11.57},{0.00, 7.12, -8.09},{0.00, 9.81, -4.18},{0.00, 12.00, 0.00},{0.00, 13.60, 4.24},{0.00, 14.56, 8.32},{0.00, 14.87, 12.05},{0.00, 14.53, 15.24},{0.00, 13.62, 17.74},{0.00, 12.19, 19.47},{0.00, 10.34, 20.35},{0.00, 8.15, 20.40},{0.00, 5.71, 19.64},{0.00, 3.10, 18.14},{0.00, 0.40, 16.01},{0.00, -2.33, 13.35},{0.00, -5.01, 10.31},{0.00, -7.57, 6.99},{0.00, -9.92, 3.51}}
};

const int danceTable2[6][32][3] PROGMEM  = {
  {{-12.00, 0.00, 0.00},{-9.91, 0.00, 2.60},{-7.51, 0.00, 5.18},{-4.90, 0.00, 7.69},{-2.15, 0.00, 10.03},{0.65, 0.00, 12.10},{3.42, 0.00, 13.80},{6.07, 0.00, 15.03},{8.52, 0.00, 15.71},{10.70, 0.00, 15.75},{12.51, 0.00, 15.13},{13.87, 0.00, 13.84},{14.72, 0.00, 11.91},{14.98, 0.00, 9.43},{14.62, 0.00, 6.52},{13.62, 0.00, 3.32},{12.00, 0.00, 0.00},{9.82, 0.00, -3.26},{7.17, 0.00, -6.29},{4.17, 0.00, -8.96},{0.97, 0.00, -11.15},{-2.28, 0.00, -12.78},{-5.43, 0.00, -13.83},{-8.33, 0.00, -14.28},{-10.87, 0.00, -14.18},{-12.96, 0.00, -13.56},{-14.51, 0.00, -12.50},{-15.50, 0.00, -11.04},{-15.89, 0.00, -9.27},{-15.71, 0.00, -7.22},{-14.96, 0.00, -4.96},{-13.71, 0.00, -2.54},},
  {{-12.00, 0.00, 0.00},{-9.93, 0.00, 3.75},{-7.58, 0.00, 7.45},{-5.04, 0.00, 10.98},{-2.38, 0.00, 14.21},{0.33, 0.00, 17.01},{3.02, 0.00, 19.26},{5.62, 0.00, 20.82},{8.06, 0.00, 21.61},{10.25, 0.00, 21.54},{12.11, 0.00, 20.59},{13.55, 0.00, 18.75},{14.48, 0.00, 16.09},{14.84, 0.00, 12.72},{14.55, 0.00, 8.78},{13.60, 0.00, 4.47},{12.00, 0.00, 0.00},{9.80, 0.00, -4.41},{7.10, 0.00, -8.56},{4.03, 0.00, -12.25},{0.74, 0.00, -15.33},{-2.60, 0.00, -17.69},{-5.82, 0.00, -19.28},{-8.78, 0.00, -20.07},{-11.34, 0.00, -20.08},{-13.41, 0.00, -19.35},{-14.91, 0.00, -17.95},{-15.82, 0.00, -15.96},{-16.13, 0.00, -13.45},{-15.85, 0.00, -10.51},{-15.03, 0.00, -7.23},{-13.73, 0.00, -3.69},},
  {{-12.00, 0.00, 0.00},{-9.91, 0.00, 2.60},{-7.51, 0.00, 5.18},{-4.90, 0.00, 7.69},{-2.15, 0.00, 10.03},{0.65, 0.00, 12.10},{3.42, 0.00, 13.80},{6.07, 0.00, 15.03},{8.52, 0.00, 15.71},{10.70, 0.00, 15.75},{12.51, 0.00, 15.13},{13.87, 0.00, 13.84},{14.72, 0.00, 11.91},{14.98, 0.00, 9.43},{14.62, 0.00, 6.52},{13.62, 0.00, 3.32},{12.00, 0.00, 0.00},{9.82, 0.00, -3.26},{7.17, 0.00, -6.29},{4.17, 0.00, -8.96},{0.97, 0.00, -11.15},{-2.28, 0.00, -12.78},{-5.43, 0.00, -13.83},{-8.33, 0.00, -14.28},{-10.87, 0.00, -14.18},{-12.96, 0.00, -13.56},{-14.51, 0.00, -12.50},{-15.50, 0.00, -11.04},{-15.89, 0.00, -9.27},{-15.71, 0.00, -7.22},{-14.96, 0.00, -4.96},{-13.71, 0.00, -2.54},},
  {{-12.00, 0.00, 0.00},{-9.82, 0.00, -3.26},{-7.17, 0.00, -6.29},{-4.17, 0.00, -8.96},{-0.97, 0.00, -11.15},{2.28, 0.00, -12.78},{5.43, 0.00, -13.83},{8.33, 0.00, -14.28},{10.87, 0.00, -14.18},{12.96, 0.00, -13.56},{14.51, 0.00, -12.50},{15.50, 0.00, -11.04},{15.89, 0.00, -9.27},{15.71, 0.00, -7.22},{14.96, 0.00, -4.96},{13.71, 0.00, -2.54},{12.00, 0.00, 0.00},{9.91, 0.00, 2.60},{7.51, 0.00, 5.18},{4.90, 0.00, 7.69},{2.15, 0.00, 10.03},{-0.65, 0.00, 12.10},{-3.42, 0.00, 13.80},{-6.07, 0.00, 15.03},{-8.52, 0.00, 15.71},{-10.70, 0.00, 15.75},{-12.51, 0.00, 15.13},{-13.87, 0.00, 13.84},{-14.72, 0.00, 11.91},{-14.98, 0.00, 9.43},{-14.62, 0.00, 6.52},{-13.62, 0.00, 3.32},},
  {{-12.00, 0.00, 0.00},{-9.80, 0.00, -4.41},{-7.10, 0.00, -8.56},{-4.03, 0.00, -12.25},{-0.74, 0.00, -15.33},{2.60, 0.00, -17.69},{5.82, 0.00, -19.28},{8.78, 0.00, -20.07},{11.34, 0.00, -20.08},{13.41, 0.00, -19.35},{14.91, 0.00, -17.95},{15.82, 0.00, -15.96},{16.13, 0.00, -13.45},{15.85, 0.00, -10.51},{15.03, 0.00, -7.23},{13.73, 0.00, -3.69},{12.00, 0.00, 0.00},{9.93, 0.00, 3.75},{7.58, 0.00, 7.45},{5.04, 0.00, 10.98},{2.38, 0.00, 14.21},{-0.33, 0.00, 17.01},{-3.02, 0.00, 19.26},{-5.62, 0.00, 20.82},{-8.06, 0.00, 21.61},{-10.25, 0.00, 21.54},{-12.11, 0.00, 20.59},{-13.55, 0.00, 18.75},{-14.48, 0.00, 16.09},{-14.84, 0.00, 12.72},{-14.55, 0.00, 8.78},{-13.60, 0.00, 4.47},},
  {{-12.00, 0.00, 0.00},{-9.82, 0.00, -3.26},{-7.17, 0.00, -6.29},{-4.17, 0.00, -8.96},{-0.97, 0.00, -11.15},{2.28, 0.00, -12.78},{5.43, 0.00, -13.83},{8.33, 0.00, -14.28},{10.87, 0.00, -14.18},{12.96, 0.00, -13.56},{14.51, 0.00, -12.50},{15.50, 0.00, -11.04},{15.89, 0.00, -9.27},{15.71, 0.00, -7.22},{14.96, 0.00, -4.96},{13.71, 0.00, -2.54},{12.00, 0.00, 0.00},{9.91, 0.00, 2.60},{7.51, 0.00, 5.18},{4.90, 0.00, 7.69},{2.15, 0.00, 10.03},{-0.65, 0.00, 12.10},{-3.42, 0.00, 13.80},{-6.07, 0.00, 15.03},{-8.52, 0.00, 15.71},{-10.70, 0.00, 15.75},{-12.51, 0.00, 15.13},{-13.87, 0.00, 13.84},{-14.72, 0.00, 11.91},{-14.98, 0.00, 9.43},{-14.62, 0.00, 6.52},{-13.62, 0.00, 3.32},},
};

// Rotate by Z axis
const int danceTable3[6][36][3] PROGMEM = {
  {{0.00, 8.86, 22.74},{-1.92, 9.24, 19.56},{-3.87, 9.35, 15.81},{-5.77, 9.12, 11.61},{-7.54, 8.52, 7.07},{-9.12, 7.52, 2.34},{-10.42, 6.12, -2.45},{-11.40, 4.36, -7.14},{-12.01, 2.29, -11.58},{-12.22, 0.00, -15.64},{-12.01, -2.40, -19.19},{-11.40, -4.80, -22.12},{-10.42, -7.07, -24.33},{-9.12, -9.09, -25.77},{-7.54, -10.76, -26.39},{-5.77, -11.98, -26.19},{-3.87, -12.72, -25.18},{-1.92, -12.94, -23.38},{0.00, -12.67, -20.85},{1.83, -11.95, -17.67},{3.53, -10.86, -13.93},{5.04, -9.48, -9.73},{6.34, -7.91, -5.19},{7.41, -6.24, -0.46},{8.25, -4.57, 4.33},{8.84, -2.94, 9.02},{9.20, -1.41, 13.47},{9.32, 0.00, 17.53},{9.20, 1.30, 21.08},{8.84, 2.50, 24.00},{8.25, 3.61, 26.21},{7.41, 4.66, 27.64},{6.34, 5.67, 28.27},{5.04, 6.62, 28.07},{3.53, 7.49, 27.06},{1.83, 8.25, 25.26},},
  {{0.00, 10.77, 0.94},{-1.94, 11.29, -3.04},{-3.94, 11.40, -6.90},{-5.91, 11.05, -10.54},{-7.78, 10.20, -13.84},{-9.45, 8.87, -16.71},{-10.85, 7.09, -19.05},{-11.91, 4.95, -20.78},{-12.57, 2.54, -21.84},{-12.79, 0.00, -22.20},{-12.57, -2.54, -21.84},{-11.91, -4.95, -20.78},{-10.85, -7.09, -19.05},{-9.45, -8.87, -16.71},{-7.78, -10.20, -13.84},{-5.91, -11.05, -10.54},{-3.94, -11.40, -6.90},{-1.94, -11.29, -3.04},{0.00, -10.77, 0.94},{1.82, -9.91, 4.92},{3.46, -8.81, 8.78},{4.90, -7.55, 12.42},{6.10, -6.22, 15.72},{7.08, -4.89, 18.59},{7.82, -3.59, 20.93},{8.33, -2.35, 22.66},{8.64, -1.16, 23.72},{8.74, -0.00, 24.08},{8.64, 1.16, 23.72},{8.33, 2.35, 22.66},{7.82, 3.59, 20.93},{7.08, 4.89, 18.59},{6.10, 6.22, 15.72},{4.90, 7.55, 12.42},{3.46, 8.81, 8.78},{1.82, 9.91, 4.92},},
  {{0.00, 12.67, -20.85},{-1.92, 12.94, -23.38},{-3.87, 12.72, -25.18},{-5.77, 11.98, -26.19},{-7.54, 10.76, -26.39},{-9.12, 9.09, -25.77},{-10.42, 7.07, -24.33},{-11.40, 4.80, -22.12},{-12.01, 2.40, -19.19},{-12.22, 0.00, -15.64},{-12.01, -2.29, -11.58},{-11.40, -4.36, -7.14},{-10.42, -6.12, -2.45},{-9.12, -7.52, 2.34},{-7.54, -8.52, 7.07},{-5.77, -9.12, 11.61},{-3.87, -9.35, 15.81},{-1.92, -9.24, 19.56},{0.00, -8.86, 22.74},{1.83, -8.25, 25.26},{3.53, -7.49, 27.06},{5.04, -6.62, 28.07},{6.34, -5.67, 28.27},{7.41, -4.66, 27.64},{8.25, -3.61, 26.21},{8.84, -2.50, 24.00},{9.20, -1.30, 21.08},{9.32, 0.00, 17.53},{9.20, 1.41, 13.47},{8.84, 2.94, 9.02},{8.25, 4.57, 4.33},{7.41, 6.24, -0.46},{6.34, 7.91, -5.19},{5.04, 9.48, -9.73},{3.53, 10.86, -13.93},{1.83, 11.95, -17.67},},
  {{0.00, 12.67, -20.85},{-1.83, 11.95, -17.67},{-3.53, 10.86, -13.93},{-5.04, 9.48, -9.73},{-6.34, 7.91, -5.19},{-7.41, 6.24, -0.46},{-8.25, 4.57, 4.33},{-8.84, 2.94, 9.02},{-9.20, 1.41, 13.47},{-9.32, 0.00, 17.53},{-9.20, -1.30, 21.08},{-8.84, -2.50, 24.00},{-8.25, -3.61, 26.21},{-7.41, -4.66, 27.64},{-6.34, -5.67, 28.27},{-5.04, -6.62, 28.07},{-3.53, -7.49, 27.06},{-1.83, -8.25, 25.26},{0.00, -8.86, 22.74},{1.92, -9.24, 19.56},{3.87, -9.35, 15.81},{5.77, -9.12, 11.61},{7.54, -8.52, 7.07},{9.12, -7.52, 2.34},{10.42, -6.12, -2.45},{11.40, -4.36, -7.14},{12.01, -2.29, -11.58},{12.22, 0.00, -15.64},{12.01, 2.40, -19.19},{11.40, 4.80, -22.12},{10.42, 7.07, -24.33},{9.12, 9.09, -25.77},{7.54, 10.76, -26.39},{5.77, 11.98, -26.19},{3.87, 12.72, -25.18},{1.92, 12.94, -23.38},},
  {{0.00, 10.77, 0.94},{-1.82, 9.91, 4.92},{-3.46, 8.81, 8.78},{-4.90, 7.55, 12.42},{-6.10, 6.22, 15.72},{-7.08, 4.89, 18.59},{-7.82, 3.59, 20.93},{-8.33, 2.35, 22.66},{-8.64, 1.16, 23.72},{-8.74, 0.00, 24.08},{-8.64, -1.16, 23.72},{-8.33, -2.35, 22.66},{-7.82, -3.59, 20.93},{-7.08, -4.89, 18.59},{-6.10, -6.22, 15.72},{-4.90, -7.55, 12.42},{-3.46, -8.81, 8.78},{-1.82, -9.91, 4.92},{0.00, -10.77, 0.94},{1.94, -11.29, -3.04},{3.94, -11.40, -6.90},{5.91, -11.05, -10.54},{7.78, -10.20, -13.84},{9.45, -8.87, -16.71},{10.85, -7.09, -19.05},{11.91, -4.95, -20.78},{12.57, -2.54, -21.84},{12.79, -0.00, -22.20},{12.57, 2.54, -21.84},{11.91, 4.95, -20.78},{10.85, 7.09, -19.05},{9.45, 8.87, -16.71},{7.78, 10.20, -13.84},{5.91, 11.05, -10.54},{3.94, 11.40, -6.90},{1.94, 11.29, -3.04},},
  {{0.00, 8.86, 22.74},{-1.83, 8.25, 25.26},{-3.53, 7.49, 27.06},{-5.04, 6.62, 28.07},{-6.34, 5.67, 28.27},{-7.41, 4.66, 27.64},{-8.25, 3.61, 26.21},{-8.84, 2.50, 24.00},{-9.20, 1.30, 21.08},{-9.32, 0.00, 17.53},{-9.20, -1.41, 13.47},{-8.84, -2.94, 9.02},{-8.25, -4.57, 4.33},{-7.41, -6.24, -0.46},{-6.34, -7.91, -5.19},{-5.04, -9.48, -9.73},{-3.53, -10.86, -13.93},{-1.83, -11.95, -17.67},{0.00, -12.67, -20.85},{1.92, -12.94, -23.38},{3.87, -12.72, -25.18},{5.77, -11.98, -26.19},{7.54, -10.76, -26.39},{9.12, -9.09, -25.77},{10.42, -7.07, -24.33},{11.40, -4.80, -22.12},{12.01, -2.40, -19.19},{12.22, 0.00, -15.64},{12.01, 2.29, -11.58},{11.40, 4.36, -7.14},{10.42, 6.12, -2.45},{9.12, 7.52, 2.34},{7.54, 8.52, 7.07},{5.77, 9.12, 11.61},{3.87, 9.35, 15.81},{1.92, 9.24, 19.56},},
};

const int turnTable[6][30][3] PROGMEM = {
  {{20.35, -18.49, 0.00},{16.54, -14.52, 4.00},{12.60, -10.67, 8.00},{8.52, -6.97, 12.00},{4.32, -3.41, 16.00},{0.00, 0.00, 19.00},{-4.44, 3.26, 16.00},{-8.99, 6.36, 12.00},{-13.64, 9.30, 8.00},{-18.40, 12.07, 4.00},{-23.25, 14.68, 0.00},{-18.40, 12.07, 0.00},{-13.64, 9.30, 0.00},{-8.99, 6.36, 0.00},{-4.44, 3.26, 0.00},{0.00, 0.00, 0.00},{4.32, -3.41, 0.00},{8.52, -6.97, 0.00},{12.60, -10.67, 0.00},{16.54, -14.52, 0.00},{20.35, -18.49, 0.00},{16.54, -14.52, 4.00},{12.60, -10.67, 8.00},{8.52, -6.97, 12.00},{4.32, -3.41, 16.00},{0.00, 0.00, 19.00},{-4.44, 3.26, 16.00},{-8.99, 6.36, 12.00},{-13.64, 9.30, 8.00},{-18.40, 12.07, 4.00}},
  {{-2.02, -23.14, 0.00},{-1.30, -18.54, 4.00},{-0.73, -13.93, 8.00},{-0.32, -9.30, 12.00},{-0.08, -4.65, 16.00},{0.00, 0.00, 19.00},{-0.08, 4.65, 16.00},{-0.32, 9.30, 12.00},{-0.73, 13.93, 8.00},{-1.30, 18.54, 4.00},{-2.02, 23.14, 0.00},{-1.30, 18.54, 0.00},{-0.73, 13.93, 0.00},{-0.32, 9.30, 0.00},{-0.08, 4.65, 0.00},{0.00, 0.00, 0.00},{-0.08, -4.65, 0.00},{-0.32, -9.30, 0.00},{-0.73, -13.93, 0.00},{-1.30, -18.54, 0.00},{-2.02, -23.14, 0.00},{-1.30, -18.54, 4.00},{-0.73, -13.93, 8.00},{-0.32, -9.30, 12.00},{-0.08, -4.65, 16.00},{0.00, 0.00, 19.00},{-0.08, 4.65, 16.00},{-0.32, 9.30, 12.00},{-0.73, 13.93, 8.00},{-1.30, 18.54, 4.00}},
  {{-23.25, -14.68, 0.00},{-18.40, -12.07, 4.00},{-13.64, -9.30, 8.00},{-8.99, -6.36, 12.00},{-4.44, -3.26, 16.00},{0.00, 0.00, 19.00},{4.32, 3.41, 16.00},{8.52, 6.97, 12.00},{12.60, 10.67, 8.00},{16.54, 14.52, 4.00},{20.35, 18.49, 0.00},{16.54, 14.52, 0.00},{12.60, 10.67, 0.00},{8.52, 6.97, 0.00},{4.32, 3.41, 0.00},{0.00, 0.00, 0.00},{-4.44, -3.26, 0.00},{-8.99, -6.36, 0.00},{-13.64, -9.30, 0.00},{-18.40, -12.07, 0.00},{-23.25, -14.68, 0.00},{-18.40, -12.07, 4.00},{-13.64, -9.30, 8.00},{-8.99, -6.36, 12.00},{-4.44, -3.26, 16.00},{0.00, 0.00, 19.00},{4.32, 3.41, 16.00},{8.52, 6.97, 12.00},{12.60, 10.67, 8.00},{16.54, 14.52, 4.00}},
  {{-20.35, 18.49, 0.00},{-16.54, 14.52, 4.00},{-12.60, 10.67, 8.00},{-8.52, 6.97, 12.00},{-4.32, 3.41, 16.00},{0.00, 0.00, 19.00},{4.44, -3.26, 16.00},{8.99, -6.36, 12.00},{13.64, -9.30, 8.00},{18.40, -12.07, 4.00},{23.25, -14.68, 0.00},{18.40, -12.07, 0.00},{13.64, -9.30, 0.00},{8.99, -6.36, 0.00},{4.44, -3.26, 0.00},{0.00, 0.00, 0.00},{-4.32, 3.41, 0.00},{-8.52, 6.97, 0.00},{-12.60, 10.67, 0.00},{-16.54, 14.52, 0.00},{-20.35, 18.49, 0.00},{-16.54, 14.52, 4.00},{-12.60, 10.67, 8.00},{-8.52, 6.97, 12.00},{-4.32, 3.41, 16.00},{0.00, 0.00, 19.00},{4.44, -3.26, 16.00},{8.99, -6.36, 12.00},{13.64, -9.30, 8.00},{18.40, -12.07, 4.00}},
  {{2.02, 23.14, 0.00},{1.30, 18.54, 4.00},{0.73, 13.93, 8.00},{0.32, 9.30, 12.00},{0.08, 4.65, 16.00},{0.00, 0.00, 19.00},{0.08, -4.65, 16.00},{0.32, -9.30, 12.00},{0.73, -13.93, 8.00},{1.30, -18.54, 4.00},{2.02, -23.14, 0.00},{1.30, -18.54, 0.00},{0.73, -13.93, 0.00},{0.32, -9.30, 0.00},{0.08, -4.65, 0.00},{0.00, 0.00, 0.00},{0.08, 4.65, 0.00},{0.32, 9.30, 0.00},{0.73, 13.93, 0.00},{1.30, 18.54, 0.00},{2.02, 23.14, 0.00},{1.30, 18.54, 4.00},{0.73, 13.93, 8.00},{0.32, 9.30, 12.00},{0.08, 4.65, 16.00},{0.00, 0.00, 19.00},{0.08, -4.65, 16.00},{0.32, -9.30, 12.00},{0.73, -13.93, 8.00},{1.30, -18.54, 4.00}},
  {{23.25, 14.68, 0.00},{18.40, 12.07, 4.00},{13.64, 9.30, 8.00},{8.99, 6.36, 12.00},{4.44, 3.26, 16.00},{0.00, 0.00, 19.00},{-4.32, -3.41, 16.00},{-8.52, -6.97, 12.00},{-12.60, -10.67, 8.00},{-16.54, -14.52, 4.00},{-20.35, -18.49, 0.00},{-16.54, -14.52, 0.00},{-12.60, -10.67, 0.00},{-8.52, -6.97, 0.00},{-4.32, -3.41, 0.00},{0.00, 0.00, 0.00},{4.44, 3.26, 0.00},{8.99, 6.36, 0.00},{13.64, 9.30, 0.00},{18.40, 12.07, 0.00},{23.25, 14.68, 0.00},{18.40, 12.07, 4.00},{13.64, 9.30, 8.00},{8.99, 6.36, 12.00},{4.44, 3.26, 16.00},{0.00, 0.00, 19.00},{-4.32, -3.41, 16.00},{-8.52, -6.97, 12.00},{-12.60, -10.67, 8.00},{-16.54, -14.52, 4.00}},
};







// return angles 0, 1, 2 of specified "leg" for its tip to reach specified "location"
// return null if impossible
long loc2angles(int leg, int loc0,int loc1,int loc2)
{
//      Serial.print("\n \n \n \n");
if (leg >= 3) {
  loc0=loc0*-1;
  loc1=loc1*-1;
 // loc2=loc2*-1; 
}
 
  //Serial.print("leg="),Serial.println(leg);
  //Serial.print("loc0="),Serial.println(loc0);
  //Serial.print("loc1="),Serial.println(loc1);
  //Serial.print("loc2="),Serial.println(loc2); 
  // shift origin to leg center
  x = loc0 - legCenters[leg][0]+legTipsDefault[leg][0];
  //Serial.print("x="),Serial.println(x);
  y = loc1 - legCenters[leg][1]+legTipsDefault[leg][1];
  //Serial.print("y="),Serial.println(y);
  z = loc2 - legCenters[leg][2]+legTipsDefault[leg][2];
  //Serial.print("z="),Serial.println(z);
  //Serial.print("LegAngle="),Serial.println(legAngles[leg]);
  
  a0 = (180/M_PI)* atan(y/x) - legAngles[leg];
  if(x<0)
    a0 += 180;
  else if(y<0)
    a0 += 360;
  if(a0 > 180)
    a0 -= 360;

  xp = sqrt(x*x+y*y)-c;
  yp = z;

  lr = sqrt(xp*xp+yp*yp);
  ar = (180/M_PI)*asin(yp/lr);
  at = (180/M_PI)*acos((lr*lr + a*a - b*b)/(2*a*lr));
  az = (180/M_PI)*acos((lr*lr - a*a + b*b)/(2*b*lr));
  a1 = at + ar;
  a2 = 180 - at - az;
  

  //Serial.print("a0="),Serial.println(a0);
  //Serial.print("a1="),Serial.println(a1);
  //Serial.print("a2="),Serial.println(a2);
 
  return a0, a1, a2;

}

// nonblockingly move tip of specified "leg" to specified "location"
// return true if ok
// return false if impossible
long moveLeg(int leg,int loc0,int loc1,int loc2)
{
  a = loc2angles(leg, loc0, loc1, loc2);

  if(a0 <= 45 && a0 >= -45 &&
      a1 <= 90 && a1 >= -90 &&
      a2 <= 150 && a2 >= 36)
  {

     if (dir==false) {
      a0=a0*-1;
     }
      
     if (leg<=2) {
      pwm.writeMicroseconds(3*leg, ms[leg][0] + a0 * 500 / 45);
      pwm.writeMicroseconds(3*leg+1, ms[leg][1] - a1 * 500 / 45);
      pwm.writeMicroseconds(3*leg+2, ms[leg][2] + (a2-90) * 500 / 45);
    }
    else if (leg>=3 && leg<=4) {
      pwm.writeMicroseconds(3*leg, ms[leg][0] - a0 * 500 / 45);
      pwm.writeMicroseconds(3*leg+1, ms[leg][1] + a1 * 500 / 45);
      pwm.writeMicroseconds(3*leg+2, ms[leg][2] - (a2-90) * 500 / 45);
    }
    else  {
      pwm.writeMicroseconds(15, ms[5][0] - a0 * 500 / 45);
      myservo16.writeMicroseconds(ms[5][1] + a1 * 500 / 45);   
      myservo17.writeMicroseconds(ms[5][2] - (a2-90) * 500 / 45); 
      }
    //Serial.print("leg="),Serial.println(leg);
    //Serial.print("a0="),Serial.println(a0);
    //Serial.print("ms0="),Serial.println(ms[leg][0] + a0 * 500 / 45 );
    //Serial.print("motor="),Serial.println(1*leg);
    //Serial.print("a1="),Serial.println(a1);
    //Serial.print("ms1="),Serial.println(ms[leg][1] - a1 * 500 / 45 );
    //Serial.print("a2="),Serial.println(-a2);
    //Serial.print("ms2="),Serial.println(ms[leg][2] + (a2-90) * 500 / 45);
  }
}
void setup () {
  pwm.begin();
  MyBlue.begin(9600); 
  pwm.setPWMFreq(FREQUENCY);
  delay(2000);
  //Serial.begin(9600);
  myservo16.attach(8);  // attaches the servo on pin 9 to the servo object
  myservo17.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() { 
   if (MyBlue.available()){
   flag = MyBlue.read(); 
   }

if (flag==48){
  for (i=0; i<=5; i++){
    loc0=0, loc1=0, loc2=0;
    moveLeg(i,loc0, loc1, loc2);  
    delay(20);
  }
}
/*
if (flag==50){
//FWD
dir=true;
for (k = 0; k<=5; k++) {
  if (MyBlue.available()){
   flag = MyBlue.read(); 
   }
  if (flag==50){
  for (j = 0; j<=19; j++) {    
      for (i = 0; i <= 5;) {
        currentMillis = millis();
          if (currentMillis - StartMillis >= 10){
            StartMillis = currentMillis;
              if ((i % 2)==0) {
              loc0=fwdTable[j][0]; 
              loc1=fwdTable[j][1];
              loc2=fwdTable[j][2];
              moveLeg(i,loc0, loc1, loc2);  
              }
              else {
              loc0=fwdTable[j+10][0]; 
              loc1=fwdTable[j+10][1];
              loc2=fwdTable[j+10][2];
              moveLeg(i,loc0, loc1, loc2);
              }
              i=i+1;
            
              }
          }
      }
}
}
}
*/

if (flag==0){
//FWD ripple
dir=true;
for (k = 0; k<=5; k++) {
  if (MyBlue.available()){
   flag = MyBlue.read(); 
   }
  if (flag==0){
      for (i = 0; i <= 19;) {
        currentMillis = millis();
          if (currentMillis - StartMillis >= 60){
            
            StartMillis = currentMillis;
              loc0=fwdTable[i][0]; 
              loc1=fwdTable[i][1];
              loc2=fwdTable[i][2];
              moveLeg(2,loc0, loc1, loc2);  

              loc0=fwdTable[i+4][0]; 
              loc1=fwdTable[i+4][1];
              loc2=fwdTable[i+4][2];
              moveLeg(1,loc0, loc1, loc2);  

              loc0=fwdTable[i+8][0]; 
              loc1=fwdTable[i+8][1];
              loc2=fwdTable[i+8][2];
              moveLeg(0,loc0, loc1, loc2);  

              loc0=fwdTable[i+12][0]; 
              loc1=fwdTable[i+12][1];
              loc2=fwdTable[i+12][2];
              moveLeg(3,loc0, loc1, loc2);  

              loc0=fwdTable[i+16][0]; 
              loc1=fwdTable[i+16][1];
              loc2=fwdTable[i+16][2];
              moveLeg(4,loc0, loc1, loc2);  

              loc0=fwdTable[i+20][0]; 
              loc1=fwdTable[i+20][1];
              loc2=fwdTable[i+20][2];
              moveLeg(5,loc0, loc1, loc2);  
              
          
              i=i+1;
              }
          }
      }
}
}
















/*
if (flag==50){//50
//FWD wave
dir=true;
    for (k = 0; k<=5; k++) {
      if (MyBlue.available()){
       flag = MyBlue.read(); 
       }
      if (flag==50){
          for (j = 0; j<=5;j++) { 
            leg_num=wave_seq[j];
              for (i = 0; i <= 19;) {   
                currentMillis = millis();
                  if (currentMillis - StartMillis >= 300){
                    StartMillis = currentMillis;
                    
                      loc0=fwdTable[i][0]; 
                      loc1=fwdTable[i][1];
                      loc2=fwdTable[i][2];
                      moveLeg(leg_num, loc0, loc1, loc2);  
                      
                      i=i+1;        
                    }
              }    
        }
    }
    }
}
*/
if (flag==52){
//BWD
dir=false;
for (k = 0; k<=5; k++) {
  if (MyBlue.available()){
   flag = MyBlue.read(); 
   }
  if (flag==52){
  for (j = 0; j<=19; j++) {    
      for (i = 0; i <= 5;) {
        currentMillis = millis();
          if (currentMillis - StartMillis >= 10){
            StartMillis = currentMillis;
              if ((i % 2)==0) {
              loc0=fwdTable[j][0]; 
              loc1=fwdTable[j][1];
              loc2=fwdTable[j][2];
              moveLeg(i,loc0, loc1, loc2);  
              }
              else {
              loc0=fwdTable[j+10][0]; 
              loc1=fwdTable[j+10][1];
              loc2=fwdTable[j+10][2];
              moveLeg(i,loc0, loc1, loc2);
              }
              i=i+1;           
          }
          }
      }
}
}
}

if (flag==49){
//CCW
dir=true;
for (k = 0; k<=5; k++) {
  if (MyBlue.available()){
   flag = MyBlue.read(); 
   }
  if (flag==49){
  for (j = 0; j<=19  ;j++ ) {
    for (i = 0; i <=5 ;) {
        currentMillis = millis();
          if (currentMillis - StartMillis >= 10){
            StartMillis = currentMillis;
              if ((i % 2)==0) {
              loc0=pgm_read_word_near(&turnTable[i][j][0]);
              loc1=pgm_read_word_near(&turnTable[i][j][1]);
              loc2=pgm_read_word_near(&turnTable[i][j][2]);
              moveLeg(i,loc0, loc1, loc2);  
              }
              else {
              m=j+10;
              loc0=pgm_read_word_near(&turnTable[i][m][0]);
              loc1=pgm_read_word_near(&turnTable[i][m][1]);
              loc2=pgm_read_word_near(&turnTable[i][m][2]);
              moveLeg(i,loc0, loc1, loc2);
              }
            i++;
        } 
      }     
    }
  }
}
}

if (flag==51){
//CW
dir=false;
for (k = 0; k<=5; k++) {
  if (MyBlue.available()){
   flag = MyBlue.read(); 
   }
  if (flag==51){
  for (j = 0; j<=19  ;j++ ) {
    for (i = 0; i <=5 ;) {
        currentMillis = millis();
          if (currentMillis - StartMillis >= 10){
            StartMillis = currentMillis;
              if ((i % 2)==0) {
              loc0=pgm_read_word_near(&turnTable[i][j][0]);
              loc1=pgm_read_word_near(&turnTable[i][j][1]);
              loc2=pgm_read_word_near(&turnTable[i][j][2]);
              moveLeg(i,loc0, loc1, loc2);  
              }
              else {
              m=j+10;
              loc0=pgm_read_word_near(&turnTable[i][m][0]);
              loc1=pgm_read_word_near(&turnTable[i][m][1]);
              loc2=pgm_read_word_near(&turnTable[i][m][2]);
              moveLeg(i,loc0, loc1, loc2);
              }
            i++;
        } 
      }     
    }
  }
}
}

if (flag==55){
//DANCE 1
dir=true;
for (k = 0; k<=5; k++) {
  if (MyBlue.available()){
   flag = MyBlue.read(); 
   }
  if (flag==55){
  for (j = 0; j<=31  ; j++) {
    for (i = 0; i <= 5;) { 
        currentMillis = millis();
          if (currentMillis - StartMillis >= 10){   //3.33
                  StartMillis = currentMillis;
                  loc0=pgm_read_word_near(&danceTable1[i][j][0]);
                  loc1=pgm_read_word_near(&danceTable1[i][j][1]);
                  loc2=pgm_read_word_near(&danceTable1[i][j][2]);
                  moveLeg(i,loc0, loc1, loc2);
                  i=i+1;     
        } 
      }
    }
  }
}
}

if (flag==56){
//DANCE 2
for (k = 0; k<=5; k++) {
  if (MyBlue.available()){
   flag = MyBlue.read(); 
   }
  if (flag==56){
  for (j = 0; j<=31  ; j++) {
    for (i = 0; i <= 5;) { 
        currentMillis = millis();
          if (currentMillis - StartMillis >= 10){//3.33
                  StartMillis = currentMillis;
                  loc0=pgm_read_word_near(&danceTable2[i][j][0]);
                  loc1=pgm_read_word_near(&danceTable2[i][j][1]);
                  loc2=pgm_read_word_near(&danceTable2[i][j][2]);
                  moveLeg(i,loc0, loc1, loc2);
                  i=i+1;
        } 
      }
    }
  }
}
}

if (flag==57){
//DANCE 3
for (k = 0; k<=5; k++) {
  if (MyBlue.available()){
   flag = MyBlue.read(); 
   }
  if (flag==57){
  for (j = 0; j<=35  ; j++) {
    for (i = 0; i <= 5;) { 
        currentMillis = millis();
          if (currentMillis - StartMillis >= 10){ //3.33
                  StartMillis = currentMillis;
                  loc0=pgm_read_word_near(&danceTable3[i][j][0]);
                  loc1=pgm_read_word_near(&danceTable3[i][j][1]);
                  loc2=pgm_read_word_near(&danceTable3[i][j][2]);
                  moveLeg(i,loc0, loc1, loc2);
                  i=i+1;
        } 
      }
    }
  }
}
}
}