#include "Comma.h"

Comma::Comma() : Lexeme(",") { }
Comma::Comma(std::string token) : Comma() { }


std::string Comma::TypeName()
{
	return "Comma";
}

