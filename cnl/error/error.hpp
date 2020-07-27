#pragma once
#include <string>
#include <string.h>
#include <misc/constants.hpp>

namespace connected
{
namespace network
{
/**
 * The class is used for error representation.
*/
class error
{
public:
    using error_type = int;

    /**
     * Create a new error using the operating system error codes.
     * @throws exception::socket_creation_exception if fails to create 
     * the socket.
    */
    error(error_type code = CNL_NO_ERROR);

    /**
     * Create a new error using a custom message.
     * @throws exception::socket_creation_exception if fails to create 
     * the socket.
    */   
    error(const std::string& message_);

    /**
     * Change the error code.
     * @param[in] code operating system error code to be set
     * @exceptsafe
     */  
    void set_code(error_type code);

     /**
     * Get the error message in human readable format.
     * @exceptsafe
     */  
    std::string get_message() const;

     /**
     * Get the error code.
     * @exceptsafe
     */  
    error_type get_code() const;


    operator bool() const
    {
        return error_code_ != CNL_NO_ERROR;
    }

private:
    int error_code_;
    std::string message_;
};
} // namespace network

} // namespace connected

#include <error/error.ipp>