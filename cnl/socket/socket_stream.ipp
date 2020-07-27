namespace connected
{
namespace network
{
template<class InternetProtocol>
socket_stream<InternetProtocol>::socket_stream() :
    socket_base(
        ip_type::family(),
        CNL_SOCK_STREAM,
        CNL_IPPROTO_TCP)
{
}

template<class InternetProtocol>
socket_stream<InternetProtocol>::socket_stream(cnl_socket_type handle) :
    socket_base(handle)
{
}

template<typename InternetProtocol>
template<std::size_t Size>
error socket_stream<InternetProtocol>::
    read(std::array<char, Size>& buffer, std::size_t& bytes) const
{
    return socket_base::read(buffer, bytes);
}

template<typename InternetProtocol>
template<std::size_t Size>
error socket_stream<InternetProtocol>::
    write(std::array<char, Size>& buffer, std::size_t& bytes) const
{
    return socket_base::write(buffer, bytes);
}

template<class InternetProtocol>
void socket_stream<InternetProtocol>::
    connect(const endpoint_type& host)
{
    throw exception::not_implemented("connect");
}

template<>
void socket_stream<ip4>::connect(const endpoint_type& host)
{
    auto data = host.get_data();
    cnl_socklen_t addr_len = sizeof(data.in_);            
    socket_base::connect((cnl_sockaddr*)&data.in_, addr_len);
}

template<>
void socket_stream<ip6>::connect(const endpoint_type& host)
{
    auto data = host.get_data();
    cnl_socklen_t addr_len = sizeof(data.in6_);
    socket_base::connect((cnl_sockaddr*)&data.in6_, addr_len);
}

template<class InternetProtocol>
socket_stream<InternetProtocol> socket_stream<InternetProtocol>::
    factory(cnl_socket_type handle)
{
    return socket_stream<ip_type>(handle); 
}

template<class InternetProtocol>
void socket_stream<InternetProtocol>::close()
{
    socket_base::close();
}
} // namespace network

} // namespace connected