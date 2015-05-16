#ifndef CLIENTS_H
#define CLIENTS_H

#include <set>
#include "socket.hpp"

class Clients
{
public:
    Clients();
    Clients(Clients&) = delete;
    Clients(Clients&&) = delete;
    Clients& operator=(const Clients&) = delete;
    Clients& operator=(Clients&&) = delete;
    typedef std::set<Socket::endpoint> collection;
    bool Registered(const Socket::endpoint &ep) const;
    void Register(const Socket::endpoint &ep);
    const collection &GetEPs() const;
private:
    collection eps;
};

#endif // CLIENTS_H
