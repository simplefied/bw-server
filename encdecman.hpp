#ifndef ADAPTER_H
#define ADAPTER_H

#include <map>
#include <utility>
#include <string>
#include <cstdio>
#include "configs.hpp"
#include "logger.hpp"
#include "command.hpp"
#include "world.hpp"
#include "events.hpp"

#define PROTOCOL_VERSION "0.3"

class EncDecManager
{
public:
    EncDecManager(World &world_);
    EncDecManager(EncDecManager&) = delete;
    EncDecManager(EncDecManager&&) = delete;
    EncDecManager& operator=(const EncDecManager&) = delete;
    EncDecManager& operator=(EncDecManager&&) = delete;
    void Decode(std::string &msg);
    std::string Encode();
private:
    void Register(Events::IEvent *event);
    std::map<std::string, Events::IEvent*> events;
    World &world_;
};

#endif // ADAPTER_H
