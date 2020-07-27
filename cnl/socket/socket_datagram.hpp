#pragma once
#include <socket/socket_base.hpp>
#include <endpoint/endpoint_base.hpp>
#include <array>

namespace connected
{
namespace network
{
/**
 * The implementation of a datagram socket (UDP as a transport layer 
 * protocol).
 * @tparam InternetProtocol Network layer protocol. Can be either ip4 
 * for Internet Protocol v4 or ip6 for Internet Protocol v6.
 */
template<typename InternetProtocol>
class socket_datagram : protected socket_base
{
public:
    using ip_type       = InternetProtocol;
    using endpoint_type = endpoint_base<ip_type>;

    /**
     * Create a new datagram socket.
     * @throws exception::socket_creation_exception if fails to create 
     * the socket.
     */    
    socket_datagram();

    /**
      * Bind the socket to the given local endpoint.
      * @param[in] endpoint The endpoint that the socket will be 
      * bound to.
      * @throws exception::socket_binding_exception if the socket 
      * is unable to bind to the endpoint.
      * @throws exception::not_implemented if ip4 or ip6 are not used 
      * as template arguments.
      */
    void bind(const endpoint_type& host);

    /**
     * Read into a buffer. This function will block the caller until 
     * the operation is finished.
     * @tparam Size buffer size.
     * @param[in] from the sender
     * @param[out] buffer store the result of the read operation.
     * @param[out] bytes store the number of bytes read.
     * @returns error type object
     * @exceptsafe
     */
    template<std::size_t Size>
    error read(const endpoint_type& from, std::array<char, Size>& buffer,
        std::size_t& bytes) const;
        
    /**
     * Write from a buffer. This function will block the caller until 
     * the operation is finished.
     * @tparam Size buffer size.
     * @param[in] to the receiver
     * @param[in] buffer store the bytes to be written.
     * @param[out] bytes store the number of bytes written
     * @returns error type object
     * @exceptsafe
     */
    template<std::size_t Size>
    error write(const endpoint_type& to, std::array<char, Size>& buffer,
        std::size_t& bytes) const;

    /** 
     * Close the socket.
     * @throws exception::socket_closing_exception if the socket 
     * is unable to close.
     */  
    void close();
};
} // namespace network

} // namespace connected

#include <socket/socket_datagram.ipp>