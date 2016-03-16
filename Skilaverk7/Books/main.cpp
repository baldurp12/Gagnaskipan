// ****************************************************************
//
// This program implements an in-memory database of books using
// a vector and sorts them using the generic sort function from
// the algorithm library.
// ****************************************************************

#include <vector>
#include <algorithm>
#include "book.h"

using namespace std;

// Function prototypes
void AddNewBook(vector<Book> &bookdata);
void PrintBooks(vector<Book> &bookdata);
void SortBooks(vector<Book> &bookdata);
void PrintMenu();

int main()
{

    int choice = 1;
    vector<Book> bookVector;

  while (choice != 3){
        PrintMenu();
        cin >> choice;

        switch (choice)
        {
        case 1 :
            AddNewBook(bookVector);
            break;
        case 2 :
            PrintBooks(bookVector);
            break;
        case 3 :
            break;
        default:
            break;
        }
  }

}

void PrintMenu(){
    cout << "\nSelect from the following choices:" << endl;
    cout << "1. \t " << " Add new book" << endl;
    cout << "2. \t " << " Print list sorted by author" << endl;
    cout << "3. \t " << " Quit" << endl;
}

void AddNewBook(vector<Book> &bookdata)
{
    Book newBook;
    bookdata.push_back(newBook);
}

void PrintBooks(vector<Book> &bookdata)
{
    SortBooks(bookdata);
    vector<Book>::iterator it;
    cout << "\nThe books entered so far, sorted alphabetically by author are:" << endl;
    for (it = bookdata.begin(); it != bookdata.end(); ++it)
    {
        cout << "\t" << (it)->getAuthor();
        cout << ".\t" << (it)->getTitle();
        cout << ".\t" << (it)->getDate() << endl;
    }
}

void SortBooks(vector<Book> &bookdata)
{
    sort(bookdata.begin(), bookdata.end());
}
