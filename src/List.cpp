#include "List.h"

namespace src
{
    template <typename T>
    List<T>::List(int bufferSize)
    {
        CurrentData = new T[bufferSize];
    }

    template <typename T>
    List<T>::List()
    {
        CurrentData = new T[1];
    }

    template <typename T>
    void List<T>::Add(T value)
    {
        int index = Count + 1;
        auto* newData = new T[index];

        memcpy(newData, CurrentData, Count);
        *newData[index] = value;
        CurrentData = newData;
        Count++;
    };

    template <typename T>
    void List<T>::Remove(T value)
    {
    }
};
