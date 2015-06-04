#include "encdecman.hpp"

using namespace std;

EncDecManager::EncDecManager(World &world) : world_(world)
{
    Register(new Events::Birth(world));
    Register(new Events::Turn(world));
}

void EncDecManager::Decode(std::string &msg)
{
    Command cmd(msg);
    if (!cmd.Size()) return;
    if (events.count(cmd[0])) {
        events[cmd[0]]->Do(cmd.Params());
    }
}

string EncDecManager::Encode()
{
    char buf[1024];
    auto players = world_.GetPlayers();
    auto poisons = world_.GetPoisons();
    auto meats = world_.GetMeats();
    string ans;
    sprintf(buf, "%s\n", PROTOCOL_VERSION);
    ans += string(buf);
    sprintf(buf, "%.1f\n", Configs::Float("world_radius"));
    ans += string(buf);
    for (auto player : players) {
        point2f pos = player.Position();
        sprintf(buf, "%s %.1f %.1f %.1f\n", player.Name().c_str(), player.Size(), pos.x, pos.y);
        ans += string(buf);
    }
    for (auto poison : poisons) {
        point2f pos = poison.Position();
        sprintf(buf, "%s %.1f %.1f %.1f\n", "poison", poison.Size(), pos.x, pos.y);
        ans += string(buf);
    }
    for (auto meat : meats) {
        point2f pos = meat.Position();
        sprintf(buf, "%s %.1f %.1f %.1f\n", "meat", meat.Size(), pos.x, pos.y);
        ans += string(buf);
    }
    if (ans.size() > 8192) Logger::Notice("Warning: packet size is too big.");
    return ans;
}

void EncDecManager::Register(Events::IEvent *event)
{
    events.insert(make_pair(event->Who(), event));
}

