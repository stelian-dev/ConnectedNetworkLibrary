#pragma once
#include <misc/config.hpp>
#include <misc/types.hpp>
#include <endpoint/endpoint_base.hpp>
#include <array>

namespace connected
{
namespace network
{
/**
 * Base class for socket types. This should not be directly used, 
 * use socket_stream/acceptor_stream or socket_datagram classes.
 */
class socket_base
{
protected:
    socket_base(int domain, int type, int protocol);
    
    socket_base(const socket_base& other)            = delete;

    socket_base& operator=(const socket_base& other) = delete;

    void close();

    socket_base(cnl_socket_type handle);

    void bind(cnl_sockaddr* host, cnl_socklen_t& host_addr_size);

    void connect(cnl_sockaddr* host, cnl_socklen_t& host_addr_size);

    void listen(unsigned max_pending_connections);

    cnl_socket_type accept(error& err);

    template<std::size_t Size>
    error read(std::array<char, Size>& arr, std::size_t& bytes,
        int flags = 0/*no flags*/) const;

    template<std::size_t Size>
    error read(cnl_sockaddr* from, cnl_socklen_t& from_addr_size,
        std::array<char, Size>& arr, std::size_t& bytes, int flags = 0/*no flags*/) const;  

    template<std::size_t Size>
    error write(std::array<char, Size>& arr, std::size_t& bytes,
        int flags = 0/*no flags*/) const;

    template<std::size_t Size>
    error write(cnl_sockaddr* to, cnl_socklen_t& to_addr_size,
        std::array<char, Size>& arr, std::size_t& bytes, int flags = 0/*no flags*/) const;
               
protected:
    cnl_socket_type handle_;
};
}//namespace network

}//namespace network

#include <socket/socket_base.ipp>