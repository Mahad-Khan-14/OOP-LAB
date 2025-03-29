#include <iostream>
#include <cstring>

using namespace std;

class Apartment
{
private:
    int id;
    string address;
    char *ownerName; // Dynamically allocated owner's name

public:
    Apartment(int _id, string _address, const char *_ownerName)
        : id(_id), address(_address)
    {
        ownerName = new char[strlen(_ownerName) + 1];
        strcpy(ownerName, _ownerName);
    }

    Apartment(const Apartment &other)
        : id(other.id), address(other.address), ownerName(other.ownerName)
    {
        // Only the reference to owner's name is copied (Shallow Copy)
    }

    ~Apartment()
    {
        delete[] ownerName;
    }

    void display() const
    {
        cout << "Apartment ID: " << id << "\n"
             << "Address: " << address << "\n"
             << "Owner: " << ownerName << "\n"
             << "--------------------------\n";
    }
};

int main()
{
    Apartment apt1(101, "123 Main St", "Alice");

    Apartment apt2(apt1);

    cout << "Original Apartment:\n";
    apt1.display();

    cout << "Copied Apartment (New Agent Handling):\n";
    apt2.display();

    return 0;
}
