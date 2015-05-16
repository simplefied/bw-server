#include "blobs.hpp"

using namespace std;

Blobs::Blob::Blob(point2f position, float size) : position_(position), size_(size)
{
}

point2f Blobs::Blob::Position() const
{
    return position_;
}

void Blobs::Blob::CorrectPosition(vector2f offset)
{
    if (offset.length() > size_) return;
    position_ += offset;
}

float Blobs::Blob::Size() const
{
    return size_;
}

Blobs::Movable_Blob::Movable_Blob(point2f position, float size) : Blob(position, size)
{
}

vector2f &Blobs::Movable_Blob::Direction()
{
    return direction_;
}

void Blobs::Movable_Blob::Step()
{
    position_ += direction_*Configs::Float("speed_factor")*(1.0 - size_/Configs::Float("players_max_size"));
}

Blobs::Meat::Meat(point2f position) : Blob(position, Configs::Float("meats_size"))
{
}

Blobs::Player::Player(point2f position, const std::string &name)
: Movable_Blob(position, Configs::Float("players_min_size")), name_(name)
{
    born_time_ = time(nullptr);
}

const std::string &Blobs::Player::Name() const
{
    return name_;
}

const time_t &Blobs::Player::BornTime() const
{
    return born_time_;
}

void Blobs::Player::Heal(float eat_size)
{
    size_ = static_cast<float>(sqrt(max(1.0, pow(size_, 2) - pow(eat_size, 2))));
}

void Blobs::Player::Eat(float eat_size)
{
    size_ = static_cast<float>(sqrt(pow(size_, 2) + pow(eat_size, 2)));
}

Blobs::Poison::Poison(point2f position, float size) : Movable_Blob(position, size)
{
}

string &Blobs::Poison::Target()
{
    return target_;
}
