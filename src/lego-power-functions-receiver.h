#ifndef LEGO_POWER_FUNCTIONS_PARTICLE_H
#define LEGO_POWER_FUNCTIONS_PARTICLE_H

#define LPF_RECEIVER_BLUE 1
#define LPF_RECEIVER_RED 0

class LegoPowerFunctions {

  public:
     int speed;
     LegoPowerFunctions(int _led_pin, int _channel, int _output);
     void go();
     void stop();
     void step_forwards();
     void step_backwards();
     int led_pin;
     int channel;
     int output;

  private:
      int first_nibble; //TODO: have Message-class handle content logic
      int second_nibble;
      int third_nibble;
      int get_cycles(float number);
      int get_checksum();
      void send_bit();
      void start_stop();
      void send_message();
};



#endif // LEGO_POWER_FUNCTIONS_PARTICLE_H
