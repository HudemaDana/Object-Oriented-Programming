#pragma once
#include <exception>
#include <string>

class MyException :public std::exception
{
private:
	std::string message;

public:
	MyException(const std::string& s):message{s}{}

	const char* what() const throw() override 
	{
		return this->message.c_str();
	}
};

class ValidatorException :public std::exception
{
private:
	std::string message;
public:
	ValidatorException(const std::string& s): message{s}{}

	const char* what() const throw() override
	{
		return this->message.c_str();
	}
};
