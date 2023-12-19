#ifndef BOOKPROTOTYPEFACTORY_H
#define BOOKPROTOTYPEFACTORY_H

#include <string>
#include <unordered_map>
#include "Book.h"

class BookPrototypeFactory {
public:
    static Book* getBook(const std::string& type);

private:
    static std::unordered_map<std::string, Book*> bookCache;
};

#endif // BOOKPROTOTYPEFACTORY_H