#pragma once
#include "Comparative.h"

/// Bubblesort
template <typename T, typename L>
class BubbleSorter
{
public:
    /**
          *
          *@ param array - array is passed to sort
          *@ param length - length of array is passed to sort
          */
    void sort(T *array, int length, L *comp);
};

template <typename T, typename L>
void BubbleSorter<T, L>::sort(T *array, int length, L *comp)
{
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i = 0; i < length - 1; i++)
        {
            if (comp->comp(array[i], array[i+1]))
            {
                T tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
                flag = true;
            }
        }
    }
}
