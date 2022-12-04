#include "Food.h"

namespace src
{
    Food::Food() { }

    void Food::OnRender(Adafruit_SSD1306 display)
    {
        display.drawChar(Position.X, Position.Y, foodCharacter, SSD1306_WHITE, SSD1306_WHITE, 1);
    }

}