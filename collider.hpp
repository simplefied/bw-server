#ifndef COLLIDER_H
#define COLLIDER_H

#include <list>
#include <utility>
#include "configs.hpp"
#include "world.hpp"

class Collider
{
public:
    Collider(World &world);
    void Collide();
private:
    void CollidePvM();
    void CollidePvP();
    void CollideWithWorld();
    void CollideWithPoison();
    World &world_;
};

#endif // COLLIDER_H
