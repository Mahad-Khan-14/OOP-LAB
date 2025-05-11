// #include "iostream"
// using namespace std;

// template <typename T, typename U>
// void printValue(T value1, U value2)
// {
//     cout << "sum of integer and double is: " << value1 + value2 << endl;
// }

// template <typename T>
// void printValue(T value1)
// {
//     cout << "Value: " << value1 << endl;
// }

// int main()
// {
//     int intval = 44;
//     double doubleval = 3.14;
//     char charValue = 'C';

//     printValue(intval, doubleval);
//     printValue(doubleval);
//     printValue(charValue);

//     return 0;
// }

// #include "iostream"
// using namespace std;

// template <typename T>
// T MaxElement(T *array, T size)
// {
//     T max = array[0];
//     for (int i = 1; i < size; i++)
//     {
//         if (array[i] > max)
//         {
//             max = array[i];
//         }
//     }
//     return max;
// }

// int main()
// {
//     int intarr[] = {1, 3, 5, 7, 9, 14};
//     double doublearr[] = {3.14, 1.75, 2.56, 9.01, 0.11};

//     int MAXINT = MaxElement(intarr, 6);
//     double MAXDOUBLE = MaxElement(doublearr, 5.0);

//     cout << "Max Element in IntArray is: " << MAXINT << endl;
//     cout << "Max Element in DoubleArray is: " << MAXDOUBLE << endl;

//     return 0;
// }

// #include "iostream"
// using namespace std;

// template <typename T>
// class WeatherData{
//     private:
//     T temperature;
//     T humidity;
//     T Air_pressure;

//     public:
//     WeatherData(T temp, T hum, T air): temperature(temp), humidity(hum), Air_pressure(air) {}

//     void PrintData() const {
//         cout << "Temperature: " << temperature << " 'C" << endl;
//         cout << "Humidity: " << humidity << " %" << endl;
//         cout << "Air Pressure: "<< Air_pressure << " Kpa" << endl;
//     }
// };

// int main()
// {
//     WeatherData<int> data1(35, 24, 100);
//     data1.PrintData();

//     cout << "------------------------" << endl;

//     WeatherData<double> data2(35.5, 24.1, 100.98);
//     data2.PrintData();

//     return 0;
// }

#include "iostream"
using namespace std;

template <typename T>
class Division
{
public:
    void Divide(T a, T b)
    {
        try
        {
            if (!b)
            {
                throw b;
            }
            cout << "result: " << a / b << endl;
        }
        catch (T b)
        {
            cout << "Cannot divide by zero!!" << endl;
        }
    }
};

int main()
{
    Division<int> data1;
    data1.Divide(14, 0);

    cout << "------------------------" << endl;

    Division<double> data2;
    data2.Divide(14.44, 14.43);

    cout << "------------------------" << endl;

    Division<float> data3;
    data2.Divide(0.44, 0.0);

    return 0;
}
