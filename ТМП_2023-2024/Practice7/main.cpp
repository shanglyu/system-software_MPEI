#include "Book.h"
#include "FictionBook.h"
#include "NonFictionBook.h"
#include "BookPrototypeFactory.h"
#include "Log.h"
#include <iostream> 

int main() {
    Log* logger = Log::getInstance();
    logger->writeLog("Program started");

    Book* book1 = BookPrototypeFactory::getBook("fiction");
    if (book1) {
        book1->printInfo(); // Fiction Book
        logger->writeLog("Fiction book created");
    }

    Book* book2 = BookPrototypeFactory::getBook("nonfiction");
    if (book2) {
        book2->printInfo(); // Non-Fiction Book
        logger->writeLog("Non-fiction book created");
    }

    Book* book3 = BookPrototypeFactory::getBook("biography");
    if (book3) {
        book3->printInfo();
    } else {
        std::cout << "Invalid book type." << std::endl;
        logger->writeLog("Invalid book type requested");
    }

    delete book1;
    delete book2;

    logger->writeLog("Program ended");

    delete logger;

    return 0;
}