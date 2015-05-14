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
    static void Load(std::string path);
    static int GetInt(std::string name);
    static float GetFloat(std::string name);
private:
    Configs() = default;
    static std::map<std::string, int> ints;
    static std::map<std::string, float> floats;
};

#endif // CONFIGS_H
