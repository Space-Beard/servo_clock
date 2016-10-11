//include Servo library for interfacing with servos
#include <Servo.h>

//create servo object
Servo myServo;

const int potPin = A0;
int angle = -1;
boolean reverse = false;

void setup() {
  //assign the pin the servo is attached to and start the serial connection
  myServo.attach(9);

  Serial.begin(9600);

}

void loop() {
  //makes the servo tick 3 degree every second, so it takes 1 minute to travel in either direction

  //determines if what the next angle should be and if it reaches a certain value, reverses the servo
  if (angle >= -1 && reverse == false ) {
    angle = angle + 1;
    if (angle == 180){
      angle = 179;
      reverse = true;
    }
  }
  if (angle <= 180 && reverse == true ){
    angle = angle - 1;
    if (angle == 0) {
      reverse = false;
    }
  }

  myServo.write(angle);
  delay(333);
    
}
