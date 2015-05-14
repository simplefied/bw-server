#ifndef WORLD_H
#define WORLD_H

#include <list>
#include <cstdlib>
#include <cmath>
#include "configs.hpp"
#include "vectors.hpp"
#include "blobs.hpp"

class Collider;

class World
{
public:
    World();
    void Birth(std::string name);
    Blobs::Player &GetBlob(std::string name);
    const std::list<Blobs::Player> &GetPlayers() const;
    const std::list<Blobs::Poison> &GetPoisons() const;
    const std::list<Blobs::Meat> &GetMeats() const;
    void Heal();
    void Step();
private:
    friend class Collider;
    void AddMeat(point2f position);
    void RoutePoisons();
    std::string CalcTarget();
    point2f GetSpawnPoint(point2f position, float radius);
    std::list<Blobs::Player> players;
    std::list<Blobs::Poison> poisons;
    std::list<Blobs::Meat> meats;
};

#endif // WORLD_H
