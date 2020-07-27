#pragma once
#include <socket/socket_stream.hpp>
#include <socket/acceptor_base.hpp>
#include <protocol/internet_protocol.hpp>
#include <endpoint/resolver_base.hpp>
#include <endpoint/endpoint_base.hpp>
#include <error/error.hpp>

namespace connected
{
namespace network
{
struct tcp_base
{
static int type()
{
    return CNL_SOCK_STREAM;
}
};

namespace ipv4
{
/**
 * Contains the flags used for TCP protocol.
 */
struct tcp : public tcp_base
{
    using socket   = socket_stream<ip4>;
    using acceptor = acceptor_base<ip4>;
    using resolver = resolver_base<ip4, tcp>;
    using endpoint = endpoint_base<ip4>;
};   
} // namespace ipv4

namespace ipv6
{
/**
 * Contains the flags used for TCP protocol.
 */
struct tcp : public tcp_base
{
    using socket   = socket_stream<ip6>;
    using acceptor = acceptor_base<ip6>;
    using resolver = resolver_base<ip6, tcp>;
    using endpoint = endpoint_base<ip6>;
};    
} // namespace ipv6

} // namespace network
    
} // namespace connected
