// Example usage for lego-power-functions-receiver library by @olaven.

#include "lego-power-functions-receiver.h"

// Initialize objects from the lib
Legopowerfunctionsreceiver legopowerfunctionsreceiver;

void setup() {
    // Call functions on initialized library objects that require hardware
    legopowerfunctionsreceiver.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    legopowerfunctionsreceiver.process();
}
