#include <Arduino.h>
#include "Snake.h"
 
namespace src
{
    Snake::Snake()
    {
        TilePositions = new Vector2[18];
        //Serial.println("Snake created");
    }

    void Snake::OnRender(Adafruit_SSD1306 display)
    {
        Position.X -= 1;

        int pointerLength = *(&TilePositions + 1);
        int length = pointerLength / sizeof(*TilePositions);

        for (int i = length - 1; i > 0; i--)
        {
            auto nextPosition = TilePositions[i - 1];
            TilePositions[i] = nextPosition;

            auto currentPosition = TilePositions[i];
            display.writePixel(currentPosition.X, currentPosition.Y, SSD1306_WHITE);
        }
        TilePositions[0] = Position;

        display.writePixel(TilePositions[0].X, TilePositions[0].Y, SSD1306_WHITE);
    }
}