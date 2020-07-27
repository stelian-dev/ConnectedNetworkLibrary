#pragma once
#include <cnl/misc/config.hpp>
#if defined(WINDOWS)
    #include <winsock2.h>
    #include <winsock.h>
    #include <ws2tcpip.h>
    #include <iphlpapi.h>
#elif defined(LINUX)
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netdb.h>
    #include <ifaddrs.h>
#endif

namespace connected
{
namespace network
{
using cnl_sockaddr_in                 = sockaddr_in;
using cnl_sockaddr_in6                = sockaddr_in6;
using cnl_sockaddr                    = sockaddr;
using cnl_addrinfo                    = addrinfo;
using cnl_port_type                   = int;
using cnl_socklen_t                   = socklen_t;
#if defined(WINDOWS)
using cnl_socket_type                 = SOCKET;        
using cnl_pip_adapter_addresses       = PIP_ADAPTER_ADDRESSES;
using cnl_pip_adapter_unicast_address = PIP_ADAPTER_UNICAST_ADDRESS;
using cnl_dword                       = DWORD;
#elif defined(LINUX)
using cnl_socket_type = int; 
using cnl_ifaddrs      = ifaddrs;
#endif

} // namespace network   

} // namespace connected
