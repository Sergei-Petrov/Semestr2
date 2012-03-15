#include "bubblesorter.h"

int *BubbleSorter::sort(int *array, int length)
{
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i = 0; i < length - 1; i++)
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i+1]);
                flag = true;
            }
    }
    return array;
}
