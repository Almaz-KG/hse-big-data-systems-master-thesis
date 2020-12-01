#define IN1_PIN 2
#define IN2_PIN 3
#define IN3_PIN 4
#define IN4_PIN 6

#define IN5_PIN 8
#define IN6_PIN 9
#define IN7_PIN 11
#define IN8_PIN 12

#define ENA1_PIN 5
#define ENA2_PIN 10

#define SPEED 210

char MOTOR_STATE = ' ';

void setup() {
  Serial.begin(9600);         // Sets the data rate in bits per second (baud) for serial data transmission
  
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);
  pinMode(IN5_PIN, OUTPUT);
  pinMode(IN6_PIN, OUTPUT);
  pinMode(IN7_PIN, OUTPUT);
  pinMode(IN8_PIN, OUTPUT);
  
  pinMode(ENA1_PIN, OUTPUT);
  pinMode(ENA2_PIN, OUTPUT);
}

void go_forward(){
  digitalWrite(IN1_PIN, HIGH); 
  digitalWrite(IN2_PIN, LOW); 

  digitalWrite(IN3_PIN, HIGH); 
  digitalWrite(IN4_PIN, LOW); 

  digitalWrite(IN5_PIN, HIGH); 
  digitalWrite(IN6_PIN, LOW); 

  digitalWrite(IN7_PIN, HIGH); 
  digitalWrite(IN8_PIN, LOW); 

  analogWrite(ENA1_PIN, SPEED);
  analogWrite(ENA2_PIN, SPEED);
}

void go_backward(){
  digitalWrite(IN1_PIN, LOW); 
  digitalWrite(IN2_PIN, HIGH); 

  digitalWrite(IN3_PIN, LOW); 
  digitalWrite(IN4_PIN, HIGH); 

  digitalWrite(IN5_PIN, LOW); 
  digitalWrite(IN6_PIN, HIGH); 

  digitalWrite(IN7_PIN, LOW); 
  digitalWrite(IN8_PIN, HIGH); 

  analogWrite(ENA1_PIN, SPEED);
  analogWrite(ENA2_PIN, SPEED);
}

void motor_stop(){
  digitalWrite(IN1_PIN, HIGH); 
  digitalWrite(IN2_PIN, HIGH); 

  digitalWrite(IN3_PIN, HIGH); 
  digitalWrite(IN4_PIN, HIGH); 

  digitalWrite(IN5_PIN, HIGH); 
  digitalWrite(IN6_PIN, HIGH); 

  digitalWrite(IN7_PIN, HIGH); 
  digitalWrite(IN8_PIN, HIGH); 

  analogWrite(ENA1_PIN, 0);
  analogWrite(ENA2_PIN, 0);
}

void loop() // ОСНОВНОЙ ЦИКЛ
{
  if (Serial.available() > 0) {
    char data = Serial.read();      // Read the incoming data and store it into variable data
    
    if (data == 'F' || data == 'B')
      MOTOR_STATE = data;
    else
      MOTOR_STATE = ' ';
  } else {
    MOTOR_STATE = ' ';
  }

  if (MOTOR_STATE == 'F')
    go_forward();
  else if (MOTOR_STATE == 'B')
    go_backward();
  else 
    motor_stop();
}
