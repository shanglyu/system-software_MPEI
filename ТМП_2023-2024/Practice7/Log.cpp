#include "Log.h"
#include <iostream>

Log* Log::instance = nullptr;

Log* Log::getInstance() {
    if (!instance) {
        instance = new Log();
    }
    return instance;
}

void Log::writeLog(const std::string& message) {
    std::cout << "Logging: " << message << std::endl;
    
}