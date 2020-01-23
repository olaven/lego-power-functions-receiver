# lego-power-functions-receiver

A Particle library for controllling the Lego Power Functions IR Receiver. 

_Credit where credit is due:_
This library is based on [jurriaan's
code](https://github.com/jurriaan/Arduino-PowerFunctions) as well as the [1.2
specification](https://github.com/jurriaan/Arduino-PowerFunctions/raw/master/LEGO_Power_Functions_RC_v120.pdf)
of the ir receiver. Thanks!

## Usage

This library enables communication with the [IR
receiver](https://www.lego.com/en-us/product/lego-power-functions-ir-receiver-8884).


```
#include "lego-power-functions-receiver.h"

const int ir_led_pin = D0; 
LegoPowerFunctions lpf(ir_led_pin, channel, LPF_RECEIVER_BLUE);

void setup() {
  Serial.begin(9600);
  lpf.step_forwards();  
}

void loop() {

  lpf.go();
}
```

See the [examples](examples) folder for more details.

## Documentation

This is a library that enables control of a Lego Train. 
Just like a [the
remote](https://www.lego.com/nb-no/product/lego-power-functions-ir-speed-remote-control-8879),
but programatically, through Particle. 

## Contributing

Here's how you can make changes to this library and eventually contribute those changes back.

To get started, [clone the library from GitHub to your local machine](https://help.github.com/articles/cloning-a-repository/).

Change the name of the library in `library.properties` to something different. You can add your name at then end.

Modify the sources in <src> and <examples> with the new behavior.

To compile an example, use `particle compile examples/usage` command in [Particle CLI](https://docs.particle.io/guide/tools-and-features/cli#update-your-device-remotely) or use our [Desktop IDE](https://docs.particle.io/guide/tools-and-features/dev/#compiling-code).

After your changes are done you can upload them with `particle library upload` or `Upload` command in the IDE. This will create a private (only visible by you) library that you can use in other projects. Do `particle library add lego-power-functions-receiver_myname` to add the library to a project on your machine or add the lego-power-functions-receiver_myname library to a project on the Web IDE or Desktop IDE.

At this point, you can create a [GitHub pull request](https://help.github.com/articles/about-pull-requests/) with your changes to the original library. 

If you wish to make your library public, use `particle library publish` or `Publish` command.

## LICENSE
Copyright 2020 @olaven

Licensed under the <insert your choice of license here> license
