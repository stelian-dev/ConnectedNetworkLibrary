#pragma once
#if defined(WINDOWS)
    #include <Ws2tcpip.h>
#elif defined(LINUX)
    #include <arpa/inet.h>
#endif
#include <protocol/internet_protocol.hpp>
#include <endpoint/endpoint_base.hpp>
#include <string>
#include <list>


namespace connected
{
namespace network
{
/**
 * This class is used to generated the endpoints associated with a 
 * given machine.
 * @tparam InternetProtocol Network layer protocol. Can be either ip4
 * for Internet Protocol v4 or ip6 for Internet Protocol v6.
 * @tparam TransportProtocol Transport layer protocol. Can be either 
 * tcp or udp.
 */
template<typename InternetProtocol, typename TransportProtocol>
class resolver_base
{
public:
    using ip_type        = InternetProtocol;
    using tp_type        = TransportProtocol;
    using endpoint_type  = endpoint_base<ip_type>;
    using endpoint_list  = std::list<endpoint_type>;
    using iterator       = typename endpoint_list::iterator;
    using const_iterator = typename endpoint_list::const_iterator;

    /**
     * Generate the endpoints associated with the current machine.
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */
    resolver_base();

    /**
     * Generate the endpoints associated with the given domain.
     * @param[in] address the hostname.
     * @param[in] service the port associated with the given address.
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */
    resolver_base(const std::string& address, const std::string& service);
    
    /**
     * @returns an iterator pointing to the first element in the 
     * sequence.
     * @exceptsafe
     */ 
    iterator begin() 
    { 
        return data_.begin();
    }

    /**
     * @returns an iterator pointing to the past-the-end element 
     * in the sequence.
     * sequence.
     * @exceptsafe
     */ 
    iterator end() 
    { 
        return data_.end();
    }

    /**
     * @returns an const_iterator pointing to the first element in 
     * the sequence.
     * @exceptsafe
     */ 
    const_iterator cbegin() const
    {
        return data_.cbegin();
    }

    /**
     * @returns an const_iterator pointing to the past-the-end 
     * element in the sequence.
     * @exceptsafe
     */ 
    const_iterator cend() const
    {
        return data_.cend();
    }

private:
    void set_data();
    void set_data(const std::string& address, const std::string& service);
    void set_data_linux();
    void set_data_windows();
    
private:
    endpoint_list data_;
}; 
} // namespace network

} // namespace connected

#include <endpoint/resolver_base.ipp>