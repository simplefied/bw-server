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
        virtual point2f Position() const = 0;
        virtual float Size() const = 0;
        virtual ~Blob() = default;
    };

    class Meat : public Blob
    {
    public:
        Meat(point2f position);
        virtual point2f Position() const;
        virtual float Size() const;
    private:
        point2f pos;
        float size;
    };

    class Player : public Blob
    {
    public:
        Player(point2f position, const std::string &pname);
        virtual point2f Position() const;
        virtual float Size() const;
        vector2f &Direction();
        const std::string &Name() const;
        const time_t &BornTime() const;
        void CorrectPosition(vector2f offset);
        void Heal(float eat_size);
        void Eat(float eat_size);
        void Step();
    private:
        std::string name;
        point2f pos;
        vector2f dir;
        float size;
        time_t born_time;
    };

    class Poison : public Blob
    {
    public:
        Poison(point2f position, float psize);
        virtual point2f Position() const;
        virtual float Size() const;
        vector2f &Direction();
        std::string &Target();
        void Step();
    private:
        std::string target;
        point2f pos;
        vector2f dir;
        float size;
    };
}

#endif // BLOBS_H
