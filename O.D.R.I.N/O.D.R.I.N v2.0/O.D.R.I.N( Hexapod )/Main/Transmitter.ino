#include <SPI.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = “00001”;
int joy[6];

void setup() {
radio.begin();
radio.openWritingPipe(address);
radio.setDataRate(RF24_2MBPS); // Set Data Rate
radio.setPALevel(RF24_PA_HIGH); // Set Power LVL
radio.setChannel(0x4C); // Set Channel
pinMode(4, INPUT_PULLUP); // Left stick button
pinMode(5, INPUT_PULLUP); // Right stick button
// Serial.begin(9600); // For Testing
}

void loop() {

radio.stopListening();
joy[0] = analogRead(A0); // Right Stick Up-Down UP=0
joy[1] = analogRead(A1); // Right Stick Left-Right RIGHT=0
joy[2] = analogRead(A2); // Left Stick Up-Down UP=0
joy[3] = analogRead(A3); // Left Stick Left-Right RIGHT=0
joy[4] = digitalRead(4); // Left Push Button PUSHED=0
joy[5] = digitalRead(5); // Right Push Button PUSHED=0
/* // For Testing
Serial.print(“A0 = “);
Serial.println(joy[0]);
Serial.print(“A1 = “);
Serial.println(joy[1]);
Serial.print(“A2 = “);
Serial.println(joy[2]);
Serial.print(“A3 = “);
Serial.println(joy[3]);
Serial.print(“LB = “);
Serial.println(joy[4]);
Serial.print(“RB = “);
Serial.println(joy[5]);
Serial.println(“———————“);
delay(1000);
*/
joy[0] = map(joy[0], 0, 1023, 255, 0);
joy[1] = map(joy[1], 0, 1023, 255, 0);
joy[2] = map(joy[2], 0, 1023, 255, 0);
joy[3] = map(joy[3], 0, 1023, 255, 0);
/* // For Testing
Serial.print(“A0 = “);
Serial.println(joy[0]);
Serial.print(“A1 = “);
Serial.println(joy[1]);
Serial.print(“A2 = “);
Serial.println(joy[2]);
Serial.print(“A3 = “);
Serial.println(joy[3]);
Serial.print(“LB = “);
Serial.println(joy[4]);
Serial.print(“RB = “);
Serial.println(joy[5]);
Serial.println(“———————“);
delay(1000);
*/
radio.write(&joy, sizeof(joy));
delay(20);
}
