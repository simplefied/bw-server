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
    Collider(Collider&) = delete;
    Collider(Collider&&) = delete;
    Collider& operator=(const Collider&) = delete;
    Collider& operator=(Collider&&) = delete;
    void Collide();
private:
    void CollidePvM();
    void CollidePvP();
    void CollideWithWorld();
    void CollideWithPoison();
    World &world_;
};

#endif // COLLIDER_H
