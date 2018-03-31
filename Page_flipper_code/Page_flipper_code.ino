#include <Servo.h>
#include <stdbool.h>

#define MINQUARTDELAY 50
#define MINHALFDELAY 200
int turn = 1;

void turnDelay(Servo servo, int deg, int ms) {
  servo.write(deg);
  delay(ms);
}

/*void goOrigin(Servo servo) {
  turn(servo, 0, MINHALFDELAY);
}

void turnQuarter(Servo servo) {
  turn(servo, 90, MINQUARTDELAY);
}

void turnOpposite(Servo servo) {
  turn(servo, 180, MINHALFDELAY);
}

void turnAround(Servo servo) {
  turnOpposite(servo);
  goOrigin(servo);
}

void sweep(Servo servo) {
  for (int deg = 0; deg <= 180; ++deg) {
    turn(servo, deg, MINQUARTDELAY);
  }
  for (int deg = 180; deg >= 0; --deg) {
    turn(servo, deg, MINQUARTDELAY);
  }
}*/

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

  servo1.attach(8); // servo controlling arm

  for(posArm=20;posArm >=0;posArm--){
      servo1.write(0); // servo on pin 9 connected to wheel returns to start position
      delay(15);
  }
}

void loop() // note that loop never ends, do not use for this project
{
  while(turn == 0){
    turn = Serial.read();
  }
  for (int i = 0; i < 4; i++) { // do this cycle 7? times to ensure paper gets discharged
    /*servo0.write(0); // adjust degrees for proper alignment with page
    delay(15);
    servo0.write(180); // servo on pin 9 connected to wheel rotates 180 degrees
    delay(1000);
    servo1.write(0); // servo on pin 8 connected to arm rotates 180 degrees to lift up
    delay(1000);
    servo1.write(180);
    delay(1000);
    servo0.write(0); // servo on pin 9 connected to wheel returns to start position
    delay(1000);
    servo1.write(0); // servo on pin 8 connected to arm returns to bottom start position
    // repeat 7? times  */
    for(posArm=0;posArm <=20;posArm++){
      servo1.write(posArm); // servo on pin 9 connected to wheel returns to start position
      delay(15);
    }
    for(posWheel=0;posWheel <= 180;posWheel++){
      servo0.write(posWheel); // servo on pin 9 connected to wheel returns to start position
      delay(5);
    }
    for(posArm=20;posArm >= 0;posArm--){
      servo1.write(posArm); // servo on pin 9 connected to wheel returns to start position
      delay(15);
    }
    for(posWheel=180;posWheel >= 0;posWheel--){
      servo0.write(posWheel); // servo on pin 9 connected to wheel returns to start position
      delay(5);
    }
    for(posArm=0;posArm <=20;posArm++){
      servo1.write(posArm); // servo on pin 9 connected to wheel returns to start position
      delay(15);
    }
    for(posWheel=0;posWheel <= 180;posWheel++){
      servo0.write(posWheel); // servo on pin 9 connected to wheel returns to start position
      delay(5);
    }
    for(posArm=20;posArm >= 0;posArm--){
      servo1.write(posArm); // servo on pin 9 connected to wheel returns to start position
      delay(15);
    }
    for(posWheel=180;posWheel >= 0;posWheel--){
      servo0.write(posWheel); // servo on pin 9 connected to wheel returns to start position
      delay(5);
    }
    // repeat 7? times
  }
  turn = 0;
}
