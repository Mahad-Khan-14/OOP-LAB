#include <iostream>
using namespace std;

void inputMatrix(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> *(matrix + i * cols + j);
        }
    }
}

void displayMatrix(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << *(matrix + i * cols + j) << "\t";
        }
        cout << endl;
    }
}

void multiplyMatrices(int *A, int *B, int *C, int r1, int c1, int c2)
{
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            *(C + i * c2 + j) = 0;
            for (int k = 0; k < c1; ++k)
            {
                *(C + i * c2 + j) += (*(A + i * c1 + k)) * (*(B + k * c2 + j));
            }
        }
    }
}

int main()
{
    int r1, c1, r2, c2;

    cout << "Enter rows and columns for Matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns for Matrix B: ";
    cin >> r2 >> c2;

    if (c1 != r2)
    {
        cout << "Matrix multiplication not possible! (Columns of A must match rows of B)" << endl;
        return 1;
    }

    int *A = new int[r1 * c1];
    int *B = new int[r2 * c2];
    int *C = new int[r1 * c2];

    cout << "Enter elements for Matrix A:" << endl;
    inputMatrix(A, r1, c1);

    cout << "Enter elements for Matrix B:" << endl;
    inputMatrix(B, r2, c2);

    multiplyMatrices(A, B, C, r1, c1, c2);

    cout << "Result of Matrix Multiplication (A x B):" << endl;
    displayMatrix(C, r1, c2);

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
