#include "logger.hpp"

using namespace std;

void Logger::Error(std::string msg)
{
    cout << "Error: " << msg << endl;
    exit(EXIT_FAILURE);
}

void Logger::Notice(std::string msg)
{
    cout << msg << endl;
}
