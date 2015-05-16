#include "configs.hpp"

using namespace std;

void Configs::Load(string path)
{
    // TODO migrate configs to third-party lib?
    ifstream file(path);
    // TODO check for file exist (Boost Filesystem?)
    while (file) {
        string str;
        getline(file, str);
        if (str.empty()) continue;
        if (str[0] == '#') continue;
        char name_buf[50], arg_buf[50];
        if(sscanf(str.c_str(), "%s \"%[^\"]\"", name_buf, arg_buf) != 2) {
            Logger::Error("Bad line in config file: " + str);
            continue;
        }
        string name(name_buf), arg(arg_buf);
        if (arg.find_first_of('.') != -1) {
            try {
                float float_arg = stof(arg);
                floats[name] = float_arg;
            }
            catch (...) {
                Logger::Error("Bad argument in config file: " + str);
            }
        } else {
            try {
                int int_arg = stoi(arg);
                ints[name] = int_arg;
            }
            catch (...) {
                Logger::Error("Bad argument in config file: " + str);
            }
        }
    }
}

int Configs::Int(string name)
{
    if (!ints.count(name)) {
        Logger::Error(name + " parameter isn't present in config file.");
    }
    return ints[name];
}

float Configs::Float(string name)
{
    if (!floats.count(name)) {
        Logger::Error(name + " parameter isn't present in config file.");
    }
    return floats[name];
}

map<string, int> Configs::ints;
map<string, float> Configs::floats;
