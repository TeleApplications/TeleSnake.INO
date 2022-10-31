#include <Arduino.h>
#include "Snake.h"
 
namespace src
{
    Snake::Snake()
    {
        TilePositions = new Vector2[3];
        Serial.println("Snake created");
    }

    void Snake::OnRender(Adafruit_SSD1306 display)
    {
        TilePositions[0] = Position;

        int length = sizeof(TilePositions) / sizeof(Vector2);

        for (int i = 2; i > 1; i--)
        {
            Serial.println(length);
            auto nextPosition = TilePositions[i - 1];
            TilePositions[i] = nextPosition;

            auto currentPosition = TilePositions[i];
            display.writePixel(currentPosition.X, currentPosition.Y, SSD1306_WHITE);
        }
    }
}