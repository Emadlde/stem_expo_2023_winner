#include <MPU6050_light.h>
#include <Wire.h>
#include <AFMotor.h>
unsigned long timer = 0;
int n=0;
int i=0;
int zead=0;
int speed1=43;
int speed2=53;
MPU6050 mpu(Wire);
float angle= 0;
 
AF_DCMotor M1(1);
AF_DCMotor M2(2);
 
const int trigpin=A2;
const int echopin =A0;
long duration;
int distance = 100;
void angle1()
{
  mpu.update();
 
}
 
 
void backward(){
  M2.run(BACKWARD);
  M1.run(BACKWARD);
}
 
void forward1(){
 angle1();
if (angle>1){
M1.setSpeed(speed1);
M2.setSpeed(speed2);
  }
  else if (angle<-1){
M1.setSpeed(speed2);
M2.setSpeed(speed1);
  }
else {
M1.setSpeed(speed2);
M2.setSpeed(speed2);
}
  M2.run(FORWARD);
  M1.run(FORWARD);
}
 
 
 
void forward2(){
 angle1();
if (angle>81){
M1.setSpeed(speed1);
M2.setSpeed(speed2);
  }
  else if (angle<79){
M1.setSpeed(speed2);
M2.setSpeed(speed1);
  }
else {
M1.setSpeed(speed2);
M2.setSpeed(speed2);
}
  M2.run(FORWARD);
  M1.run(FORWARD);
}
 
 
void forward3(){
 
 angle1();
if (angle<179){
M1.setSpeed(speed2);
M2.setSpeed(speed1);
  }
  else if (angle>181){
M1.setSpeed(speed1);
M2.setSpeed(speed2);
  }
else {
M1.setSpeed(speed2);
M2.setSpeed(speed2);
}
  M2.run(FORWARD);
  M1.run(FORWARD);
}
 
 
 
void forward4(){
 
 angle1();
if (angle<269){
M1.setSpeed(speed2);
M2.setSpeed(speed1);
  }
  else if (angle>271){
M1.setSpeed(speed1);
M2.setSpeed(speed2);
  }
else {
M1.setSpeed(speed2);
M2.setSpeed(speed2);
}
  M2.run(FORWARD);
  M1.run(FORWARD);
}
 
 
 
void turnright(){
   angle1();
  M1.setSpeed(60);  
  M2.setSpeed(0);
  M1.run(FORWARD);
  M2.run(BACKWARD);
}
 
void forward5(){
 angle1();
if (angle>181){
M1.setSpeed(speed1);
M2.setSpeed(speed2);
  }
  else if (angle<179){
M1.setSpeed(speed2);
M2.setSpeed(speed1);
  }
else {
M1.setSpeed(speed2);
M2.setSpeed(speed2);
}
  M2.run(FORWARD);
  M1.run(FORWARD);
}
 
 
 
 
void   turnleft()
{
  angle1();
  M2.setSpeed(90);
  M1.setSpeed(0);
  M1.run(BACKWARD);  
  M2.run(FORWARD);
}
 
void stop(){
  M1.run(RELEASE);
  M2.run(RELEASE);
}
 
 
void ultra(){
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration*0.034/2;
}
 
void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
  Wire.begin();
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
 
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
 
}
void loop() {
distance=12;
 
while(distance>11)
{
 if(i==0){
  speed1=100;
  speed2=110;
  forward1();
  delay(200);
  i++;
  speed1=43;
  speed2=53;
}
 
 if(i==1&&n==1){
  speed1=90;
  speed2=100;
  forward2();
  delay(150);
  i++;
  speed1=43;
  speed2=53;
}  
if(i==2&&n==2){
  speed1=120;
  speed2=130;
  forward3();
  delay(20);
  i++;
  speed1=43;
  speed2=53;
}  
if(i==3&&n==3){
  speed1=120;
  speed2=130;
  forward3();
  delay(10);
  i++;
  speed1=43;
  speed2=53;
}  
 if(i==4&&n==4){
  speed1=120;
  speed2=130;
  forward3();
  delay(170);
  i++;
  speed1=43;
  speed2=53;
}  
 
  ultra();
  delay(10);
  if (n==0){
  angle=mpu.getAngleZ();
  forward1();
  }
  if (n==1){
  angle=mpu.getAngleZ();
  forward2();
  }
  if (n==2){
     
  angle=mpu.getAngleZ();
  forward3();
  }
  if (n==3){
  angle=mpu.getAngleZ();
  forward4();
  }
  if (n==4){
  angle=mpu.getAngleZ();
  forward3();
  }
  if (n==5){
  angle=mpu.getAngleZ();
  forward2();
  }
  if (n==6){
  angle=mpu.getAngleZ();
  forward1();
  }
}
n++;
 
if(n==1){
  angle=0;
  while(angle<70){
    angle=mpu.getAngleZ();
    turnright();
  }
}
 
 else if (n==2){
  angle=90;
    while(angle<150){
      angle=mpu.getAngleZ();
      turnright();
    }
  }
  else if (n==3){
      angle=200;
  while(angle<230){
    angle=mpu.getAngleZ();
    turnright();
  }
  }
 
   else if (n==4)
  {
  angle=270;
  while(angle>210){
  angle=mpu.getAngleZ();
  turnleft();
  }
  }
 
  else if (n==5){
  angle=180;
  while(angle>110)
  {
  angle=mpu.getAngleZ();
  turnleft();
  }
  }
 
  else if (n==6){
  angle=270;
  while(angle>30){
    angle=mpu.getAngleZ();
    turnleft();
  }
  }
 
  else if (n==7){
    stop();
    delay(1000000);
  }
}
 