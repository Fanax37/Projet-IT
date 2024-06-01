#include <Wire.h>
#include <rgb_lcd.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include "AFMotor.h"
#if defined(ARDUINO_ARCH_AVR)
#define SERIAL Serial
SoftwareSerial mySerial(2,3);
#define TRANS_SERIAL  mySerial
#elif defined(ARDUINO_ARCH_SAMD)
#define <SERIAL SerialUSB>
#define <TRANS_SERIAL  Serial>
#else

#endif
//roue devant 1 = gauche 2 = droite
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
//roues derrière 3 = gauche 4 = droite
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//RX=2,TX=3(D2) Software Serial Port

rgb_lcd lcd;
Servo servo;
int ligneGauche = 7;
int ligneDroite = 8;

int CapteurChambre = 9;

int speakerPin = 2; // pin a changer


const int colorR = 255;
const int colorG = 215;
const int colorB = 0;


bool waitForValidation = false;
char roomNumber = -1; 

const int triggerPin = 4; 
const int echoPin    = 5; 

int i = 0;
int z = 0;

long duration, distance;
void setup() {

   lcd.begin(16, 2);
   lcd.setRGB(colorR, colorG, colorB);
   servo.attach(7); // pin a changer 

   lcd.setCursor(0, 0);

   lcd.display();
   pinMode (speakerPin, OUTPUT);
   pinMode (CapteurChambre, INPUT);
   pinMode(ligneDroite,INPUT);  
   pinMode(ligneGauche,INPUT);
  
   
   Serial.begin (9600);
   
   TRANS_SERIAL.begin(9600); 
   SERIAL.begin(9600);  // start serial for output
   SERIAL.println(roomNumber);

   motor1.setSpeed(255);
   motor1.run(RELEASE);
   motor2.setSpeed(255);
   motor2.run(RELEASE);
   motor3.setSpeed(255);
   motor3.run(RELEASE);
   motor4.setSpeed(255);
   motor4.run(RELEASE);

   Serial.println("== Debut du programme ==");

}

void loop() {
  
  printData();
  if (waitForValidation == true) {
    delay (5000);
    lcd.clear();
  }else{
    obstacle();
  }
  servo.write(0);
  detectionChambre(i,z);
  int val = digitalRead(CapteurChambre);
  if (val==LOW){
    z = z + 1;
  }
  
}
