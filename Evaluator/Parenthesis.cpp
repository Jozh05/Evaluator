#include "Parenthesis.h"


Parenthesis::Parenthesis() : Lexeme("(") { }
Parenthesis::Parenthesis(std::string token) : Lexeme(token) { }

std::string Parenthesis::TypeName()
{
	return "Parenthesis";
}

