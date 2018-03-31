#include <Servo.h>

Servo servo0;
Servo servo1;
int sensorvalue0;
int sensorvalue1;

////get output from python program: positive count if hit, negative or 0 if hold
//// int count = get.countFromProgram;
//int count = 1;
//int count1 = -1;
//int count2 = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  servo0.attach(9);

  pinMode(A1, INPUT);
  pinMode(8, OUTPUT);
  servo1.attach(8);

for (int i = 0; i < 7; i++) { // do this cycle 7? times to ensure paper gets discharged
  servo0.write(0);
  delay(1000);
  servo0.write(180); // servo on pin 9 connected to wheel rotates 180 degrees
  delay(1000);
  servo1.write(0); // servo on pin 8 connected to arm rotates 180 degrees to lift up
  delay(1000);
  servo1.write(180);
  delay(1000);
  servo0.write(0); // servo on pin 9 connected to wheel returns to start position
  delay(1000);
  servo1.write(0); // servo on pin 8 connected to arm returns to bottom start position
  // repeat 7? times  
}

}

 
//
//  if (count1 > 0) { //move hand down to surface to indicate hit
//    servo0.write(105);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 300ms for the servo to reach the position
//    servo0.write(90);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 300ms for the servo to reach the position
//    servo0.write(75);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 300ms for the servo to reach the position
//    servo0.write(60);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 300ms for the servo to reach the position
//    servo0.write(45);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 300ms for the servo to reach the position
//    servo0.write(35);                 // tell servo to go to position in variable 'pos'
//    delay(500);                      // waits 300ms for the servo to reach the position
//    servo0.write(60);                 // tell servo to go to position in variable 'pos'
//    delay(500);                      // waits 300ms for the servo to reach the position
//    servo0.write(90);                 // tell servo to go to position in variable 'pos'
//    delay(500);                      // waits 300ms for the servo to reach the position
//  }
//
//  else { //leave hand alone and move arm side to side to indicate hold
//    servo1.write(45);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(20);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(0);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(20);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(45);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(70);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(90);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(110);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(135);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(155);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(180);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(155);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(135);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(110);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//    servo1.write(90);                 // tell servo to go to position in variable 'pos'
//    delay(200);                      // waits 75ms for the servo to reach the position
//  }
//}

void loop() // note that loop never ends, do not use for this project
{
}
