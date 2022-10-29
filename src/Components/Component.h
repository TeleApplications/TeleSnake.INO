#include <Arduino.h>
#pragma once

namespace Components
{
    class Component
    {
        public: byte Pin;
        public: uint8_t Mode;

        public: Component(byte pin, uint8_t mode); 

        public: virtual void OnLoad() {}

        public: virtual void OnUpdate(long difference) {}
    };
}