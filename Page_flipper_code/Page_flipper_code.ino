#include <Servo.h>

Servo servo0; //the wheel
Servo servo1; //the arm
int sensorvalue0;
int sensorvalue1;
int posArm;
int posWheel;

////get output from python program: positive count if hit, negative or 0 if hold
//// int count = get.countFromProgram;
//int count = 1;
//int count1 = -1;
//int count2 = 0;

void setup(){
  //pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  servo0.attach(2); // servo controlling wheel

  //pinMode(A1, INPUT);
  pinMode(8, OUTPUT);
  servo1.attach(8); // servo controlling arm

  for(posArm=30;posArm >=0;posArm--){
      servo1.write(posArm); // servo on pin 9 connected to wheel returns to start position
      delay(15);
  }

  for (int i = 0; i < 7; i++) { // do this cycle 7? times to ensure paper gets discharged
    /*servo0.write(0); // adjust degrees for proper alignment with page
    delay(15);
    servo0.write(180); // servo on pin 9 connected to wheel rotates 180 degrees
    delay(1500);
    servo1.write(0); // servo on pin 8 connected to arm rotates 180 degrees to lift up
    delay(1500);
    servo1.write(40);
    delay(1500);
    servo0.write(0); // servo on pin 9 connected to wheel returns to start position
    delay(1500);
    servo1.write(0); // servo on pin 8 connected to arm returns to bottom start position
    // repeat 7? times  */
    for(posArm=0;posArm <=30;posArm++){
      servo1.write(posArm); // servo on pin 9 connected to wheel returns to start position
      delay(15);
    }
    for(posWheel=0;posWheel <= 180;posWheel++){
      servo0.write(posWheel); // servo on pin 9 connected to wheel returns to start position
      delay(5);
    }
    for(posArm=30;posArm >= 0;posArm--){
      servo1.write(posArm); // servo on pin 9 connected to wheel returns to start position
      delay(15);
    }
    for(posWheel=180;posWheel >= 0;posWheel--){
      servo0.write(posWheel); // servo on pin 9 connected to wheel returns to start position
      delay(5);
    }
    for(posArm=0;posArm <=30;posArm++){
      servo1.write(posArm); // servo on pin 9 connected to wheel returns to start position
      delay(15);
    }
    for(posWheel=0;posWheel <= 180;posWheel++){
      servo0.write(posWheel); // servo on pin 9 connected to wheel returns to start position
      delay(5);
    }
    for(posArm=30;posArm >= 0;posArm--){
      servo1.write(posArm); // servo on pin 9 connected to wheel returns to start position
      delay(15);
    }
    for(posWheel=180;posWheel >= 0;posWheel--){
      servo0.write(posWheel); // servo on pin 9 connected to wheel returns to start position
      delay(5);
    }
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
