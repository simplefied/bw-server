#ifndef CONFIGS_H
#define CONFIGS_H

#include <fstream>
#include <cstdio>
#include <string>
#include <map>
#include "logger.hpp"

class Configs
{
public:
    Configs() = delete;
    static void Load(std::string path);
    static int Int(std::string name);
    static float Float(std::string name);
private:
    static std::map<std::string, int> ints;
    static std::map<std::string, float> floats;
};

#endif // CONFIGS_H
