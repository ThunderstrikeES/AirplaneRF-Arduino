
// RECEPTOR

#include <Servo.h> 
#include <SPI.h>
#include <RF24.h>

#define CE_PIN 7
#define CSN_PIN 8
#define pindata 53

const byte addresses[][6] = {"00001"}; 

RF24 radio(CE_PIN, CSN_PIN);

int datos[4];
int motor;
int servo1;
int servo2;
const int pos_0 = 130; // Posición inicial servos

Servo Motor;

Servo servo_1;
Servo servo_2;
Servo servo_3;

void setup()
{
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(1, addresses[0]);  
  radio.startListening();

Motor.attach(10);
Motor.writeMicroseconds(2000);

servo_1.attach(5);
servo_1.write(pos_0);

servo_2.attach(4);
servo_2.write(pos_0);

delay(1000);

digitalWrite(pindata, HIGH);
delay(100);
pinMode(pindata, OUTPUT);

}

void loop() {

radio.read(&datos,sizeof(datos));

  servo1=map(datos[0], 0, 180, 55, 125);
  servo2=map(datos[1], 0, 180, 55, 125);
  
  servo_1.write(servo1);
  servo_2.write(servo2);

  motor=map(datos[2], 0, 180, 50, 140);
  Motor.write(motor);

}
