#include <iostream>
using namespace std;

class MatrixHelper;

class Matrix2x2
{
private:
    int a, b, c, d;

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0)
        : a(a), b(b), c(c), d(d) {}

    Matrix2x2 operator+(const Matrix2x2 &m) const
    {
        return Matrix2x2(a + m.a, b + m.b, c + m.c, d + m.d);
    }

    Matrix2x2 operator-(const Matrix2x2 &m) const
    {
        return Matrix2x2(a - m.a, b - m.b, c - m.c, d - m.d);
    }

    Matrix2x2 operator*(const Matrix2x2 &m) const
    {
        return Matrix2x2(
            a * m.a + b * m.c,
            a * m.b + b * m.d,
            c * m.a + d * m.c,
            c * m.b + d * m.d);
    }

    friend int determinant(const Matrix2x2 &m);

    friend class MatrixHelper;

    friend ostream &operator<<(ostream &os, const Matrix2x2 &m)
    {
        os << "[ " << m.a << " " << m.b << " ]\n";
        os << "[ " << m.c << " " << m.d << " ]";
        return os;
    }
};

class MatrixHelper
{
public:
    void updateElement(Matrix2x2 &m, int row, int col, int value)
    {
        if (row == 0 && col == 0)
            m.a = value;
        else if (row == 0 && col == 1)
            m.b = value;
        else if (row == 1 && col == 0)
            m.c = value;
        else if (row == 1 && col == 1)
            m.d = value;
        else
            cout << "Invalid index!" << endl;
    }
};

int determinant(const Matrix2x2 &m)
{
    return m.a * m.d - m.b * m.c;
}

int main()
{
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1:\n"
         << m1 << "\n\n";
    cout << "Matrix 2:\n"
         << m2 << "\n\n";

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 prod = m1 * m2;

    cout << "Addition:\n"
         << sum << "\n\n";
    cout << "Subtraction:\n"
         << diff << "\n\n";
    cout << "Multiplication:\n"
         << prod << "\n\n";

    cout << "Determinant of Matrix 1: " << determinant(m1) << endl;
    cout << "Determinant of Matrix 2: " << determinant(m2) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 1, 1, 10);

    cout << "\nMatrix 1 after update:\n"
         << m1 << endl;

    return 0;
}
