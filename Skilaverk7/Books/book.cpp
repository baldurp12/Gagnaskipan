#include "book.h"

Book::Book()
{
    cout << "Enter author: " << endl;
    cin >> author;
    cout << "Enter title: " << endl;
    cin >> title;
    cout << "Enter date " << endl;
    cin >> date;
}

Book::Book(string anAuthor, string aTitle, string aDate)
{
    author = anAuthor;
    title = aTitle;
    date = aDate;

}
string Book::getAuthor() const
{
    return author;
}

string Book::getTitle() const
{
    return title;
}
string Book::getDate() const
{
    return date;
}
bool operator <(const Book &book1, const Book &book2)
{
    return (book1.getAuthor() < book2.getAuthor());
}
