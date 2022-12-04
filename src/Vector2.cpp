#include "Vector2.h"

namespace src
{
    Vector2::Vector2() 
    {
    }

    Vector2::Vector2(int x, int y)
    {
        X = x;
        Y = y;
    }

    Vector2* Vector2::operator+=(const src::Vector2 vector)
    {
        int finalX = X + vector.X;
        int finalY = Y + vector.Y;

        return new Vector2(finalX, finalY);
    }

    Vector2* Vector2::operator-=(const src::Vector2 vector)
    {
        int finalX = X - vector.X;
        int finalY = Y - vector.Y;

        return new Vector2(finalX, finalY);
    }
}