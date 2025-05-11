#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int recordNumber;
    cout << "Enter the record number you want to read: ";
    cin >> recordNumber;

    ifstream inFile("data_record.txt");
    if (!inFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int currentLine = 1;
    bool found = false;

    while (getline(inFile, line))
    {
        if (currentLine == recordNumber)
        {
            cout << line << endl;
            found = true;
            break;
        }
        currentLine++;
    }

    if (!found)
    {
        cout << "Record " << recordNumber << " not found in the file." << endl;
    }

    inFile.close();
    return 0;
}
