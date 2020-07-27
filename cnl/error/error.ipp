namespace connected
{
namespace network
{

error::error(error_type code) :
    error_code_(code)
{    
    message_ = strerror(error_code_);
}

error::error(const std::string& message_) :
    error_code_(CNL_ERROR), message_(message_)
{
}

void error::set_code(error_type code)
{
    error_code_ = code;
    message_    = strerror(error_code_);
}

std::string error::get_message() const
{
    return message_;
}

error::error_type error::get_code() const
{
    return error_code_;
}

} // namespace network

} // namespace connected
