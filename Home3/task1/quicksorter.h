#pragma once
#include "sorter.h"

class QuickSorter : public Sorter
{
public:
    int *sort(int *array, int length);
private:
    static void qSort(int *array, int left, int right);
};
