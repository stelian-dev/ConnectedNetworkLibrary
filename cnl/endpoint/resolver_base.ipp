namespace connected
{
namespace network
{
template<typename InternetProtocol, typename TransportProtocol>
resolver_base<InternetProtocol, TransportProtocol>::
    resolver_base()
{
    set_data();
}

template<typename InternetProtocol, typename TransportProtocol>
resolver_base<InternetProtocol, TransportProtocol>::
    resolver_base(const std::string& address, const std::string& service)
{
    set_data(address, service);
}

template<typename InternetProtocol, typename TransportProtocol>
void resolver_base<InternetProtocol, TransportProtocol>::
    set_data()
{
#if defined(WINDOWS)
    set_data_windows();
#elif defined(LINUX)
    set_data_linux();
#endif
}

template<typename InternetProtocol, typename TransportProtocol>
void resolver_base<InternetProtocol, TransportProtocol>::
    set_data(const std::string& address, const std::string& service)
{
    cnl_addrinfo* data;
    cnl_addrinfo hints{};
    hints.ai_family    = ip_type::family();
    hints.ai_socktype  = tp_type::type();
    hints.ai_flags     = AI_PASSIVE;
    hints.ai_protocol  = CNL_ANYPROTO;
    hints.ai_canonname = nullptr;
    hints.ai_addr      = nullptr;
    hints.ai_next      = nullptr;

    int error = getaddrinfo(address.c_str(), 
                    service.c_str(),
                    &hints, &data);
    if(CNL_NO_ERROR == error)
    {
        for(auto it = data; it != nullptr; it = it->ai_next)
        {
            if(it && it->ai_addr)
            {
                data_.push_back(endpoint_type(it->ai_addr));
            }

        }
        freeaddrinfo(data);
    }
}

#if defined(WINDOWS)
template<typename InternetProtocol, typename TransportProtocol>
void resolver_base<InternetProtocol, TransportProtocol>::
    set_data_windows()
{
    cnl_dword error, size;
    cnl_pip_adapter_addresses adapter_addresses;

    error = GetAdaptersAddresses(ip_type::family(),
                                    CNL_GAA_FLAG_INCLUDE_PREFIX,
                                    nullptr,
                                    nullptr,
                                    &size);

    if (CNL_ERROR_BUFFER_OVERFLOW != error) 
    {
        return;
    }
    
    adapter_addresses = (cnl_pip_adapter_addresses)malloc(size);

    error = GetAdaptersAddresses(ip_type::family(), 
                                    CNL_GAA_FLAG_INCLUDE_PREFIX, 
                                    nullptr, 
                                    adapter_addresses, 
                                    &size);
    if (CNL_NO_ERROR != error) 
    {
        free(adapter_addresses);
    }

    for (auto it = adapter_addresses; it != NULL; it = it->Next) 
    {
        for (auto it2 = it->FirstUnicastAddress; it2 != NULL; it2 = it2->Next) 
        {
            data_.push_back(it2->Address.lpSockaddr);
        }
    }

    free(adapter_addresses);
}
#elif defined(LINUX)
template<typename InternetProtocol, typename TransportProtocol>
void resolver_base<InternetProtocol, TransportProtocol>::
    set_data_linux()
{
    cnl_ifaddrs* data;
    int error = getifaddrs(&data);
    if(CNL_NO_ERROR == error)
    {
        for(auto it = data; it != nullptr; it = it->ifa_next)
        {
            if(it && 
                it->ifa_addr != nullptr &&
                it->ifa_addr->sa_family == ip_type::family())
            {
                data_.push_back(endpoint_type(it->ifa_addr));
            }
        }  
        freeifaddrs(data);  
    }
}
#endif
} // namespace network

} // namespace connected