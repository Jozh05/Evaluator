#include "Boolean.h"

Boolean::Boolean() : Boolean("false") { }
Boolean::Boolean(std::string token) : Lexeme(token) { }


std::string Boolean::TypeName()
{
	return "Boolean";
}

