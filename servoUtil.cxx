#include <stdbool.h>
#include <Servo.h>

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
    
	void turnDelay(int deg, size_t ms) {
		servo.write(deg);
		delay(ms);
    }
	
	void turn(int deg, int ms) {
		turnDelay(deg, (size_t)ms);
	}
	
	void turnQuarter() {
		turnDelay(90, 15);
	}
	
	void sweep() {
		for (int deg = 0; deg <= 180; ++deg) {
			turnDelay(deg, 15);
		}
		for (int deg = 180; deg >= 0; --deg) {
			turnDelay(deg, 15);
		}
	}
	
	void goOrigin() {
		turn(0, 15);
	}
	
	void turnLeft() {
		turn(90, 15);
	}
	
	void turnAround() {
		turn(360, 15);
	}
	
	void turnQuick(int deg) {
		turn(deg, 0);
	}
}
