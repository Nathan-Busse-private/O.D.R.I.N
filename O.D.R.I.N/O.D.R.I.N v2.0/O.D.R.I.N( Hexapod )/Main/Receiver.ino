#include <SPI.h>
#include<RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
#define led1 3
#define led2 5
#define led3 6
#define led4 9
int val[4];

void setup() {
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
radio.begin();
radio.openReadingPipe(0, address);
radio.setDataRate(RF24_2MBPS);
radio.setPALevel(RF24_PA_HIGH);
radio.setChannel(0x4C);
radio.startListening();
}

void loop() {

delay(5);
radio.startListening();
while (!radio.available());
radio.read(&val, sizeof(val));
analogWrite(led1, val[0]);
analogWrite(led2, val[1]);
analogWrite(led3, val[2]);
analogWrite(led4, val[3]);

}
