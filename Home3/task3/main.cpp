#include "quickSorter.h"
#include "iostream"

using namespace std;

int main()
{
    Sorter *obj = new QuickSorter();
    int n = 0;
    int m = 0;
    cout << "Enter n and m" << endl;
    cin >> n >> m;
    cout << "Enter matrix" << endl;
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[j][i];

    obj->sort(matrix, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[j][i] << " ";
        cout << endl;
    }
    for (int i = 0; i < n; i++)
        delete [] matrix[i];
    delete [] matrix;
    delete obj;
    return 0;
}
