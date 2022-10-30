#include <Arduino.h>
#include "Snake.h"
 
namespace src
{
    void Snake::OnRender(Adafruit_SSD1306 display)
    {
        display.writePixel(X, Y, SSD1306_WHITE);

        X+=1;
        Y+=1;
    }
}