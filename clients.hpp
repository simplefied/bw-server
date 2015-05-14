#ifndef CLIENTS_H
#define CLIENTS_H

#include <set>
#include "socket.hpp"

class Clients
{
public:
    Clients();
    typedef std::set<Socket::endpoint> collection;
    bool Registered(const Socket::endpoint &ep) const;
    void Register(const Socket::endpoint &ep);
    const collection &GetEPs() const;
private:
    collection eps;
};

#endif // CLIENTS_H
