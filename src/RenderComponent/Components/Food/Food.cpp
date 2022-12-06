#include "Food.h"

namespace src
{
    Food::Food() { Position = Vector2(5, 5);}

    void Food::OnRender(Adafruit_SSD1306 display)
    {
        //display.drawChar(Position.X, Position.Y, foodCharacter, SSD1306_WHITE, SSD1306_WHITE, 1);
        display.writePixel(Position.X, Position.Y, SSD1306_WHITE);
    }

}