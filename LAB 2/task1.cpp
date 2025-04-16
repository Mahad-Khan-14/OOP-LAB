#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    string author;
    int year;
};

int main()
{
    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;

    Book *books = new Book[numBooks];

    cin.ignore();

    for (int i = 0; i < numBooks; ++i)
    {
        cout << "\nEnter details for book " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Year of Publication: ";
        cin >> books[i].year;
        cin.ignore();
    }

    int specificYear;
    cout << "\nEnter a specific year to display books published after it: ";
    cin >> specificYear;

    cout << "\nBooks published after " << specificYear << ":\n";
    bool found = false;
    for (int i = 0; i < numBooks; ++i)
    {
        if (books[i].year > specificYear)
        {
            cout << "\nTitle: " << books[i].title
                 << "\nAuthor: " << books[i].author
                 << "\nYear: " << books[i].year << "\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No books found published after " << specificYear << ".\n";
    }

    delete[] books;

    return 0;
}
