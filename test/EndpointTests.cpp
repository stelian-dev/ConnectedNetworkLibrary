#include <gtest/gtest.h>
#include <cnl/protocol/tcp.hpp>
#include <cnl/misc/types.hpp>

using namespace connected::network;

const cnl_port_type port = 8080;
const std::string address_v4("255.255.255.255");
const std::string address_v6("ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff");

TEST(EndpointTests, TestInternetProtocol_v4)
{
    ipv4::tcp::endpoint endpoint(port);

    cnl_sockaddr_in data = endpoint.get_data().in_;
    EXPECT_EQ(CNL_AF_INET, data.sin_family);
}

TEST(EndpointTests, TestConstructorWithPort_v4)
{
    ipv4::tcp::endpoint endpoint(port);

    EXPECT_EQ(port, endpoint.get_port());
}

TEST(EndpointTests, TestConstructorWithPort_v6)
{
    ipv6::tcp::endpoint endpoint(port);

    EXPECT_EQ(port, endpoint.get_port());
}

TEST(EndpointTests, TestConstructorWithAddressAndPort_v4)
{
    ipv4::tcp::endpoint endpoint(address_v4, port);

    EXPECT_EQ(port, endpoint.get_port());
    EXPECT_EQ(address_v4, endpoint.get_address());
}

TEST(EndpointTests, TestConstructorWithAddressAndPort_v6)
{
    ipv6::tcp::endpoint endpoint(address_v6, port);

    EXPECT_EQ(port, endpoint.get_port());
    EXPECT_EQ(address_v6, endpoint.get_address());
}