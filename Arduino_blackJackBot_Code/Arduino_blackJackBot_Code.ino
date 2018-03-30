#include <Servo.h>
#include "ServoUtil.cpp"

int servoPin = 9;
ServoUtil servo(servoPin);
//servo.setPin(9);

Servo servo0;
Servo servo1;
int sensorvalue0;
int sensorvalue1;

//get output from python program: positive count if hit, negative or 0 if hold
// int count = get.countFromProgram;
int count = 1;
int count1 = -1;
int count2 = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  servo0.attach(9);

  pinMode(A1, INPUT);
  pinMode(8, OUTPUT);
  servo1.attach(8);

  servo0.write(0);
  delay(200);
  servo0.write(180);
  delay(1000);
//  servo.turn(0, 200);
//  servo.goOrigin();
//  servo.turnAround();
//  servo.turn(180, 200);
  return;

  if (count > 0) { //move hand down to surface to indicate hit
    servo0.write(105);                 // tell servo to go to position in variable 'pos'
    delay(200);                      // waits 300ms for the servo to reach the position
    servo0.write(90);                 // tell servo to go to position in variable 'pos'
    delay(200);                      // waits 300ms for the servo to reach the position
    servo0.write(75);                 // tell servo to go to position in variable 'pos'
    delay(200);                      // waits 300ms for the servo to reach the position
    servo0.write(60);                 // tell servo to go to position in variable 'pos'
    delay(200);                      // waits 300ms for the servo to reach the position
    servo0.write(45);                 // tell servo to go to position in variable 'pos'
    delay(200);                      // waits 300ms for the servo to reach the position
    servo0.write(35);                 // tell servo to go to position in variable 'pos'
    delay(500);                      // waits 300ms for the servo to reach the position
    servo0.write(60);                 // tell servo to go to position in variable 'pos'
    delay(500);                      // waits 300ms for the servo to reach the position
    servo0.write(90);                 // tell servo to go to position in variable 'pos'
    delay(500);                      // waits 300ms for the servo to reach the position
  }

  else { //leave hand alone and move arm side to side to indicate hold
    servo1.write(45);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(20);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(0);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(20);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(45);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(70);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(90);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(110);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(135);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(155);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(180);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(155);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(135);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(110);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
    servo1.write(90);                 // tell servo to go to position in variable 'pos'
    delay(75);                      // waits 75ms for the servo to reach the position
  }
}

void loop()
{
  
}
