int Pin = 13;


void setup() {
  // put your setup code here, to run once:
pinMode(Pin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("ON");
digitalWrite(Pin,HIGH);
delay(1000);
Serial.println("OFF");
digitalWrite(Pin,LOW);
delay(1000);
}
