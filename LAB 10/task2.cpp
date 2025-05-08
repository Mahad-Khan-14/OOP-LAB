#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
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

                cout << "Original Line: " << line << endl;

                istringstream str(line);

                string type, id, name, year, extra, cert;
                getline(str, type, ',');
                getline(str, id, ',');
                getline(str, name, ',');
                getline(str, year, ',');
                getline(str, extra, ',');
                getline(str, cert, ',');

                cout << "Type: " << type << endl;
                cout << "ID: " << id << endl;
                cout << "Name: " << name << endl;
                cout << "Year: " << year << endl;
                cout << "Extra Data: " << extra << endl;
                cout << "Certification: " << cert << endl;
                cout << "-----------------------------\n";
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