#include "iostream"
#include "fstream"
#include "string"
using namespace std;

class student
{
public:
    int rollno;
    string name;
    float marks;
};

void writeTofile()
{
    ofstream openFile;
    openFile.open("student.txt", ios::app);

    student s;
    cout << "Enter your roll no";
    cin >> s.rollno;
    cin.ignore();
    cout << "Enter your Name";
    getline(cin, s.name);
    cout << "Enter your marks";
    cin >> s.marks;

    if (openFile.is_open())
    {
        openFile << s.rollno << ", " << s.name << ", " << ", " << s.marks << endl;
        openFile.close();
        cout << "Data successfully written to file!!\n";
    }
    else
    {
        cout << "Unable to open the file for writing\n";
    }
}

void ReadFromFile()
{
    ifstream readfile;
    readfile.open("student.txt");
    string str;

    cout << "........Student records..........\n" << endl;
    if (readfile.is_open())
    {

        while (getline(readfile, str))
        {
            cout << str << endl;
        }
        readfile.close();
    }
    else
    {
        cout << "Unable to open the file for reading\n";
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\nRecord Data" << endl;
        cout << "1. Add student data\n";
        cout << "2. Show all Data\n";
        cout << "3. To Exit\n";

        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            writeTofile();
            break;
        case 2:
            ReadFromFile();
            break;
        case 3:
            cout << "Thank you!!.....Exiting!!\n";
            return 1;

        default:
            cout << "Invalid Choice!! << endl";
            break;
        }
    } while (choice != 3);

    return 0;
}