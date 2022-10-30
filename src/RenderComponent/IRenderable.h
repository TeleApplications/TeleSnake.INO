#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

#pragma once

namespace RenderComponent
{
    class IRenderable
    {
        public: virtual void OnRender(Adafruit_SSD1306 display) {}
    };
}