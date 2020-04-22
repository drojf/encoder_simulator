#include "avr/wdt.h"

const int ledPin = 13;      // the pin that the LED is attached to
const int channel_a = 7;
const int channel_b = 8;
int phase_delay = 50;
  

void setup() {
  // initialize the serial communication:
  Serial.begin(115200);
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(channel_a, OUTPUT);
  pinMode(channel_b, OUTPUT);
  Serial.setTimeout(300);
}

void poll_serial(void) {
  if (Serial.available()) {
    int result = Serial.parseInt();
    if(result != 0)
    {
      phase_delay = result;
      Serial.println(phase_delay);      
    }    
  }
}

void loop() {
  // Channel A high  
  digitalWrite(ledPin, HIGH);
  digitalWrite(channel_a, HIGH);
  delay(phase_delay);
  poll_serial();
  
  // Channel B high  
  digitalWrite(ledPin, LOW);
  digitalWrite(channel_b, HIGH);
  delay(phase_delay);
  poll_serial();

  // Channel A low
  digitalWrite(ledPin, HIGH);
  digitalWrite(channel_a, LOW);
  delay(phase_delay);
  poll_serial();

  // Channel B low
  digitalWrite(ledPin, LOW);
  digitalWrite(channel_b, LOW);
  delay(phase_delay);
  poll_serial();

}
