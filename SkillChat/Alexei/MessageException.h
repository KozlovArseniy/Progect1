#pragma once
#include<exception>
#include<string>

class MessageException : public std::exception
{
public:
	explicit MessageException(const std::string& error);

	virtual const char* what() const noexcept override;

private:
	std::string _error;
};