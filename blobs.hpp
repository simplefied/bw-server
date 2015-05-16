#ifndef BLOBS_H
#define BLOBS_H

#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cfloat>
#include <cstdlib>
#include "configs.hpp"
#include "vectors.hpp"

namespace Blobs {
    class Blob
    {
    public:
        virtual ~Blob() = default;
        point2f Position() const;
        void CorrectPosition(vector2f offset);
        float Size() const;
    protected:
        Blob(point2f position, float size);
        point2f position_;
        float size_;
    };

    class Movable_Blob : public Blob
    {
    public:
        virtual ~Movable_Blob() = default;
        vector2f &Direction();
        void Step();
    protected:
        Movable_Blob(point2f position, float size);
        vector2f direction_;
    };

    class Meat : public Blob
    {
    public:
        Meat(point2f position);
    };

    class Player : public Movable_Blob
    {
    public:
        Player(point2f position, const std::string &name);
        const std::string &Name() const;
        const time_t &BornTime() const;
        void Heal(float eat_size);
        void Eat(float eat_size);
    private:
        std::string name_;
        time_t born_time_;
    };

    class Poison : public Movable_Blob
    {
    public:
        Poison(point2f position, float size);
        std::string &Target();
    private:
        std::string target_;
    };
}

#endif // BLOBS_H
