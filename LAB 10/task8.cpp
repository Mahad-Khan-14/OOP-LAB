#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile("config.txt");

    if (!outFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string data1 = "AAAAABBBBBCCCCC";

    outFile << data1;
    outFile.close();

    fstream File("config.txt", ios::in | ios::out);
    if (!File)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    File.seekp(5);
    File.write("XXXXX", 5);

    File.seekg(0);
    string word;
    File >> word;
    cout << "Updated File content: " << word << endl;
    File.close();
    return 0;
}
