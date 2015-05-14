#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

class Command
{
public:
    Command(std::string &str);
    Command(std::vector<std::string> str);
    Command Params() const;
    const std::string &operator[](std::uint8_t n) const;
    std::size_t Size() const;
private:
    std::vector<std::string> cmd;
};

#endif // COMMAND_H
