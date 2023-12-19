#ifndef LOG_H
#define LOG_H

#include <string>

// Singleton logger class
class Log {
private:
    static Log* instance;
    Log() {} // Private constructor to prevent instantiation

public:
    static Log* getInstance();
    void writeLog(const std::string& message);
};

#endif // LOG_H