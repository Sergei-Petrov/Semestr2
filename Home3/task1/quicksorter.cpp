#include "quicksorter.h"

int *QuickSorter::sort(int *array, int length)
{
    qSort(array, 0, length - 1);
    return array;
}

void QuickSorter::qSort(int *array, int left, int right)
{
    if(left < right)
    {
        int point = array[left];
        int i = left;
        int j = right;
        while(i < j)
        {
            while(array[i] <= point && i < right)
                i++;
            while(array[j] >= point && j > left)
                j--;
            if(i < j)
                swap(array[i], array[j]);
        }
        swap(array[left], array[j]);
        qSort(array, left, j - 1);
        qSort(array, j + 1, right);
    }
}
