#ifdef PLATFORM_ID
#include "Particle.h"
#else
#include "Particle_mock.h"
#endif

#include "lego-power-functions-receiver.h"

//fastest backwards -> fastest forwards
const int steps[] = {
  9, 10, 11, 12, 13, 14, 15, 8, 1, 2, 3, 4, 5, 6, 7,
};


LegoPowerFunctions::LegoPowerFunctions(int _led_pin, int _channel, int _output) {

  this->led_pin = _led_pin;
  this->channel = _channel;
  this->output = _output;
  this->speed = 7; //<- middle of array. Old: 0;

  pinMode(led_pin, OUTPUT);
}

int LegoPowerFunctions::get_cycles(float number) {

  return int ((1.0/38000.0) * 1000 * 1000 * number);
}

int LegoPowerFunctions::get_checksum() {

  return (0xf ^ first_nibble ^ second_nibble ^ third_nibble);
}

void LegoPowerFunctions::send_bit() {

   const int delay = get_cycles(0.5);

   for(int i = 0; i < 6; i++) {

     digitalWrite(this->led_pin, HIGH);
     delayMicroseconds(delay);
     digitalWrite(this->led_pin, LOW);
     delayMicroseconds(delay);
   }
}

void LegoPowerFunctions::start_stop() {

  send_bit();
  int start_stop_delay = get_cycles(39);
  delayMicroseconds(start_stop_delay);
}

void LegoPowerFunctions::send_message() {

  const int message = this->first_nibble << 12 | this->second_nibble << 8 | this->third_nibble << 4 | this->get_checksum();
  const int HIGH_PAUSE = this->get_cycles(21);
  const int LOW_PAUSE = this->get_cycles(10);

  for(int i = 0; i < 6; i++) {

    this->start_stop();
    for(int j = 0; j < 16; j++) {

      this->send_bit();
      delayMicroseconds((0x8000 & (message << j)) != 0 ? HIGH_PAUSE : LOW_PAUSE);
    }
    this->start_stop();
  }
}

void LegoPowerFunctions::stop() {

  this->speed = 7;
  this->send_message();
}

void LegoPowerFunctions::go() {

  this->first_nibble = 8 | (this->channel - 1);
  this->second_nibble = 4 | this->output;
  this->third_nibble = steps[speed];//speed;

  this->send_message();
}


void LegoPowerFunctions::step_forwards() {

  if (speed == 14) return; //should not go higher
  speed = (speed + 1) % 15;
}

void LegoPowerFunctions::step_backwards() {


  if (speed == 0) return;
  speed -= 1;
}
