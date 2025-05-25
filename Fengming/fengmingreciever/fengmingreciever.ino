/*
  433 MHz RF Module Receiver

*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;


#define IN1 A0
#define IN2 A1
#define IN3 20
#define IN4 21
#define SHOOT 15

int t10 = 10;
int t100 = 100;

void setup()
{
    pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(SHOOT, OUTPUT);
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);
}

void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[5];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      Serial.print("Message Received: ");
      Serial.println((char*)buf);         

      if (buf[0] == 'F' && buf[1] == 'M'){
//        Serial.println("Hello World!");

        if (buf[2] == 'F'){
            digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(t10);
//        Serial.println("Left forward");
        }
        if (buf[2] == 'B'){
            digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(t10);
//        Serial.println("Left Backwards");
        }
        
        if (buf[3] == 'F'){
            digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(t10);
//        Serial.println("Right forward");
        }
        if (buf[3] == 'R'){
            digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(t10);
//        Serial.println("Right Backwards");
        }

        
        if (buf[4] == 'S'){
          digitalWrite(SHOOT, HIGH);
          delay(t100);
        Serial.println("Shoot");
        }

      }
      else {
  // Stop motors again
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);       
  digitalWrite(SHOOT, LOW); 
        }
    }
}
