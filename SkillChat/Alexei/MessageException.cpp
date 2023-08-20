#include"MessageException.h"

MessageException::MessageException(const std::string& error) : _error(error) {}

const char* MessageException::what() const noexcept 
{
    return this->_error.c_str();
}