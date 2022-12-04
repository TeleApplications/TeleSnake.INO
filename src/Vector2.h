#include <Arduino.h>

#pragma once
namespace src
{
    class Vector2
    {
        public: int X = 0;
        public: int Y = 0;

        public: Vector2();

        public: Vector2(int x, int y);

        public: Vector2* operator+=(const src::Vector2 vector);

        public: Vector2* operator-=(const src::Vector2 vector);

        public: static Vector2 Left() { return Vector2(-1, 0); }
        public: static Vector2 Right() { return Vector2(1, 0); }
        public: static Vector2 Up() { return Vector2(0, 1); }
        public: static Vector2 Down() { return Vector2(0, -1); }
    };
}