#include <Arduino.h>
#include <math.h>
#include "Snake.h"
 
namespace src
{
    Snake::Snake()
    {
        TilePositions = new Vector2[3];
        Direction = src::Vector2::Right();
    }

    void Snake::OnRender(Adafruit_SSD1306 display)
    {
        Position.X += Direction.X;
        Position.Y += Direction.Y;

        int length = 3;
        for (int i = length - 1; i > 0; i--)
        {
            auto currentPosition = TilePositions[i - 1];

            auto oldPosition = TilePositions[i];
            TilePositions[i] = currentPosition;

            oldPosition -= currentPosition;
            int indexX = abs(oldPosition.X) / (oldPosition.X * -1);
            int indexY = abs(oldPosition.Y) / (oldPosition.Y * -1);

            DrawTile(display, currentPosition, 4, src::Vector2(indexX, indexY));
        }

        TilePositions[0] = Position;
        //DrawTile(display, TilePositions[0], 4, src::Vector2(1, 1)); 
    }

    void Snake::DrawTile(Adafruit_SSD1306 display, Vector2 position, int size, Vector2 offset)
    {
        for (int i = 0; i < size; i++)
        {
            int currentY = i + position.Y;
            for (int j = 0; j < size; j++)
            {
                int currentX = j + position.X;
                display.writePixel(currentX * offset.X, currentY * offset.Y, SSD1306_WHITE);
            }
        }
    }
}