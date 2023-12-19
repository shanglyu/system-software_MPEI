#ifndef BOOK_H
#define BOOK_H

// Book class
class Book {
public:
    virtual void printInfo() = 0;
    virtual ~Book() {}
};

#endif // BOOK_H