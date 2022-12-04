namespace src
{
    class Vector2D
    {
        public: int X = 0;
        public: int Y = 0;

        public: Vector2D()
        {
        };

        public: Vector2D(int x, int y)
        {
            X = x;
            Y = y;
        };

        public: Vector2D* operator+=(const src::Vector2D vector)
        {
            int finalX = X + vector.X;
            int finalY = Y + vector.Y;

            return new Vector2D(finalX, finalY);
        }

        public: Vector2D* operator-=(const src::Vector2D vector)
        {
            int finalX = X - vector.X;
            int finalY = Y - vector.Y;

            return new Vector2D(finalX, finalY);
        }

        public: static Vector2D Left() { return Vector2D(-1, 0); }
        public: static Vector2D Right() { return Vector2D(1, 0); }
        public: static Vector2D Up() { return Vector2D(0, 1); }
        public: static Vector2D Down() { return Vector2D(0, -1); }
    };
}