#pragma once
#if defined(WINDOWS)
    #include <winsock2.h>
#elif defined(LINUX)
    #include <sys/socket.h>
#endif
#include <misc/config.hpp>

namespace connected
{
namespace network
{
//Errors
#define CNL_ERROR                   -1
#define CNL_NO_ERROR                0

//Sizes
#define CNL_INET6_ADDRSTRLEN        INET6_ADDRSTRLEN
#define CNL_INET_ADDRSTRLEN         INET_ADDRSTRLEN

//Address family
#define CNL_AF_INET                 AF_INET
#define CNL_AF_INET6                AF_INET6
#define CNL_AF_UNSPEC               AF_UNSPEC

//Socket type
#define CNL_SOCK_STREAM             SOCK_STREAM
#define CNL_SOCK_DGRAM              SOCK_DGRAM
#define CNL_SOCK_ANY                0

//Protocol type
#define CNL_IPPROTO_TCP             IPPROTO_TCP
#define CNL_IPPROTO_UDP             IPPROTO_UDP
#define CNL_ANYPROTO                0

//Options
#define CNL_INADDR_ANY              INADDR_ANY
#define CNL_INADDR6_ANY             in6addr_any                  
#define CNL_INPORT_ANY              0

//Errors
#define CNL_EAGAIN                  EAGAIN
#define CNL_EWOULDBLOCK             EWOULDBLOCK

//Other
#if defined(WINDOWS)  
#define CNL_INVALID_SOCKET          INVALID_SOCKET
#define CNL_SOCKET_ERROR            SOCKET_ERROR
#define WIN_SOCK_VERSION_MAJOR      2
#define WIN_SOCK_VERSION_MINOR      2
#define CNL_ERROR_BUFFER_OVERFLOW   ERROR_BUFFER_OVERFLOW
#define CNL_GAA_FLAG_INCLUDE_PREFIX GAA_FLAG_INCLUDE_PREFIX
#elif defined(LINUX)
#define CNL_INVALID_SOCKET          -1
#define CNL_SOCKET_ERROR            -1
#endif
    
} //namespace network

} //namespace connected