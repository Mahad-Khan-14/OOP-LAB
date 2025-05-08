#include "iostream"
#include "fstream"

/*
    useful classes for working with files are:
    . fstreambase
    . ofstream --> derived from fstreambase
    . ifstream --> derived from fstreambase
*/

using namespace std;

/*
    In order to work with files in C++, you have to open it. Primarily, there are two ways to open a file:
    . using the constructor
    . using the member function open() of the class
*/

int main()
{
    string str = "Mahad khan is geting written to the file";
    string str2;

    // opening file using constructor and writing in it
    ofstream out("write.txt"); // write operation
    out << str;

    // Binary file writing
    ofstream binary("binza.dat", ios::binary);
    binary.write((char *)&str, sizeof(str));

    // opening file using constructor and reading from it
    ifstream in("write.txt"); // read operation
    getline(in, str2);

    cout << str2;

    return 0;
}