#include "logger.hpp"

using namespace std;

void Logger::Error(std::string msg)
{
    clog << "Error: " << msg << endl;
    exit(EXIT_FAILURE);
}

void Logger::Notice(std::string msg)
{
    clog << msg << endl;
}
