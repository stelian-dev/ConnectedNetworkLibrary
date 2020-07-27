namespace connected
{
namespace network
{
template<class InternetProtocol>
acceptor_base<InternetProtocol>::acceptor_base(unsigned max_pending_connections) :
    max_pending_connections_(max_pending_connections)
{
}

template<class InternetProtocol>
void acceptor_base<InternetProtocol>::bind(const endpoint_type& host)
{
    throw exception::not_implemented("bind");
}

template<>
void acceptor_base<ip4>::bind(const endpoint_type& host)
{
    auto data = host.get_data();
    cnl_socklen_t addr_len = sizeof(data.in_);
    socket_type::bind((cnl_sockaddr*)&data.in_, addr_len);
}

template<>
void acceptor_base<ip6>::bind(const endpoint_type& host)
{
    auto data = host.get_data();
    cnl_socklen_t addr_len = sizeof(data.in6_);
    socket_type::bind((cnl_sockaddr*)&data.in6_, addr_len);
}

template<class InternetProtocol>
void acceptor_base<InternetProtocol>::listen()
{
    socket_type::listen(max_pending_connections_);
}

template<class InternetProtocol>
void acceptor_base<InternetProtocol>::accept(
    const std::function<void(socket_type&, error)>& handler)
{
    error err;
    cnl_socket_type result_handle_ = socket_base::accept(err);
    accept_base(result_handle_, err, handler);
}

template<class InternetProtocol>
void acceptor_base<InternetProtocol>::accept_base(cnl_socket_type handle, 
    error& err, const std::function<void(socket_type&, error)>& handler)
{
    socket_type socket = socket_type::factory(handle);
    handler(socket, err);
}

template<class InternetProtocol>
void acceptor_base<InternetProtocol>::close()
{
    socket_type::close();
}
} // namespace network
    
} // namespace connected
