#pragma once
#include <cnl/socket/socket_datagram.hpp>
#include <cnl/protocol/internet_protocol.hpp>
#include <cnl/endpoint/resolver_base.hpp>
#include <cnl/endpoint/endpoint_base.hpp>
#include <cnl/error/error.hpp>

namespace connected
{
namespace network
{
struct udp_base
{
static int type()
{
    return CNL_SOCK_STREAM;
}
};

namespace ipv4
{
/**
 * Contains the flags used for UDP protocol.
 */
struct udp : public udp_base
{
    using socket   = socket_datagram<ip4>;
    using resolver = resolver_base<ip4, udp>;
    using endpoint = endpoint_base<ip4>;
};    
} // namespace ipv4

namespace ipv6
{
/**
 * Contains the flags used for UDP protocol.
 */
struct udp : public udp_base
{
    using socket   = socket_datagram<ip6>;
    using resolver = resolver_base<ip6, udp>;
    using endpoint = endpoint_base<ip6>;
};    
} // namespace ipv6

} // namespace network
    
} // namespace connected
