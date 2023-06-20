#include <Servo.h>

#define trigPin 2
#define echoPin 3
#define LEDlampRed 9
#define  LEDlampYellow 10
#define LEDlampGreen 11 
#define soundbuzzer 7
int sound  = 200;

Servo myServo;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow,  OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);

  myServo.attach(5);
}
void  loop() {
  for (int i=15;i<=165;i++) { 
    myServo.write(i);
    delay(30);
    calculateDistance();
  }

  for(int i=165;i>15;i--){ 
    myServo.write(i);
    delay(30);
    calculateDistance();
  }
}

void calculateDistance() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = durationindigit*0.034 / 2;
 
  if (distanceincm < 50) { digitalWrite(LEDlampGreen, HIGH);
  } else { digitalWrite(LEDlampGreen,  LOW); }
  
  if (distanceincm < 20) { digitalWrite(LEDlampYellow, HIGH);
  } else { digitalWrite(LEDlampYellow, LOW); }
  
  if (distanceincm  < 5) {
    digitalWrite(LEDlampRed, HIGH);
    tone(soundbuzzer, sound);
    delay(500);
    noTone(soundbuzzer);
  } else  { digitalWrite(LEDlampRed,LOW); }
 
  Serial.print(distanceincm);
  Serial.println("  cm");
    
  delay(100);
}
