#pragma once
#include <cnl/misc/constants.hpp>

namespace connected
{
namespace network
{
/**
 * Contains the flags used for IP v4 protocol.
 */
struct ip4
{
static int family()
{
    return CNL_AF_INET;
}
};
/**
 * Contains the flags used for IP v6 protocol.
 */
struct ip6
{
static int family()
{
    return CNL_AF_INET6;
}
};
} // namespace network
    
} // namespace connected
