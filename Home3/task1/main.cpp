#include "bubblesorter.h"
#include "quicksorter.h"
#include "iostream"

using namespace std;

int main()
{
    Sorter *obj = new QuickSorter();
    int array[5];
    for(int i = 0; i < 5; i++)
        cin >> array[i];
    obj->sort(array, 5);
    for(int i = 0; i < 5; i++)
        cout << array[i] << " ";
    delete obj;
    return 0;
}
