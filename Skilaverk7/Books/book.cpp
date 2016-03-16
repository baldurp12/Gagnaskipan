#include "book.h"

Book::Book()
{
    cin.ignore();
    cout << "Enter author: " << endl;
    getline(cin, author);
    cout << "Enter title: " << endl;
    getline(cin, title);
    cout << "Enter date " << endl;
    getline(cin, date);
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
