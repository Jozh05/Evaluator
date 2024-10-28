#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class InvalidOperation : public exception {

public:
	InvalidOperation(string token) : exception(token.c_str()) {};
};