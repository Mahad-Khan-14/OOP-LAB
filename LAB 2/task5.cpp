#include <iostream>
#include <string>
using namespace std;

int *arrayAllocation(int size)
{
    int *arr = new int[size];
    return arr;
}

void deallocateArray(int *arr)
{
    delete[] arr;
    cout << "arrayDeallocation successful" << endl;
}

void inputArray(int size, int *arr)
{
    cout << "Enter elements of Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> *(arr + i);
    }
}

void DisplayMatrix(int *arr, int size)
{
    cout << "Array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int SumArray(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}

int main()
{
    int size;
    cout << "Enter the no. of elements you want in your array: " << endl;
    cin >> size;

    int *array1 = arrayAllocation(size);

    inputArray(size, array1);
    DisplayMatrix(array1, size);

    int sum1 = SumArray(array1, size);
    cout << "The sum of Array1: " << sum1 << endl;

    deallocateArray(array1);

    return 0;
}