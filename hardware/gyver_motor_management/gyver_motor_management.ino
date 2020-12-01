#include "GyverMotor.h"

// GMotor motor(DRIVER2WIRE, dig_pin, PWM_pin, (LOW / HIGH) )
GMotor motor1(DRIVER2WIRE, 4, 3, HIGH);
GMotor motor2(DRIVER2WIRE, 7, 5, HIGH);

int MIN_SPEED = -255;
int MAX_SPEED = 255;

int SPEED = 0;
int SPEED_STEP = 20;

void setup() {
  Serial.begin(9600);
  
  motor1.setMode(AUTO);
  motor2.setMode(AUTO);

  motor1.setMinDuty(SPEED_STEP);
  motor2.setMinDuty(SPEED_STEP);
}

void loop() {

  if (Serial.available() > 0) {
    char data = Serial.read();      // Read the incoming data and store it into variable data
    
    if (data == 'F')
      SPEED += SPEED_STEP;
    else if (data == 'B')
      SPEED -= SPEED_STEP;
    else
      SPEED = 0;
  }
  
  SPEED = constrain(SPEED, MIN_SPEED, MAX_SPEED);
  motor1.setSpeed(SPEED);
  motor2.setSpeed(SPEED);
  
  delay(10);  // задержка просто для "стабильности"
}
