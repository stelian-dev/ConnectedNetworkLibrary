#pragma once
#include <misc/config.hpp>

#if defined(WINDOWS)
#include <Winsock2.h>
#include <exception/exception.hpp>

namespace connected
{
namespace network
{
struct winsock_init
{
winsock_init()
{
    WSADATA data = {0};
    int result = 0;
    result = WSAStartup(MAKEWORD(WIN_SOCK_VERSION_MAJOR,
                                WIN_SOCK_VERSION_MINOR), &data);
    if(CNL_NO_ERROR != result)
    {
        throw exception::winsock_init_exception(result);
    }
}
~winsock_init()
{
    WSACleanup();
}
};

//Initialize Windows sockets before main
static winsock_init init;

} //namespace network

} //namespace connected
#endif