#if defined(WINDOWS)
    #include <winsock2.h>
    #include <misc/winsock_init.hpp>
#elif defined(LINUX)
    #include <sys/socket.h>
    #include <unistd.h>
#endif
#include <cnl/misc/constants.hpp>
#include <cnl/exception/exception.hpp>
#include <errno.h>

namespace connected
{
namespace network
{
socket_base::socket_base(int domain, int type, int protocol)
{
    handle_ = ::socket(domain, type, protocol);
    if(CNL_INVALID_SOCKET == handle_)
    {
        throw exception::socket_creation_exception(errno);
    }
}

socket_base::socket_base(cnl_socket_type handle) :
    handle_(handle)
{    
}

void socket_base::close()
{
    int error = 0;
#if defined(WINDOWS)
    error = ::closesocket(handle_);
#elif defined(LINUX)
    error = ::close(handle_);
#endif
    if(CNL_SOCKET_ERROR == error)
    {
        throw exception::socket_closing_exception(errno);
    }
}

void socket_base::bind(cnl_sockaddr* host, cnl_socklen_t& host_addr_size)
{
    int error = ::bind(handle_, host, host_addr_size);
    if(CNL_SOCKET_ERROR == error)
    {
        throw exception::socket_binding_exception(errno);
    }
}

void socket_base::connect(cnl_sockaddr* host, cnl_socklen_t& host_addr_size)
{
    int error = ::connect(handle_, host, host_addr_size);
    if(CNL_SOCKET_ERROR == error)
    {
        throw exception::socket_connecting_exception(errno);
    }        
}

void socket_base::listen(unsigned max_pending_connections)
{
    int error = ::listen(handle_, max_pending_connections);
    if(CNL_SOCKET_ERROR == error)
    {
        throw exception::socket_listening_exception(errno);
    }
}

cnl_socket_type socket_base::accept(error& err)
{
    cnl_socket_type remote_socket = ::accept(handle_,
                                            nullptr,
                                            nullptr);
    if(CNL_INVALID_SOCKET == remote_socket)
    {
        err.set_code(errno);
    }

    return remote_socket;
}

template<std::size_t Size>
error socket_base::read(std::array<char, Size>& arr, std::size_t& bytes, int flags) const
{
    char buf[Size];
    error err;
    int result = recv(handle_, buf, Size, flags);

    if(CNL_ERROR == result)
    {
        err.set_code(errno);
    }

    if(!err)
    {
        std::copy(std::begin(buf), std::end(buf), std::begin(arr));
        bytes = result;
    }
    else
    {
         bytes = 0;
    }

    return err;
}

template<std::size_t Size>
error socket_base::read(cnl_sockaddr* from, cnl_socklen_t& from_addr_size,
    std::array<char, Size>& arr, std::size_t& bytes, int flags) const
{
    char buf[Size];
    error err;
    int result = recvfrom(handle_, buf, Size, flags, from, &from_addr_size);

    if(CNL_ERROR == result)
    {
        err.set_code(errno);
    }

    if(!err)
    {
        std::copy(std::begin(buf), std::end(buf), std::begin(arr));
        bytes = result;
    }
    else
    {
         bytes = 0;
    }

    return err;
}

template<std::size_t Size>
error socket_base::write(std::array<char, Size>& arr, std::size_t& bytes, int flags) const
{
    char buf[Size];
    error err;
    std::copy(arr.begin(), arr.end(), std::begin(buf));
    int result = send(handle_, buf, Size, flags);
    
    if(CNL_ERROR == result)
    {
        err.set_code(errno);
    }

    if(!err)
    {
        bytes = result;
    }
    else
    {
        bytes = 0;     
    }
    
    return err;   
}

template<std::size_t Size>
error socket_base::write(cnl_sockaddr* to, cnl_socklen_t& to_addr_size,
    std::array<char, Size>& arr, std::size_t& bytes, int flags) const
{
    char buf[Size];
    error err;
    std::copy(arr.begin(), arr.end(), std::begin(buf));
    int result = sendto(handle_, buf, Size, flags, to, to_addr_size);

    if(CNL_ERROR == result)
    {
        err.set_code(errno);
    }

    if(!err)
    {
        bytes = result;
    }
    else
    {
        bytes = 0;     
    }
    
    return err; 
} 
}//namespace network

}//namespace network