#include <Arduino.h>
#include "RenderComponent\Components\Snake\Snake.h"
 
namespace src
{
    Snake::Snake()
    {
        TilePositions = new Vector2[32];
        Direction = Vector2::Right();
    }

    void Snake::OnRender(Adafruit_SSD1306 display)
    {
        Position.X += Direction.X;
        Position.Y += Direction.Y;

        //Serial.print(TileLength);
        for (int i = TileLength - 1; i > 0; i--)
        {
            auto currentPosition = TilePositions[i - 1];
            TilePositions[i] = currentPosition;
            Serial.println("X: " + currentPosition.X);
            Serial.println("Y: " + currentPosition.Y);

            DrawTile(display, currentPosition, 2, Vector2(0, 0));
        }
        //if(Position.X == FoodPosition.X && Position.Y == FoodPosition.Y)
        //{
            //FoodPosition = Vector2(RandomNext(0, 128), RandomNext(0, 64));
            //TileLength++;
        //}


        TilePositions[0] = Position;
        //display.drawChar(TilePositions[0].X, TilePositions[0].Y, 'O', SSD1306_BLACK, SSD1306_WHITE, 1);
        //display.drawChar(FoodPosition.X, FoodPosition.Y, '.', SSD1306_WHITE, SSD1306_WHITE, 1);
    }

    int Snake::RandomNext(int min, int max)
    {
        int maxValue = (max - min + 1);
        return min + (rand() % maxValue);
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