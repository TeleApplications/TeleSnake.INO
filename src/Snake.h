#include <Adafruit_SSD1306.h>
#include "RenderComponent\IRenderable.h"

namespace src
{
    class Snake : public RenderComponent::IRenderable
    {
        public: int X = 0;
        public: int Y = 0; 

        public: void OnRender(Adafruit_SSD1306 display) override;
    };
}