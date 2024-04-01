#include <Servo.h> // REWRITE THE FOLLOWING WAY: DEFINE 1 LINE OF CODE THAT EXECUTES THE MOVEMENT OF THE SERVO, THEN DEPENDING ON THE SERVO YOU WANT, IT CHANGES BUT ITS NOT NECESSARY TO REWRITE EVERYTHING AGAIN.
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;

int pos_servo1 = 90;
int pos_servo2 = 90;
int pos_servo3 = 90;
int pos_servo4 = 90;

#define BUTTON_UP 2
#define BUTTON_RIGHT 3
#define BUTTON_DOWN 4
#define BUTTON_LEFT 5
#define BUTTON_E 6
#define BUTTON_F 7
#define BUTTON_K 8
#define PIN_ANALOG_X 0
#define PIN_ANALOG_Y 1
#define DELAY 10

void setup() {
  servo_1.attach(9);
  servo_2.attach(10);
  servo_3.attach(11);
  servo_4.attach(12);

  Serial.begin(9600);

  pinMode(BUTTON_UP, INPUT);
  digitalWrite(BUTTON_UP, HIGH);
  pinMode(BUTTON_RIGHT, INPUT);
  digitalWrite(BUTTON_RIGHT, HIGH);
  pinMode(BUTTON_DOWN, INPUT);
  digitalWrite(BUTTON_DOWN, HIGH);
  pinMode(BUTTON_LEFT, INPUT);
  digitalWrite(BUTTON_LEFT, HIGH);
  pinMode(BUTTON_E, INPUT);
  digitalWrite(BUTTON_E, HIGH);
  pinMode(BUTTON_F, INPUT);
  digitalWrite(BUTTON_F, HIGH);
  pinMode(BUTTON_K, INPUT);
  digitalWrite(BUTTON_K, HIGH);
}

void loop() {
  Serial.print("x: "); Serial.print(analogRead(PIN_ANALOG_X));
  Serial.print(" y: "); Serial.println(analogRead(PIN_ANALOG_Y));
  servo_1.write(pos_servo1);
  servo_2.write(pos_servo2);
  servo_3.write(pos_servo3);
  servo_4.write(pos_servo4);
  
  while (digitalRead(BUTTON_UP) == LOW) {
    //Serial.println(" Button UP is pressed");
    delay(DELAY); 
    if (pos_servo1 >= 180) {
      Serial.println("LIMIT REACHED!");
      delay(5);
    } 
    else {
      pos_servo1 += 1;
      servo_1.write(pos_servo1);
    }
  }

  while (digitalRead(BUTTON_RIGHT) == LOW) {
    //Serial.println(" Button RIGHT is pressed");
    delay(DELAY);
    if (pos_servo2 >= 180) {
      Serial.println("LIMIT REACHED!");
      delay(5);
    } 
    else {
      pos_servo2 += 1;
      servo_2.write(pos_servo2);
    }
  }

  while (digitalRead(BUTTON_DOWN) == LOW) {
    //Serial.println(" Button DOWN is pressed");
    delay(DELAY);
    if (pos_servo1 <= 0) {
      Serial.println("LIMIT REACHED!");
      delay(5);
    } 
    else {
      pos_servo1 -= 1;
      servo_1.write(pos_servo1);
    }
  }

  while (digitalRead(BUTTON_LEFT) == LOW) {
    //Serial.println(" Button LEFT is pressed");
    delay(DELAY);
    if (pos_servo2 <= 0) {
      Serial.println("LIMIT REACHED!");
      delay(5);
    } 
    else {
      pos_servo2 -= 1;
      servo_2.write(pos_servo2);
    }
  }

  // while() // I want to make this portion in the future proportional to the speed of the servo (EXAMPLE: Moving a little the joystick will only move slowly the Servo)

  //while (digitalRead(BUTTON_E) == LOW) { // use in the future for pause button
    Serial.println(" Button START is pressed");
    delay(DELAY);
  //}

  //while (digitalRead(BUTTON_F) == LOW) {
    Serial.println(" Button SELECT is pressed");
    delay(DELAY);
  //}

  //while (digitalRead(BUTTON_K) == LOW) { 
    Serial.println(" THUMB is pressed");
    delay(DELAY);
  //}
}
