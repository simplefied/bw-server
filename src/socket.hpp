#ifndef SOCKET_H
#define SOCKET_H

#include <boost/asio/io_service.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/udp.hpp>
#include <cstdint>
#include "logger.hpp"

#define READ_BUFF_SIZE 65535

class Socket
{
public:
    typedef boost::asio::ip::udp::endpoint endpoint;
    Socket(std::uint16_t port);
    Socket(Socket&) = delete;
    Socket(Socket&&) = delete;
    Socket& operator=(const Socket&) = delete;
    Socket& operator=(Socket&&) = delete;
    std::string Read(endpoint &remote_ep, bool &cache_is_empty);
    void Write(const endpoint &remote_ep, const std::string &msg);
private:
    boost::asio::io_service ios;
    boost::asio::ip::udp::socket socket;
};

#endif // SOCKET_H
