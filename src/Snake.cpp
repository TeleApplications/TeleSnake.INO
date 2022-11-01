#include <Arduino.h>
#include "Snake.h"
 
namespace src
{
    Snake::Snake()
    {
        TilePositions = new Vector2[6];
        //Serial.println("Snake created");
    }

    void Snake::OnRender(Adafruit_SSD1306 display)
    {
        Position.X -= 1;
        int length = sizeof(&TilePositions);
        Serial.println(length);

        for (int i = 5; i > 0; i--)
        {
            auto nextPosition = TilePositions[i - 1];
            TilePositions[i] = nextPosition;

            auto currentPosition = TilePositions[i];
            display.writePixel(currentPosition.X, currentPosition.Y, SSD1306_WHITE);
        }

        TilePositions[0] = Position;

        //Serial.println(TilePositions[0].X);
        display.writePixel(TilePositions[0].X, TilePositions[0].Y, SSD1306_WHITE);
    }
}