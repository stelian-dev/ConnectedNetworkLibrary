#pragma once
#include <socket/socket_stream.hpp>
#include <functional>

namespace connected
{
namespace network
{
/**
 * This class is used for specific stream socket operations like 
 * binding, listening and accepting new connections.
 * @tparam InternetProtocol Network layer protocol. Can be either ip4
 *      for Internet Protocol v4 or ip6 for Internet Protocol v6.
 */
template<typename InternetProtocol>
class acceptor_base : private socket_stream<InternetProtocol>
{
public:
    using ip_type       = InternetProtocol;
    using endpoint_type = endpoint_base<ip_type>;
    using socket_type   = socket_stream<ip_type>;

    /**
     * Create a new acceptor.
     * @throws exception::socket_creation_exception if fails to create 
     * the socket.
     */
    acceptor_base(unsigned max_pending_connections);
    
    /**
     * Bind to the given endpoint.
     * @param[in] endpoint the machine that the socket will be 
     * bound to.
     * @throws exception::socket_binding_exception if the socket 
     * is unable to bind to the given endpoint.
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */      
    void bind(const endpoint_type& host);

    /**
     * Mark the socket as passive. The bind method should be called 
     * before the listen method.
     * @throws exception::socket_listening_exception if the acceptor 
     * is unable to listen for incoming connections.
     */      
    void listen();

    /** Accept new incoming connections. This method will block the 
     * caller until a connection is present.
     * @param[in] handler callback handler.
     * @throws exception::not_implemented if ip4 or ip6 are not used 
     * as template arguments.
     */     
    void accept(const std::function<void(socket_type&, error)>& handler);

    /** 
     * Close the acceptor.
     * @throws exception::socket_closing_exception if the acceptor 
     * is unable to close.
     */      
    void close();
    
private:
    void accept_base(cnl_socket_type handle, error& err,
        const std::function<void(socket_type&, error)>& handler);

private:
    unsigned max_pending_connections_;
};
} // namespace network
    
} // namespace connected

#include <socket/acceptor_base.ipp>