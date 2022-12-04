#include <Adafruit_SSD1306.h>
#include "List.h"
#include "Food.h"
#include "Vector2.cpp"
#include "RenderComponent\IRenderable.h"

namespace src
{
    class Snake : public RenderComponent::IRenderable
    {
        private: src::Food foodComponent = new src::Food();
        public: int TileLength = 8;

        public: Vector2D Position;
        public: Vector2D Direction;

        private: Vector2D lastDirection;
        public: Vector2D *TilePositions;

        public: Snake();

        public: void OnRender(Adafruit_SSD1306 display) override;

        private: void DrawTile(Adafruit_SSD1306 display, Vector2D position, int size, Vector2D offset);
        private: int RandomNext(int min, int max);
    };
}