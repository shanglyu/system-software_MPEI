#ifndef NONFICTIONBOOK_H
#define NONFICTIONBOOK_H

#include "Book.h"

// Concrete book class
class NonFictionBook : public Book {
public:
    void printInfo() override;
};

#endif // NONFICTIONBOOK_H