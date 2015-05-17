#include "collider.hpp"

using namespace std;

Collider::Collider(World &world) : world_(world)
{

}

void Collider::Collide()
{
    CollideWithWorld();
    CollidePvM();
    CollidePvP();
    CollideWithPoison();
}

void Collider::CollidePvM()
{
    list<pair<bool, Blobs::Meat>> temp_meats;
    for (auto meat : world_.meats) {
        temp_meats.push_back(make_pair(false, meat));
    }

    for (auto piter = world_.players.begin(); piter != world_.players.end(); ++piter) {
        for (auto miter = temp_meats.begin(); miter != temp_meats.end(); ++miter) {
            if (miter->first) continue;
            if (length(piter->Position() - miter->second.Position()) < piter->Size() + miter->second.Size()) {
                piter->Eat(miter->second.Size());
                miter->first = true;
            }
        }
    }

    world_.meats.clear();
    for (auto pair : temp_meats) {
        if (!pair.first) world_.meats.push_back(pair.second);
    }

    while (world_.meats.size() < Configs::Int("meats_count")) {
        world_.AddMeat(world_.GetSpawnPoint(point2f(0, 0), Configs::Float("world_radius") - Configs::Float("meats_size") - 1));
    }
}

void Collider::CollidePvP()
{
    list<pair<bool, Blobs::Player>> temp_players;
    for (auto player : world_.players) {
        temp_players.push_back(make_pair(false, player));
    }

    for (auto big = temp_players.begin(); big != temp_players.end(); ++big) {
        for (auto small = temp_players.begin(); small != temp_players.end(); ++small) {
            if (small != big) {
                if (small->first) continue;
                if (length(big->second.Position() - small->second.Position()) < big->second.Size()) {
                    if (big->second.Size() > small->second.Size()) {
                        big->second.Eat(small->second.Size());
                        small->first = true;
                    }
                }
            }
        }
    }

    world_.players.clear();
    for (auto pair : temp_players) {
        if (!pair.first) world_.players.push_back(pair.second);
    }
}

void Collider::CollideWithWorld()
{
    for (auto &player : world_.players) {
        vector2f wv = point2f(0, 0) - player.Position();
        float radius = length(wv) + player.Size();
        if (radius <= Configs::Float("world_radius")) continue;
        player.CorrectPosition(normalize(wv)*(radius - Configs::Float("world_radius")));
    }
}

void Collider::CollideWithPoison()
{
    list<Blobs::Player> temp_players;
    for (auto player : world_.players) {
        temp_players.push_back(player);
    }
    list<pair<bool, Blobs::Poison>> temp_poisons;
    for (auto poison : world_.poisons) {
        temp_poisons.push_back(make_pair(false, poison));
    }

    for (auto big = temp_players.begin(); big != temp_players.end(); ++big) {
        for (auto small = temp_poisons.begin(); small != temp_poisons.end(); ++small) {
            if (small->first) continue;
            if (length(big->Position() - small->second.Position()) < big->Size()) {
                if (big->Size() >= Configs::Float("players_min_size")) {
                    big->Heal(small->second.Size());
                    small->first = true;
                }
            }
        }
    }

    world_.players.clear();
    for (auto player : temp_players) {
        if (player.Size() >= Configs::Float("players_min_size")) world_.players.push_back(player);
    }
    world_.poisons.clear();
    for (auto pair : temp_poisons) {
        if (!pair.first) world_.poisons.push_back(pair.second);
    }
}

