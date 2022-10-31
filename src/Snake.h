#include <Adafruit_SSD1306.h>
#include "List.h"
#include "RenderComponent\IRenderable.h"

namespace src
{
    struct Vector2
    {
        public: int X = 0;
        public: int Y = 0; 
    };

    class Snake : public RenderComponent::IRenderable
    {
        public: Vector2 Position;
        private: Vector2 lastDirection;

        public: Vector2 *TilePositions;

        public: Snake();
        public: void OnRender(Adafruit_SSD1306 display) override;
    };
}