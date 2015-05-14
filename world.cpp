#include "world.hpp"
#include "logger.hpp"
using namespace std;

World::World()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    for(int i=0; i<Configs::GetInt("meats_count"); ++i) {
        AddMeat(GetSpawnPoint(point2f(0, 0), Configs::GetFloat("world_radius") - Configs::GetFloat("meats_size") - 1));
    }
}

void World::Birth(string name)
{   
    for (auto aiter = players.begin(); aiter != players.end(); ++aiter) {
        if (aiter->Name() == name) {
            players.erase(aiter);
            break;
        }
    }
    point2f spawn_point = GetSpawnPoint(point2f(0, 0), Configs::GetFloat("world_radius") - Configs::GetFloat("players_min_size") - 1);
    Blobs::Player blob(spawn_point, name);
    players.push_back(blob);
}

Blobs::Player &World::GetBlob(string name)
{
    for (auto iter = players.begin(); iter != players.end(); ++iter) {
        if (iter->Name() == name) return *iter;
    }
    throw string("unknown user");
}

const list<Blobs::Player> &World::GetPlayers() const
{
    return players;
}

const std::list<Blobs::Poison> &World::GetPoisons() const
{
    return poisons;
}

const list<Blobs::Meat> &World::GetMeats() const
{
    return meats;
}

void World::Heal()
{
    if (!players.size()) return;
    if (poisons.size()) return;

    // Compute all poisons mass
    long mass = 0;
    for (auto player : players) {
        mass += lround(pow(player.Size(), 2));
    }
    if (mass / players.size() <= lround(pow(Configs::GetFloat("players_min_size"), 2))) return;
    mass >>= 1;

    long min_mass = Configs::GetInt("poisons_min_mass");
    long max_mass = Configs::GetInt("poisons_max_mass");
    for (int i = 0; i < Configs::GetInt("max_poisons_count"); ++i) {
        if (mass < min_mass) break;
        long pmass = rand()%(max_mass - min_mass + 1) + min_mass;
        mass -= pmass;
        float radius = Configs::GetFloat("world_radius") - static_cast<float>(sqrt(Configs::GetInt("poisons_max_mass"))) - 1;
        Blobs::Poison poison(GetSpawnPoint(point2f(0, 0), radius), static_cast<float>(sqrt(pmass)));
        poison.Target() = CalcTarget();
        poisons.push_back(poison);
    }
}

void World::Step()
{
    for (auto piter = players.begin(); piter != players.end(); ++piter) {
        if (piter->Size() > Configs::GetFloat("players_max_size")) {
            for (int i = 0; i < Configs::GetInt("meats_count")*2; ++i){
                AddMeat(GetSpawnPoint(piter->Position(), piter->Size() - Configs::GetFloat("meats_size") - 1));
            }
            players.erase(piter);
            break;
        }
    }
    for (auto &player : players) {
        player.Step();
    }
    RoutePoisons();
    for (auto &poison : poisons) {
        poison.Step();
    }
}

point2f World::GetSpawnPoint(point2f position, float radius)
{
    float linear = static_cast<float>(rand()%lround(radius));
    float angle = static_cast<float>(rand()%360);
    angle = angle/180*M_PI;
    return point2f(position + vector2f(linear*cos(angle), linear*sin(angle)));
}

void World::AddMeat(point2f position)
{
    Blobs::Meat blob(position);
    meats.push_back(blob);
}

void World::RoutePoisons()
{
    if (!players.size()) poisons.clear();
    for (auto &poison : poisons) {
        try {
            GetBlob(poison.Target());
        }
        catch (...) {
            poison.Target() = CalcTarget();
        }
        Blobs::Player target = GetBlob(poison.Target());
        vector2f dir = target.Position() - poison.Position();
        poison.Direction() = dir.normalize();
    }
}

string World::CalcTarget()
{
    long mass = 0;
    for (auto player : players) {
        mass += lround(player.Size());
    }
    long sel = rand()%mass;
    long iter = 0;
    for (auto player : players) {
        iter += lround(player.Size());
        if (iter > sel) return player.Name();
    }
    throw new string("Unable calc target.");
}
