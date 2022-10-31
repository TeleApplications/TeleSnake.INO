#pragma once
namespace src
{
    template <class T>
    class ICollection 
    {
        private: int count;
        public: T *CurrentData;

        public: List(int bufferSize = 32);

        public: T operator[](int index);
    };
}