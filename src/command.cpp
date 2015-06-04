#include "command.hpp"

using namespace std;

Command::Command(string &str)
{
    vector<boost::iterator_range<string::iterator>> cmd_temp; // Boost ugly code, it's not mine
    boost::split(cmd_temp, str, boost::is_space(), boost::token_compress_on);
    for (auto part : cmd_temp)
    {
        cmd.push_back(string(part.begin(), part.end()));
    }
}

Command::Command(std::vector<string> str)
{
    cmd = str;
}

Command Command::Params() const
{
    return Command(vector<string>(cmd.begin() + 1, cmd.end()));
}

const std::string &Command::operator[](uint8_t n) const
{
    return cmd[n];
}

size_t Command::Size() const
{
    return cmd.size();
}

