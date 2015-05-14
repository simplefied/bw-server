#include "socket.hpp"

using namespace std;
using namespace boost::asio;

Socket::Socket(uint16_t port) : ios(), socket(ios, endpoint(ip::udp::v4(), port))
{
    socket.non_blocking(true);
}

string Socket::Read(endpoint &remote_ep, bool &cache_is_empty)
{
    uint8_t data[READ_BUFF_SIZE];
    size_t size;
    try {
        size = socket.receive_from(boost::asio::buffer(&data, sizeof(data)), remote_ep);
    }
    catch (boost::system::system_error &err) {
        if (err.code() == boost::asio::error::would_block) cache_is_empty = true;
        else Logger::Error(err.what());
        return string();
    }
    string msg;
    msg.reserve(size);
    for (unsigned int i = 0; i < size; ++i) msg.push_back((char)data[i]);
    return msg;
}

void Socket::Write(const endpoint &remote_ep, const string &msg)
{
    size_t size;
    try {
        size = socket.send_to(boost::asio::buffer(msg.c_str(), msg.size()), remote_ep);
    }
    catch (boost::system::system_error &err) {
        Logger::Error(err.what());
    }
    if (size != msg.size()) Logger::Notice("Warning: partial write.");
}

bool Socket::Available()
{
    return socket.available() > 0;
}
