#include <iostream>
using namespace std;

int main()
{
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    int **arr = new int *[size];

    for (int i = 0; i < size; ++i)
    {
        arr[i] = new int;
        cout << "Enter value for element " << i << ": ";
        cin >> *arr[i];
    }

    cout << "\nValues in the array:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << "Element " << i << " = " << *arr[i] << endl;
    }

    for (int i = 0; i < size; ++i)
    {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}
