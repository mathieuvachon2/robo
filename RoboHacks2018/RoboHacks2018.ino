#include <stdbool.h>
#include <Servo.h>

int const servoPin = 0;

Servo servo1;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  servo1.attach(servoPin);
}

// the loop function runs over and over again forever
void loop() {
//  blinks();
  spins();
}

void spinny(int angle, size_t ms) {
  servo1.write(angle);
  delay(ms);
}

void spins() {
  spinny(0, 1000);
  spinny(90, 1000);
  spinny(180, 1000);
}

void blinky(bool on, size_t ms) {
  digitalWrite(LED_BUILTIN, on);
  delay(ms);
}

void blinks() {
  blinky(true, 100);
  blinky(false, 100);
  blinky(true, 100);
  blinky(false, 500);

  blinky(true, 100);
  blinky(false, 100);
  blinky(true, 100);
  blinky(false, 1000);

  blinky(true, 1000);
  blinky(false, 1000);
  blinky(true, 1000);
  blinky(false, 1000);
}

