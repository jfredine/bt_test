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
        SoftSerial.write(Serial.read());
    }
    while(SoftSerial.available()) {
        Serial.write(SoftSerial.read());
    }
}