#pragma once

namespace src
{
    template <typename T>
    class List
    {
        public: int Count = 1;
        public: T *CurrentData;

        public: List(int bufferSize);
        public: List();

        public: void Add(T value);
        public: void Remove(T value);

    };
}
 