#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem
{
public:
    int itemID;
    char itemName[20];

    InventoryItem(int id = 0, const char *name = "")
    {
        itemID = id;
        strncpy(itemName, name, sizeof(itemName) - 1);
        itemName[sizeof(itemName) - 1] = '\0';
    }

    void display() const
    {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
    }
};

int main()
{

    InventoryItem itemToWrite(101, "Laptop");

    ofstream outFile("inventory.dat", ios::binary);
    if (!outFile)
    {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile.write((char *)&itemToWrite, sizeof(itemToWrite));
    outFile.close();

    InventoryItem itemToRead;

    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile)
    {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    inFile.read((char *)&itemToRead, sizeof(itemToRead));
    inFile.close();

    cout << "Loaded Inventory Item from File:" << endl;
    itemToRead.display();

    return 0;
}
