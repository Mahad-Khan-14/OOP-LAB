#include <iostream>
#include <string>
using namespace std;

class Library
{
private:
    string *bookList;
    string *borrowedBooks;
    string *availableBooks;
    int totalBooks;
    int totalBorrowed;
    int totalAvailable;
    int capacity;

public:
    Library(int size)
    {
        capacity = size;
        bookList = new string[capacity];
        borrowedBooks = new string[capacity];
        availableBooks = new string[capacity];
        totalBooks = totalBorrowed = totalAvailable = 0;
    }

    ~Library()
    {
        delete[] bookList;
        delete[] borrowedBooks;
        delete[] availableBooks;
    }

    void AddBook(const string &book)
    {
        if (totalBooks < capacity)
        {
            bookList[totalBooks++] = book;
            availableBooks[totalAvailable++] = book;
            cout << book << " added to the library.\n";
        }
        else
        {
            cout << "Library is full. Cannot add more books.\n";
        }
    }

    void LendBook(const string &book)
    {
        bool found = false;
        for (int i = 0; i < totalAvailable; ++i)
        {
            if (availableBooks[i] == book)
            {
                for (int j = i; j < totalAvailable - 1; ++j)
                    availableBooks[j] = availableBooks[j + 1];
                totalAvailable--;

                borrowedBooks[totalBorrowed++] = book;
                cout << book << " has been borrowed.\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << book << " is not available to borrow.\n";
    }

    void ReturnBook(const string &book)
    {
        bool found = false;
        for (int i = 0; i < totalBorrowed; ++i)
        {
            if (borrowedBooks[i] == book)
            {
                for (int j = i; j < totalBorrowed - 1; ++j)
                    borrowedBooks[j] = borrowedBooks[j + 1];
                totalBorrowed--;

                availableBooks[totalAvailable++] = book;
                cout << book << " has been returned.\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << book << " was not borrowed from this library.\n";
    }

    void DisplayStatus()
    {
        cout << "\nAll Books:\n";
        for (int i = 0; i < totalBooks; ++i)
            cout << "- " << bookList[i] << endl;

        cout << "\nAvailable Books:\n";
        for (int i = 0; i < totalAvailable; ++i)
            cout << "- " << availableBooks[i] << endl;

        cout << "\nBorrowed Books:\n";
        for (int i = 0; i < totalBorrowed; ++i)
            cout << "- " << borrowedBooks[i] << endl;
    }
};

int main()
{

    Library HamzaLib(5);

    HamzaLib.AddBook("C++ Programming");
    HamzaLib.AddBook("Data Structures");
    HamzaLib.AddBook("Operating Systems");
    HamzaLib.AddBook("Computer Networks");
    HamzaLib.AddBook("AI");
    HamzaLib.AddBook("Discrete Math");

    HamzaLib.LendBook("C++ Programming");
    HamzaLib.LendBook("AI");
    HamzaLib.ReturnBook("C++ Programming");
    HamzaLib.ReturnBook("Analytics");

    HamzaLib.DisplayStatus();

    return 0;
}
