#include "RenderComponent\IRenderable.h"
#include "Vector2.cpp"
#pragma once

namespace src 
{
    class Food : public RenderComponent::IRenderable 
    {
        private: char foodCharacter = '#';
        public: src::Vector2D Position;

        public: Food();

        public: void OnRender(Adafruit_SSD1306 display) override;
    };
}