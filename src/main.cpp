#include <Arduino.h>
#include <SoftwareSerial.h>

//                        RX  TX
SoftwareSerial SoftSerial(12, 13);

void setup() {
    Serial.begin(9600);
    SoftSerial.begin(9600);
}

#define BUFFER_SIZE 200
void loop() {
    while (Serial.available()) {
        char c = Serial.read();
        Serial.write(c);
        SoftSerial.write(c);
        
    }
    while(SoftSerial.available()) {
        char c = SoftSerial.read();
        SoftSerial.write(c);
        Serial.write(c);
    }
}