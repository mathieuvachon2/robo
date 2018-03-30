#ifndef SERVO_UTIL
#define SERVO_UTIL

#include <stdbool.h>
#include <Arduino.h>
#include <Servo.h>

#define MINQUARTDELAY 50
#define MINHALFDELAY 200

class ServoUtil {
    Servo servo;
	int servoPin;
public:
	ServoUtil(int servoPin) {
		servo.attach(servoPin);
	}

	int getPin() { return servoPin; }
	void setPin(int pin) {
		servoPin = pin;
		servo.attach(servoPin);
	}
	
	Servo getServo() { return servo; }
	
	void turn(int deg, int ms) {
		servo.write(deg);
		delay(ms);
	}
	
	void goOrigin() {
		turn(0, MINHALFDELAY);
	}
	
	void turnQuarter() {
		turn(90, MINQUARTDELAY);
	}

	void turnOpposite() {
		turn(180, MINHALFDELAY);
	}
	
	void turnAround() {
		turnOpposite();
		goOrigin();
	}
	
	void sweep() {
		for (int deg = 0; deg <= 180; ++deg) {
			turn(deg, MINQUARTDELAY);
		}
		for (int deg = 180; deg >= 0; --deg) {
			turn(deg, MINQUARTDELAY);
		}
	}
};

#endif /* ServoUtil.cpp */
