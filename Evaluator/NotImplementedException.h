#pragma once
#include <stdexcept>
#include <string>

class NotImplementedException : public std::exception {
public:
	NotImplementedException(std::string identificator) : std::exception(identificator.c_str()) {};
};