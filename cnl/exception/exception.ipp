namespace connected
{
namespace network
{
namespace exception
{
socket_creation_exception::socket_creation_exception(const error& err)
{
    what_ = "Cannot create the socket. Error: ";
    what_ += err.get_message();
}

const char * socket_creation_exception::what() const throw ()
{
    return what_.c_str();
}

socket_closing_exception::socket_closing_exception(const error& err)
{
    what_ = "Cannot close the socket. Error: ";
    what_ += err.get_message();
}

const char * socket_closing_exception::what() const throw ()
{
    return what_.c_str();
}

socket_binding_exception::socket_binding_exception(const error& err)
{
    what_ = "Cannot bind the socket. Error: ";
    what_ += err.get_message();
}

const char * socket_binding_exception::what() const throw ()
{
    return what_.c_str();
}

socket_listening_exception::socket_listening_exception(const error& err)
{
    what_ = "The socket cannot listen. Error: ";
    what_ += err.get_message();
}

const char * socket_listening_exception::what() const throw ()
{
    return what_.c_str();
}

socket_connecting_exception::socket_connecting_exception(const error& err)
{
    what_ = "The socket cannot connect to host. Error: ";
    what_ += err.get_message();
}

const char * socket_connecting_exception::what() const throw ()
{
    return what_.c_str();
}

not_implemented::not_implemented(const std::string& error)
{
    what_ = "Not implemented: ";
    what_ += error;
}

const char * not_implemented::what() const throw ()
{
    return what_.c_str();
}

winsock_init_exception::winsock_init_exception(const error& err)
{
    what_ = "Cannot initialize Windows Socket. Error: ";
    what_ += err.get_message();
}

const char * winsock_init_exception::what() const throw ()
{
    return what_.c_str();
}
} //namespace exception

} // namespace network

} // namespace connected