#include "RenderComponent\IRenderable.h"
#include "Vector2.h"
#pragma once

namespace src 
{
    class Food : public RenderComponent::IRenderable 
    {
        private: char foodCharacter = '#';
        public: src::Vector2 Position;

        public: Food();

        public: void OnRender(Adafruit_SSD1306 display) override;
    };
}