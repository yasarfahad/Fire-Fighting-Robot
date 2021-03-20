#include<SoftwareSerial.h>
#include<AFMotor.h>
#include<Servo.h>
#define LED 13
AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
Servo slidServo;
Servo posServo;
int command;
void setup(){
  pinMode(LED,OUTPUT);
  posServo.attach(9);
  slidServo.attach(10);
  Serial.begin(9600);
  m1.setSpeed(240);
  m2.setSpeed(255);
  m3.setSpeed(255);
}
void loop(){
  digitalWrite(LED,HIGH);
  //delay(200);
  //digitalWrite(LED,LOW);
  //delay(200);
  command=Serial.read();
  if(command >=1 && command<=179)
  {
    slidServo.write(command);
  }
  else if( command == 206)
  {
    posServo.write(25);
  }
  else if( command == 207)
  {
    posServo.write(90);
  }
  else if( command == 208)
  {
    posServo.write(130);
  }
 else if(command == 200)
  {
    m1.run(FORWARD);
    m2.run(FORWARD);
  }
else if(command == 201)
{
  m1.run(FORWARD);
  m2.run(BACKWARD);  
}
  else if(command == 202)
  {
    m1.run(BACKWARD);
    m2.run(FORWARD);
  }
  else if(command ==203)
  {
    m1.run(BACKWARD);
    m2.run(BACKWARD);
  }
  else if(command == 0)
  {
    m1.run(RELEASE);
    m2.run(RELEASE);
  }
else if(command == 204)
{
  m3.run(FORWARD);
}
else if(command == 205)
{
  m3.run(RELEASE);
}
}
