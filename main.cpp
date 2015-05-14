#include <thread>
#include <chrono>
#include <ctime>
#include "configs.hpp"
#include "socket.hpp"
#include "clients.hpp"
#include "world.hpp"
#include "encdecman.hpp"
#include "collider.hpp"

using namespace std;

int main()
{
    Configs::Load("server.conf");
    Socket socket(Configs::GetInt("server_port"));
    Clients clients;
    World world;
    EncDecManager edman(world);
    Collider collider(world);

    long int frame_time = 1000/Configs::GetInt("server_fps");
    clock_t begin_frame;
    while (true) {
        begin_frame = clock();
        {
            collider.Collide();
            {
                string msg = edman.Encode();
                for (Socket::endpoint ep : clients.GetEPs()) {
                    socket.Write(ep, msg);
                }
            }
            bool cache_is_empty = false;
            while (!cache_is_empty) {
                Socket::endpoint remote_ep;
                string msg = socket.Read(remote_ep, cache_is_empty);
                if (msg.empty()) continue;
                if (msg == "connect") {
                    clients.Register(remote_ep);
                }
                else if (clients.Registered(remote_ep)) edman.Decode(msg);
            }
            if (rand()%Configs::GetInt("not_healing_chance") == 0) world.Heal();
            world.Step();
        }
        long int millis_est = lround(static_cast<float>(clock() - begin_frame)/CLOCKS_PER_SEC*1000);
        if (millis_est < frame_time) {
            this_thread::sleep_for(chrono::milliseconds(frame_time - millis_est));
        }
    }
    return 0;
}

