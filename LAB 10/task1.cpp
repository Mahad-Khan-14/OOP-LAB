#include "iostream"
#include "fstream"
#include "string"
using namespace std;

class cardealer
{
private:
    string filename;

public:
    cardealer(const string &name) : filename(name) {}

    void readdata()
    {
        ifstream in(filename);
        string line;
        cout << "Reading file " << filename << endl;
        if (in.is_open())
        {
            while (getline(in, line))
            {
                if (line.empty() || line.substr(0, 2) == "//")
                {
                    continue;
                }

                cout << line << endl;
            }
            in.close();
        }
        else
        {
            cout << "File could not be able to open for reading" << endl;
        }
    }
};

int main()
{
    cardealer vehicle("vehicle.txt");
    vehicle.readdata();
    return 0;
}