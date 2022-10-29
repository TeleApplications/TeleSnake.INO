#include "Component.h"
#include <Arduino.h>

namespace Components
{
   Component::Component(byte pin, uint8_t mode) : Pin(pin), Mode(mode)
   {
      pinMode(Pin, Mode);
   }
}
