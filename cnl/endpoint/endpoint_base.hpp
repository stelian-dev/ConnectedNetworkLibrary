#pragma once
#include <cnl/protocol/internet_protocol.hpp>
#include <string>

namespace connected
{
namespace network
{
/**
 * The implementation of an endpoint. An endpoint is described by its 
 * address and its port.
 * @tparam InternetProtocol Network layer protocol. Can be either ip4
 *      for Internet Protocol v4 or ip6 for Internet Protocol v6.
 */
template<typename InternetProtocol>
class endpoint_base
{
public:
    using ip_type = InternetProtocol;

    struct data_type
    {
        cnl_sockaddr_in  in_;
        cnl_sockaddr_in6 in6_;
    };

     /**
     * Create a new endpoint using all interfaces and the given port.
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */
    endpoint_base(unsigned port);

     /**
     * Create a new endpoint using the given address and port.
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */    
    endpoint_base(const std::string& address, unsigned port);

    /**
     * Create a new endpoint using cnl_sockaddr structure.
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */       
    endpoint_base(cnl_sockaddr* addr);

     /**
     * Get the data structure that describes the endpoint.
     * @returns data_type object 
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */      
    data_type get_data() const;

     /**
     * Get the address associated with the endpoint in human readable 
     * format.
     * @returns a std::string representing the ip address.
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */        
    std::string get_address() const;

     /**
     * Get the port associated with the endpoint in human readable 
     * format.
     * @returns a cnl_port_type(aka int) representing the port.
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */        
    cnl_port_type get_port() const;

private:
    void set_data(const std::string& address, unsigned port);
    void set_data(unsigned port);

private:
    data_type data_;
};
} //namespace network

} //namespace network

#include <cnl/endpoint/endpoint_base.ipp>