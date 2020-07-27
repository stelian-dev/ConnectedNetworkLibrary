#pragma once
#include <socket/socket_base.hpp>
#include <endpoint/endpoint_base.hpp>
#include <protocol/internet_protocol.hpp>
#include <error/error.hpp>
#include <array>

namespace connected
{
namespace network
{
/**
 * The implementation of a stream socket (TCP as a transport layer 
 * protocol). For binding, listening and acception connections use the 
 * acceptor class.
 * @tparam InternetProtocol Network layer protocol. Can be either ip4
 *      for Internet Protocol v4 or ip6 for Internet Protocol v6.
 */
template<typename InternetProtocol>
class socket_stream : protected socket_base
{
public:
    using ip_type       = InternetProtocol;
    using self_type     = socket_stream<ip_type>;
    using endpoint_type = endpoint_base<ip_type>;

    /**
     * Create a new stream socket.
     * @throws exception::socket_creation_exception if fails to create
     *      the socket.
     */
    socket_stream();

    /**
     * Read into a buffer. This function will block the caller until 
     * the operation is finished.
     * @tparam Size buffer size.
     * @param[out] buffer store the result of the read operation.
     * @param[out] bytes store the number of bytes read.
     * @returns error type object
     * @exceptsafe
     */
    template<std::size_t Size>
    error read(std::array<char, Size>& buffer, std::size_t& bytes) const;

    /**
     * Write from a buffer. This function will block the caller until 
     * the operation is finished.
     * @tparam Size buffer size.
     * @param[in] buffer store the bytes to be written.
     * @param[out] bytes store the number of bytes written
     * @returns error type object
     * @exceptsafe
     */
    template<std::size_t Size>
    error write(std::array<char, Size>& buffer, std::size_t& bytes) const;

    /**
     * Connect to the given endpoint.
     * @param[in] endpoint the machine that the socket will be 
     * connected to.
     * @throws exception::socket_creation_exception if the socket 
     * is unable to connect to the given endpoint.
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */   
    void connect(const endpoint_type& host);

    /** 
     * Close the socket.
     * @throws exception::socket_closing_exception if the socket 
     * is unable to close.
     */  
    void close();
    
protected:
    socket_stream(cnl_socket_type handle); 
    static self_type factory(cnl_socket_type handle);
};
} // namespace network

} // namespace connected

#include <socket/socket_stream.ipp>