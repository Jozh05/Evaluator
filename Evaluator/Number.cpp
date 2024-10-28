#include "Number.h"

Number::Number() : Lexeme("0") { }
Number::Number(std::string token) : Lexeme(token) { }


std::string Number::TypeName()
{
	return "Number";
}

