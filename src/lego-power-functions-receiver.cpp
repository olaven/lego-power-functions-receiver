/* lego-power-functions-receiver library by @olaven
 */

#include "lego-power-functions-receiver.h"

/**
 * Constructor.
 */
Legopowerfunctionsreceiver::Legopowerfunctionsreceiver()
{
  // be sure not to call anything that requires hardware be initialized here, put those in begin()
}

/**
 * Example method.
 */
void Legopowerfunctionsreceiver::begin()
{
    // initialize hardware
    Serial.println("called begin");
}

/**
 * Example method.
 */
void Legopowerfunctionsreceiver::process()
{
    // do something useful
    Serial.println("called process");
    doit();
}

/**
* Example private method
*/
void Legopowerfunctionsreceiver::doit()
{
    Serial.println("called doit");
}
