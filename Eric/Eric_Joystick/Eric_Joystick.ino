
int axisX = A0;
int axisY = A1;
int buttenPin = 13;
int buttenPinValue = 0;
int axisXValue = 0;
int axisYValue = 0;
int ledPin = A2;

void setup() {
  pinMode(axisX, INPUT);
  pinMode(axisY, INPUT);
  pinMode(buttenPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  axisXValue = analogRead(axisX);
  axisYValue = analogRead(axisY);
  buttenPinValue = digitalRead(buttenPin);
  Serial.print("UpDown:");
  Serial.print(axisYValue);
  Serial.print(",");
  Serial.print("LeftRight");
  Serial.print(axisXValue);
  Serial.print(", ");
  Serial.print(buttenPinValue);
  Serial.println("");
  analogWrite(ledPin, axisXValue);
  
}
