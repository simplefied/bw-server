#ifndef SOCKET_H
#define SOCKET_H

#include <boost/asio.hpp>
#include <cstdint>
#include "logger.hpp"

#define READ_BUFF_SIZE 65535

class Socket
{
public:
    typedef boost::asio::ip::udp::endpoint endpoint;
    Socket(std::uint16_t port);
    std::string Read(endpoint &remote_ep, bool &cache_is_empty);
    void Write(const endpoint &remote_ep, const std::string &msg);
    bool Available();
private:
    boost::asio::io_service ios;
    boost::asio::ip::udp::socket socket;
};

#endif // SOCKET_H
