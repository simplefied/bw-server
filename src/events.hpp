#ifndef EVENTS_H
#define EVENTS_H

#include <ctime>
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
        Birth(Birth&) = delete;
        Birth(Birth&&) = delete;
        Birth& operator=(const Birth&) = delete;
        Birth& operator=(Birth&&) = delete;
        virtual std::string Who();
        virtual void Do(Command cmd);
    private:
        World &aworld;
    };

    class Turn : public IEvent
    {
    public:
        Turn(World &world);
        Turn(Turn&) = delete;
        Turn(Turn&&) = delete;
        Turn& operator=(const Turn&) = delete;
        Turn& operator=(Turn&&) = delete;
        virtual std::string Who();
        virtual void Do(Command cmd);
    private:
        World &aworld;
    };
}

#endif // EVENTS_H
