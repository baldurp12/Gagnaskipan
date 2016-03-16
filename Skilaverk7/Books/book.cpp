#include "book.h"

Book::Book()
{
    
}

Book::Book(string anAuthor, string aTitle, string aDate)
{
    
}
string Book::getAuthor() const
{
    return 0;
}

string Book::getTitle() const
{
    return 0;
}
string Book::getDate() const
{
    return 0;
}
bool operator <(const Book &book1, const Book &book2)
{
    if(book1.getAuthor() < book2.getAuthor())
    {
        return true;
    }
    return false;
}
