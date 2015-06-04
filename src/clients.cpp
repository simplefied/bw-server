#include "clients.hpp"

using namespace std;

bool Clients::Registered(const Socket::endpoint &ep) const
{
    return eps.count(ep);
}

void Clients::Register(const Socket::endpoint &ep)
{
    eps.insert(ep);
}

const Clients::collection &Clients::GetEPs() const
{
    return eps;
}


Clients::Clients()
{

}
