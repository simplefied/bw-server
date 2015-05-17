#include "events.hpp"

using namespace std;

Events::Birth::Birth(World &world) : aworld(world)
{

}

std::string Events::Birth::Who()
{
    return "birth";
}

void Events::Birth::Do(Command cmd)
{
    if (cmd.Size() != 1) return;
    if (cmd[0].size() < 2 || cmd[0].size() > 16) return;
    try {
        Blobs::Player player = aworld.GetBlob(cmd[0]);
        if (difftime(time(nullptr), player.BornTime()) < 5) return;
    }
    catch (...) {

    }
    aworld.Birth(cmd[0]);
}

Events::Turn::Turn(World &world) : aworld(world)
{

}

std::string Events::Turn::Who()
{
    return "turn";
}

void Events::Turn::Do(Command cmd)
{
    if (cmd.Size() != 3) return;
    if (cmd[0].size() < 2 || cmd[0].size() > 16) return;
    vector2f ndir;
    try {
        ndir = vector2f(stof(cmd[1]), stof(cmd[2]));
    }
    catch (...) {
        return;
    }
    if (length(ndir) > 100) ndir = normalize(ndir);
    else if (length(ndir) < 10) ndir = vector2f(0, 0);
    else ndir = ndir/100;
    try {
        aworld.GetBlob(cmd[0]).Direction() = ndir;
    }
    catch (...) {

    }
}
