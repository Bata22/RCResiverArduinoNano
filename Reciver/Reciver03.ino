#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

 

Servo myServo;
Servo esc;

RF24 radio(7, 8); // CE, CSN


const byte address[6] = "00001";
int joys[2];

void setup() {
 // pinMode(4, OUTPUT);
 myServo.attach(9);
   esc.attach(4, 1000, 2000);
   esc.write(0);
  // myServo.write(90);
   delay(2000);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
 // myServo.attach(9); //command pin of the steering servo is connected to pin 9
//  esc.attach(3); //Specify the esc signal pin,Here as 3
//  esc.writeMicroseconds(1000); //initialize the signal to 1000
  radio.startListening();
}

void loop() {

//  delay(5);
//   while (!radio.available());
  
  if (radio.available()) {

     
      radio.read(&joys ,sizeof(joys));
        Move();
     

  }



  
}

void Move()
{
   myServo.write(joys[0]);
    esc.write(joys[1]);

  }

   
