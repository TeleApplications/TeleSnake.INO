#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "IRenderable.h"

#pragma once

namespace RenderComponent
{
    struct DisplayInformation
    {
        public:
            int Width;
            int Height;
            int Address;

        public: DisplayInformation() { }
        public: DisplayInformation(int width, int height, int address)
        {
            Width = width;
            Height = height;
            Address = address;
        }
    };

    class RenderManager
    {
        private: long lastRefresh = 0;
        private: Adafruit_SSD1306 currentDisplay;
        private: RenderComponent::IRenderable *currentComponenets;

        public: DisplayInformation Information;

    
        public: RenderManager(RenderComponent::IRenderable components[], DisplayInformation information);

        public: bool StartRender();
        private: void RenderComponents(RenderComponent::IRenderable components[]);
    };
}