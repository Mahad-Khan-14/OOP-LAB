#include <iostream>
using namespace std;

int **allocateMatrix(int rows, int cols)
{
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[cols];
    return matrix;
}

void deallocateMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

void inputMatrix(int **matrix, int rows, int cols, const string &name)
{
    cout << "Enter elements of " << name << " matrix:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            cout << name << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
}

void displayMatrix(int **matrix, int rows, int cols, const string &name)
{
    cout << name << " matrix:\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int **matrixA = allocateMatrix(rows, cols);
    int **matrixB = allocateMatrix(rows, cols);
    int **matrixSum = allocateMatrix(rows, cols);
    int **matrixDiff = allocateMatrix(rows, cols);

    inputMatrix(matrixA, rows, cols, "Matrix A");
    inputMatrix(matrixB, rows, cols, "Matrix B");

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
            matrixDiff[i][j] = matrixA[i][j] - matrixB[i][j];
        }

    displayMatrix(matrixSum, rows, cols, "Sum");
    displayMatrix(matrixDiff, rows, cols, "Difference");

    deallocateMatrix(matrixA, rows);
    deallocateMatrix(matrixB, rows);
    deallocateMatrix(matrixSum, rows);
    deallocateMatrix(matrixDiff, rows);

    return 0;
}
