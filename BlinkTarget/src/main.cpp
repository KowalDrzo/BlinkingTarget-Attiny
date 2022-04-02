#include <Arduino.h>

#define RESET_Pin 5
#define SENSOR_Pin 3
#define LED_Pin 1

void setup() {

    pinMode(RESET_Pin, INPUT_PULLUP);
    pinMode(SENSOR_Pin, INPUT_PULLUP);
    pinMode(LED_Pin, OUTPUT);

    int16_t i;

    for (i = 0; i < 255; i++) {
        analogWrite(LED_Pin, i);
        delay(3);
    }
    for (; i >= 0; i--) {
        analogWrite(LED_Pin, i);
        delay(1);
    }
}

void loop() {

    if (!digitalRead(SENSOR_Pin)) {
        
        for (uint8_t i = 0; i < 7; i++) {
            analogWrite(LED_Pin, 255);
            delay(100);
            analogWrite(LED_Pin, 0);
            delay(100);
        }
    }
}