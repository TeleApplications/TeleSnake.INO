#include <Adafruit_SSD1306.h>
#include "List.h"
#include "RenderComponent\IRenderable.h"

namespace src
{
    struct Vector2
    {
        public: int X = 0;
        public: int Y = 0; 

        public: Vector2()
        {
        };

        public: Vector2(int x, int y)
        {
            X = x;
            Y = y;
        };

        public: Vector2* operator+=(const src::Vector2 vector)
        {
            int finalX = X + vector.X;
            int finalY = Y + vector.Y;

            return new Vector2(finalX, finalY);
        }

        public: static Vector2 Left() { return Vector2(-1, 0); }
        public: static Vector2 Right() { return Vector2(1, 0); }
        public: static Vector2 Up() { return Vector2(0, 1); }
        public: static Vector2 Down() { return Vector2(0, -1); }
    };

    class Snake : public RenderComponent::IRenderable
    {
        public: Vector2 Position;
        public: Vector2 Direction;

        private: Vector2 lastDirection;

        public: Vector2 *TilePositions;

        public: Snake();
        public: void OnRender(Adafruit_SSD1306 display) override;
    };
}