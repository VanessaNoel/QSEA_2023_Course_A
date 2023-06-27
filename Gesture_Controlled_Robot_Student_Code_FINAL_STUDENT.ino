#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h" 

//Setting up DC motors by assigning pins:
int motor1Out1 = 2;
int motor1Out2 = 3;

int motor2Out3 = 4;
int motor2Out4 = 5;

//MPU6050 (accelerometer/gyro sensor) setup:
MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
};

MyData data;

//Setting up the maximum and minimum values for X and Y:
int yMin = ;//For forwards
int yMax = ; //For backwards
//
//int xMin = ; //For right
//int xMax = ; //For left

void setup() {
  // put your setup code here, to run once:

  //starting the serial monitor, just incase we need to debug:
  Serial.begin(9600);

  //MPU6050 initilization:
  mpu.initialize();

  //Setting the DC motor pin modes to OUTPUT:
  //motor1Out1
  pinMode(motor1Out1, OUTPUT);
  //motor1Out2
  pinMode(motor1Out2, OUTPUT);
  //motor2Out3
  pinMode(motor2Out3, OUTPUT);
  //motor2Out4
  pinMode(motor2Out4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Getting the motion data from the MPU6050:
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255 ); // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255);  // Y axis data

  //Printing the data in the X and Y to see what the ranges should be:
  Serial.print("Y value: ");
  Serial.println(data.Y);
  delay(100);
  
  //Serial.print("X value: ");
  //Serial.println(data.X);
  //delay(100);

  //If the Y value is less than yMin, move the motors forward:
//  if(data.Y < yMin) {
//    Serial.println(data.Y);
//    Serial.println("Forward");
//
//    //Add either HIGH or LOW, depending on which direction you want the motors to rotate:
//    digitalWrite(motor1Out1, );
//    digitalWrite(motor1Out2, );
//
//    digitalWrite(motor2Out3, );
//    digitalWrite(motor2Out4, );
//
//}

  //If the Y value is more than yMax, move the motors backward:
//  if(data.Y > yMax) {
//    Serial.println(data.Y);
//    Serial.println("Backward");
//
//    //Add either HIGH or LOW, depending on which direction you want the motors to rotate:
//    digitalWrite(motor1Out1, );
//    digitalWrite(motor1Out2, );
//
//    digitalWrite(motor2Out3, );
//    digitalWrite(motor2Out4, );
//}

  //If the X value is more than xMax, move the car left:
//  if(data.X > xMax){
//    Serial.println(data.X);
//    Serial.println("Left");
//
//    //Add either HIGH or LOW, depending on which direction you want the motors to rotate:
//    digitalWrite(motor1Out1, );
//    digitalWrite(motor1Out2, );
//
//    digitalWrite(motor2Out3, );
//    digitalWrite(motor2Out4, );
//    
//}

  //If the X value is less than xMin, move the car right:
//  if(data.X < xMin){
//    Serial.println(data.X);
//    Serial.println("Right");
//
//    //Add either HIGH or LOW, depending on which direction you want the motors to rotate:
//    digitalWrite(motor1Out1, );
//    digitalWrite(motor1Out2, );
//
//    digitalWrite(motor2Out3, );
//    digitalWrite(motor2Out4, );
//    
//}

//Finding the X and Y data ranges when the sensor is laying flat:
//  if((data.Y < yMax) && (data.Y > yMin) && (data.X < xMax) && (data.X > xMin)){
//   Serial.println("Flat");
//
//    //Add either HIGH or LOW, depending on which direction you want the motors to rotate:
//   digitalWrite(motor1Out1, );
//   digitalWrite(motor1Out2, );
//
//   digitalWrite(motor2Out3, );
//   digitalWrite(motor2Out4, );
//}

}
