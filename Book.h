#include <cstdlib>
#include <iostream>
#include <string>

class Book
{
private:
public:
    std::string author;
    std::string category;
    int numberOfPages;
    bool isBorrowed;
    Book() = default;
    Book(std::string newAuthor, std::string newCategory, int newNumberOfPages, bool newIsBorrowed);
    ~Book() = default;
    friend std::ostream &operator<<(std::ostream &out, const Book &Book);
};

Book::Book(std::string newAuthor, std::string newCategory, int newNumberOfPages, bool newIsBorrowed)
    : author(newAuthor), category(newCategory), numberOfPages(newNumberOfPages), isBorrowed(newIsBorrowed) {}

std::ostream &operator<<(std::ostream &out, const Book &Book)
{
    out << "Author: " << Book.author << ", Category: " << Book.category << ", Number of Pages: " << Book.numberOfPages << ", Status:";
    if (Book.isBorrowed)
    {
        out << "Borrowed";
    }
    else
    {
        out << "On the bookshelf";
    }
    return out;
}