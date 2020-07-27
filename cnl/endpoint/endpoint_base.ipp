#if defined(WINDOWS)
    #include <Ws2tcpip.h>
#elif defined(LINUX)
    #include <arpa/inet.h>
#endif
#include <exception/exception.hpp>
namespace connected
{
namespace network
{
template<class InternetProtocol>
endpoint_base<InternetProtocol>::endpoint_base(unsigned port)
{
    set_data(port);
}

template<class InternetProtocol>
endpoint_base<InternetProtocol>::endpoint_base(const std::string& address, unsigned port)
{
    set_data(address, port);
}

template<class InternetProtocol>
endpoint_base<InternetProtocol>::endpoint_base(cnl_sockaddr* addr)
{
    throw exception::not_implemented("endpoint_base");
}

template<>
endpoint_base<ip4>::endpoint_base(cnl_sockaddr* addr)
{
    data_.in_ = *((cnl_sockaddr_in*)addr);
}

template<>
endpoint_base<ip6>::endpoint_base(cnl_sockaddr* addr)
{
    data_.in6_ = *((cnl_sockaddr_in6*)addr);
}

template<class InternetProtocol>
typename endpoint_base<InternetProtocol>::data_type 
    endpoint_base<InternetProtocol>::get_data() const
{
    return data_;
}

template<class InternetProtocol>
void endpoint_base<InternetProtocol>::set_data(const std::string& address, unsigned port)
{
    throw exception::not_implemented("set_data"); 
}

template<>
void endpoint_base<ip4>::set_data(const std::string& address, unsigned port)
{
    data_.in_.sin_family = ip_type::family();
    data_.in_.sin_port   = htons(port);
    inet_pton(ip_type::family(),
        address.c_str(),
        &(data_.in_.sin_addr.s_addr));
}

template<>
void endpoint_base<ip6>::set_data(const std::string& address, unsigned port)
{
    data_.in6_.sin6_family = ip_type::family();
    data_.in6_.sin6_port   = htons(port);
    inet_pton(ip_type::family(),
        address.c_str(),
        &(data_.in6_.sin6_addr));
}

template<class InternetProtocol>
void endpoint_base<InternetProtocol>::set_data(unsigned port)
{
    throw exception::not_implemented("set_data");
}

template<>
void endpoint_base<ip4>::set_data(unsigned port)
{
    data_.in_.sin_family      = ip_type::family();
    data_.in_.sin_port        = htons(port);
    data_.in_.sin_addr.s_addr = htonl(CNL_INADDR_ANY);
}

template<>
void endpoint_base<ip6>::set_data(unsigned port)
{
    throw exception::not_implemented("ipv6");
} 

template<class InternetProtocol>
std::string endpoint_base<InternetProtocol>::get_address() const
{
    throw exception::not_implemented("get_address");
}

template<>
std::string endpoint_base<ip4>::get_address() const
{
    char destination[CNL_INET_ADDRSTRLEN]{0};
    inet_ntop(ip4::family(), &(data_.in_.sin_addr), destination,
                sizeof(destination));
    return destination;
}

template<>
std::string endpoint_base<ip6>::get_address() const
{
    char destination[CNL_INET6_ADDRSTRLEN]{0};
    inet_ntop(ip6::family(), &(data_.in6_.sin6_addr), destination,
                sizeof(destination));
    return destination;
}

template<class InternetProtocol>
cnl_port_type endpoint_base<InternetProtocol>::get_port() const
{
    throw exception::not_implemented("get_port");
}

template<>
cnl_port_type endpoint_base<ip4>::get_port() const
{
    return ntohs(data_.in_.sin_port);
}  

template<>
cnl_port_type endpoint_base<ip6>::get_port() const
{
    return ntohs(data_.in6_.sin6_port);
}  
} // namespace network

} // namespace connected