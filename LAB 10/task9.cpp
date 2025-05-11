#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile;

    inFile.open("large_log.txt");
    if (!inFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;
        cout << "Position after reading line: " << inFile.tellg() << endl;
    }

    inFile.close();

    return 0;
}
