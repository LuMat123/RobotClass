#include <Servo.h>

int servo1pos = 0;
int servo2pos = 0;
int servo3pos = 0;

int anglepos1 = 0;
int anglepos2 = 0;
int anglepos3 = 0;

int maxspeed = 25;
int minspeed = 55;

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
int keyboard_input = 0;
int electropin = 7;
int electropin2 = 6;
int menu_popup = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(electropin, OUTPUT);
pinMode(electropin2, OUTPUT);
myservo1.attach(8);
myservo2.attach(9);
myservo3.attach(10);
myservo4.attach(3);
myservo5.attach(2);
myservo6.attach(4);
Serial.begin(9600);
Serial.println("Setup done");
}

void loop() {
  // put your main code here, to run repeatedly:
//pickup();
//delay(500);
//myservo1.write(100);
//delay(500);
//myservo1.write(130);
//delay(500);
//place();
//delay(500);

show_menu();

keyboard_input = Serial.parseInt();


//Serial.println(keyboard_input);
if (keyboard_input >= 1) {

if (keyboard_input == 1) {
  homing();
}
else if (keyboard_input == 2) {
  test_servo_all();
  menu_popup = 0;
}
else if (keyboard_input == 3) {
  test_electromagnet();
}
else if (keyboard_input == 4) {
  test_electromagnet2();
}
else if (keyboard_input == 5) {
  test_servo1();
}
else if (keyboard_input == 6) {
  test_servo2();
}
else if (keyboard_input == 7) {
  test_servo3();
}
  
if (keyboard_input <= 1180 and keyboard_input >= 1000) {
  keyboard_input = keyboard_input - 1000;
  myservo1.write(keyboard_input);
  delay(50);
  Serial.println("Angle for motor 1: ");
  Serial.println(keyboard_input);
}
if (keyboard_input <= 2180 and keyboard_input >= 2000) {
  keyboard_input = keyboard_input - 2000;
  myservo2.write(keyboard_input);
  delay(50);
  Serial.println("Angle for motor 2: ");
  Serial.println(keyboard_input);
}
if (keyboard_input <= 3180 and keyboard_input >= 3000) {
  keyboard_input = keyboard_input - 3000;
  myservo3.write(keyboard_input);
  delay(50);
  Serial.println("Angle for motor 3: ");
  Serial.println(keyboard_input);
}
if (keyboard_input <= 4180 and keyboard_input >= 4000) {
  keyboard_input = keyboard_input - 4000;
  anglepos1 = keyboard_input;
  gotoangle();
  Serial.println("Angle for motor 3: ");
  Serial.println(keyboard_input);
}


}
/*delay(50);
homing();
electromagnet_on();*/
}


void gotoangle() {
  if (servo1pos < anglepos1) {
    for (int angle = servo1pos; angle <= anglepos1; angle++) {
      myservo1.write(angle);
      delay(maxspeed);
    }
  }
}


void pickup() {
  Serial.println("Pickup started");
  myservo2.write(100);
  delay(500);
  myservo1.write(60);
  delay(150);
  myservo2.write(55);
  delay(150);
  myservo3.write(160);
  delay(150);
  electromagnet_on();
  delay(5000);
  myservo2.write(85);
  delay(150);
  Serial.println("Pickup done");
  delay(150);
}

void place() {
  Serial.println("Placing started");

  myservo1.write(160);
  delay(150);
  myservo2.write(55);
  delay(150);
  electromagnet_off();
  delay(150);
  Serial.println("Placing done");
}

void test_electromagnet() {
digitalWrite(electropin, HIGH);
Serial.println("Left electromagnet on");
delay(5000);
digitalWrite(electropin, LOW);
Serial.println("Left electromagnet off");
delay(5000);
}

void test_electromagnet2() {
digitalWrite(electropin2, HIGH);
Serial.println("Right electromagnet on");
delay(5000);
digitalWrite(electropin2, LOW);
Serial.println("Right electromagnet off");
delay(5000);
}

void electromagnet_on() {
digitalWrite(electropin, HIGH);
Serial.println("Electromagnet on");
}

void electromagnet_off() {
digitalWrite(electropin, LOW);
Serial.println("Electromagnet off");
}

void homing() {
  Serial.println("Homing started");
  myservo1.write(0);
  delay(50);
  myservo2.write(0);
  delay(50);
  myservo3.write(0);
  delay(50);
  servo1pos = 0;
  servo2pos = 0;
  servo3pos = 0;
  Serial.println("Homing done");
}

void test_servo_all() {
for(int counter = 0; counter <= 180; counter = counter + 1){
  myservo1.write(counter);
  myservo2.write(counter);
  myservo3.write(counter);
  delay(maxspeed);
  Serial.println(counter);
}
for(int counter = 180; counter >= 0; counter = counter - 1){
  myservo1.write(counter);
  myservo2.write(counter);
  myservo3.write(counter);
  delay(maxspeed);
  Serial.println(counter);
}
}

void test_servo1() {
for(int counter = 0; counter <= 180; counter = counter + 1){
  myservo1.write(counter);
  delay(50);
  Serial.println(counter);
}
for(int counter = 180; counter >= 0; counter = counter - 1){
  myservo1.write(counter);
  delay(50);
  Serial.println(counter);
}
}

void test_servo2() {
  for(int counter = 0; counter <= 180; counter = counter + 1){
  myservo2.write(counter);
  delay(50);
  Serial.println(counter);
}
for(int counter = 180; counter >= 0; counter = counter - 1){
  myservo2.write(counter);
  delay(50);
  Serial.println(counter);
}
}
void test_servo3() {
  for(int counter = 0; counter <= 180; counter = counter + 1){
  myservo3.write(counter);
  delay(50);
  Serial.println(counter);
}
for(int counter = 180; counter >= 0; counter = counter - 1){
  myservo3.write(counter);
  delay(50);
  Serial.println(counter);
}
}
void show_menu() {
  if (menu_popup == 0) {
Serial.println("Robot Menu: ");
Serial.println("1 = homing");
Serial.println("2 = move all");
Serial.println("3 = left electromagnet");
Serial.println("4 = right electromagnet");
Serial.println("5 = servo 1");
Serial.println("6 = servo 2");
Serial.println("7 = servo 3");
menu_popup = 1;
}
}
