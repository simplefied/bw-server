#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <cstdlib>

class Logger
{
public:
    Logger() = delete;
    static void Error(std::string msg);
    static void Notice(std::string msg);
};

#endif // LOGGER_H
