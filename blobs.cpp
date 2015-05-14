#include "blobs.hpp"

using namespace std;

Blobs::Meat::Meat(point2f position) : pos(position)
{
    size = Configs::GetFloat("meats_size");
}

point2f Blobs::Meat::Position() const
{
    return pos;
}

float Blobs::Meat::Size() const
{
    return size;
}

Blobs::Player::Player(point2f position, const std::string &pname) : name(pname), pos(position)
{
    size = Configs::GetFloat("players_min_size");
    born_time = time(nullptr);
}

point2f Blobs::Player::Position() const
{
    return pos;
}

float Blobs::Player::Size() const
{
    return size;
}

vector2f &Blobs::Player::Direction()
{
    return dir;
}

const std::string &Blobs::Player::Name() const
{
    return name;
}

const time_t &Blobs::Player::BornTime() const
{
    return born_time;
}

void Blobs::Player::CorrectPosition(vector2f offset)
{
    if (offset.length() > size) return;
    pos += offset;
}

void Blobs::Player::Heal(float eat_size)
{
    this->size = static_cast<float>(sqrt(max(1.0, pow(this->size, 2) - pow(eat_size, 2))));
}

void Blobs::Player::Eat(float eat_size)
{
    this->size = static_cast<float>(sqrt(pow(this->size, 2) + pow(eat_size, 2)));
}

void Blobs::Player::Step()
{
    pos += dir*Configs::GetFloat("speed_factor")*(1.0 - size/Configs::GetFloat("players_max_size"));
}


Blobs::Poison::Poison(point2f position, float psize) : pos(position), size(psize)
{

}

point2f Blobs::Poison::Position() const
{
    return pos;
}

float Blobs::Poison::Size() const
{
    return size;
}

vector2f &Blobs::Poison::Direction()
{
    return dir;
}

string &Blobs::Poison::Target()
{
    return target;
}

void Blobs::Poison::Step()
{
    pos += dir*Configs::GetFloat("speed_factor")*(1.0 - size/Configs::GetFloat("players_max_size"));
}
