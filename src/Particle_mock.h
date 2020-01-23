/**
   This file is copied from:
   https://github.com/particle-iot/device-os/blob/0aaba72703217df871e39c5456010608de565137/user/inc/Arduino.h
 */

#ifndef ARDUINO_H
#define ARDUINO_H

#define OUTPUT 1
#define HIGH 1
#define LOW 1

void pinMode(int pin, int mode) {
  // mocked for test
}
void digitalWrite(int pin, int hi_lo) {
  // mocked for test
}
void delayMicroseconds(int microseconds) {
  // mocked for test
}

#endif	/* ARDUINO_H */
