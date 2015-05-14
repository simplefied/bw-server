#ifndef EVENTS_H
#define EVENTS_H

#include <cstdio>
#include <cstdlib>
#include "command.hpp"
#include "world.hpp"

namespace Events{
    class IEvent
    {
    public:
        virtual std::string Who() = 0;
        virtual void Do(Command cmd) = 0;
        virtual ~IEvent() = default;
    };

    class Birth : public IEvent
    {
    public:
        Birth(World &world);
        virtual std::string Who();
        virtual void Do(Command cmd);
    private:
        World &aworld;
    };

    class Turn : public IEvent
    {
    public:
        Turn(World &world);
        virtual std::string Who();
        virtual void Do(Command cmd);
    private:
        World &aworld;
    };
}

#endif // EVENTS_H
