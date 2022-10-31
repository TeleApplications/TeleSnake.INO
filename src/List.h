#include "ICollection.h"

#pragma once

namespace src
{
    template <class T>
    class List : public ICollection
    {
        public: List(int bufferSize = 32);

        public: void Add(T value);
        public: void Remove(T value);
    };
}
 