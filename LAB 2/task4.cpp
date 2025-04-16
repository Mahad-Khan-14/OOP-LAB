#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    string *arr = new string[n];

    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, arr[i]);
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {

                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted strings:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;

    return 0;
}
