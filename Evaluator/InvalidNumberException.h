#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class InvalidNumberException : public exception{
public:
	InvalidNumberException(string token) : exception(token.c_str()){};
};