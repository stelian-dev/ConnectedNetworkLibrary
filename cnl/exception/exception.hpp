#pragma once
#include <cnl/error/error.hpp>
#include <exception>
#include <string>

namespace connected
{
namespace network
{
namespace exception
{
class socket_creation_exception : public std::exception
{
public:
    socket_creation_exception(const error& err);
    const char * what () const throw ();
private:
    std::string what_;
};

class socket_closing_exception : public std::exception
{
public:
    socket_closing_exception(const error& err);
    const char * what () const throw ();
private:
    std::string what_;
};

class socket_binding_exception : public std::exception
{
public:
    socket_binding_exception(const error& err);
    const char * what () const throw ();
private:
    std::string what_;
}; 

class socket_listening_exception : public std::exception
{
public:
    socket_listening_exception(const error& err);
    const char * what () const throw ();
private:
    std::string what_;
}; 

class socket_connecting_exception : public std::exception
{
public:
    socket_connecting_exception(const error& err);
    const char * what () const throw ();
private:
    std::string what_;
}; 

class not_implemented : public std::exception
{
public:
    not_implemented(const std::string& error);
    const char * what () const throw ();
private:
    std::string what_;
}; 

class winsock_init_exception : public std::exception
{
public:
    winsock_init_exception(const error& err);
    const char * what () const throw ();
private:
    std::string what_;
}; 
} //namespace exception

} // namespace network

} // namespace connected

#include <cnl/exception/exception.ipp>