#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <cstdlib>

class Logger
{
public:
    static void Error(std::string msg);
    static void Notice(std::string msg);
private:
    Logger();
};

#endif // LOGGER_H
