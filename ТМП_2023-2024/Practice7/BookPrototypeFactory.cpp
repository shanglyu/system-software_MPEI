#include "BookPrototypeFactory.h"
#include "FictionBook.h"
#include "NonFictionBook.h"

std::unordered_map<std::string, Book*> BookPrototypeFactory::bookCache;

Book* BookPrototypeFactory::getBook(const std::string& type) {
    if (bookCache.find(type) == bookCache.end()) {
        if (type == "fiction") {
            bookCache[type] = new FictionBook();
        } else if (type == "nonfiction") {
            bookCache[type] = new NonFictionBook();
        } else {
            return nullptr;
        }
    }
    return bookCache[type];
}