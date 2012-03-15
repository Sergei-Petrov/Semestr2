#pragma once
#include "sorter.h"

/// Quicksort

class QuickSorter : public Sorter
{
public:
    /// sends for qSort
    int *sort(int *array, int length);
private:
    /**
      * recursive sorting
      *@ param array - array is passed to sort
      *@ param left - pointer to beginning
      *@ param right - pointer to end
      */
    static void qSort(int *array, int left, int right);
};
