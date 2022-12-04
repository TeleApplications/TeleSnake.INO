#include <Arduino.h>
#include "Snake.h"
 
namespace src
{
    Snake::Snake()
    {
        TilePositions = new Vector2[12];
        Direction = src::Vector2::Right();
    }

    void Snake::OnRender(Adafruit_SSD1306 display)
    {
        Position.X += Direction.X;
        Position.Y += Direction.Y;

        int length = 12;
        //Serial.write("Render");
        for (int i = length - 1; i > 0; i--)
        {
            auto currentPosition = TilePositions[i - 1];

            auto oldPosition = TilePositions[i];
            TilePositions[i] = currentPosition;

            //oldPosition -= currentPosition;
            int indexX = CalculateIndex(currentPosition.X - oldPosition.X);
            Serial.print(indexX);
            int indexY = CalculateIndex(currentPosition.Y - oldPosition.Y);
            DrawTile(display, currentPosition, 1, src::Vector2(Direction.X * i , 0));

            //display.writePixel(currentPosition.X, currentPosition.Y, SSD1306_WHITE);
        }

        TilePositions[0] = Position;
        //DrawTile(display, TilePositions[0], 4, src::Vector2(1, 1)); 
    }

    int Snake::CalculateIndex(int value)
    {
        //Serial.write(value);
        //int devideIndex = 1 >> (value & (value / 2));
        //Serial.write(returnValue);

        if(value == 0)
            return value;

        int absValue = value > 0 ? value : value * -1;
        int returnValue = absValue / value;
        return returnValue;
    }

    void Snake::DrawTile(Adafruit_SSD1306 display, Vector2 position, int size, Vector2 offset)
    {
        for (int i = 0; i < size; i++)
        {
            int currentY = position.Y + (i + (offset.Y * size));
            for (int j = 0; j < size; j++)
            {
                int currentX = position.X + (j + (offset.X * size));
                display.writePixel(currentX, currentY, SSD1306_WHITE);
            }
        }
    }
}