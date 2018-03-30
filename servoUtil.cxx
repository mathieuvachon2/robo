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
    void turnDelay(int deg, size_t ms) {
		servo.write(deg);
		delay(ms);
    }
}
