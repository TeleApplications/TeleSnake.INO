#include <Adafruit_SSD1306.h>
#include "List.h"
#include "Food.h"
#include "Vector2.h"
#include "RenderComponent\IRenderable.h"

namespace src
{
    class Snake : public RenderComponent::IRenderable
    {
        private: src::Food foodComponent = src::Food();
        public: int TileLength = 8;

        public: Vector2 Position;
        public: Vector2 Direction;

        private: Vector2 lastDirection;
        public: Vector2 *TilePositions;

        public: Snake();

        public: void OnRender(Adafruit_SSD1306 display) override;

        private: void DrawTile(Adafruit_SSD1306 display, Vector2 position, int size, Vector2 offset);
        private: int RandomNext(int min, int max);
    };
}