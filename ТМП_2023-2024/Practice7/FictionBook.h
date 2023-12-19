#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include "Book.h"

class FictionBook : public Book {
public:
    void printInfo() override;
};

#endif // FICTIONBOOK_H