namespace connected
{
namespace network
{
template<typename InternetProtocol>
socket_datagram<InternetProtocol>::socket_datagram() :
    socket_base(
        ip_type::family(),
        CNL_SOCK_DGRAM,
        CNL_IPPROTO_UDP)
{
}

template<typename InternetProtocol>
void socket_datagram<InternetProtocol>::bind(const endpoint_type& host)
{
    throw exception::not_implemented("bind");
}

template<>
void socket_datagram<ip4>::bind(const endpoint_type& host)
{
    auto data = host.get_data();
    cnl_socklen_t addr_len = sizeof(data.in_);
    socket_base::bind((cnl_sockaddr*)&data.in_, addr_len);
}

template<>
void socket_datagram<ip6>::bind(const endpoint_type& host)
{
    auto data = host.get_data();
    cnl_socklen_t addr_len = sizeof(data.in6_);
    socket_base::bind((cnl_sockaddr*)&data.in6_, addr_len);
}


template<typename InternetProtocol>
template<std::size_t Size>
error socket_datagram<InternetProtocol>::read(const endpoint_type& from,
    std::array<char, Size>& buffer, std::size_t& bytes) const
{
    throw exception::not_implemented("read");
}

template<>
template<std::size_t Size>
error socket_datagram<ip4>::read(const endpoint_type& from,
        std::array<char, Size>& buffer, std::size_t& bytes) const
{
    auto data = from.get_data();
    cnl_socklen_t addr_len = sizeof(data.in_);
    return socket_base::read((cnl_sockaddr*)&data.in_, addr_len, buffer, bytes);
}

template<>
template<std::size_t Size>
error socket_datagram<ip6>::read(const endpoint_type& from,
        std::array<char, Size>& buffer, std::size_t& bytes) const
{
    auto data = from.get_data();
    cnl_socklen_t addr_len = sizeof(data.in6_);
    return socket_base::read((cnl_sockaddr*)&data.in6_, addr_len, buffer, bytes);
}

template<typename InternetProtocol>
template<std::size_t Size>
error socket_datagram<InternetProtocol>::write(const endpoint_type& to,
    std::array<char, Size>& buffer, std::size_t& bytes) const
{
    throw exception::not_implemented("write");
}    

template<>
template<std::size_t Size>
error socket_datagram<ip4>::write(const endpoint_type& to,
    std::array<char, Size>& buffer, std::size_t& bytes) const
{
    auto data = to.get_data();
    cnl_socklen_t addr_len = sizeof(data.in_);
    return socket_base::write((cnl_sockaddr*)&data.in_, addr_len, buffer, bytes);
}

template<>
template<std::size_t Size>
error socket_datagram<ip6>::write(const endpoint_type& to,
    std::array<char, Size>& buffer, std::size_t& bytes) const
{
    auto data = to.get_data();
    cnl_socklen_t addr_len = sizeof(data.in6_);
    return socket_base::write((cnl_sockaddr*)&data.in6_, addr_len, buffer, bytes);
}     

template<typename InternetProtocol>
void socket_datagram<InternetProtocol>::close()
{
    socket_base::close();
}

} // namespace network

} // namespace connected