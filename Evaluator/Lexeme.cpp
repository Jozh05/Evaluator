#include "Lexeme.h"
#include "NotImplementedException.h"

Lexeme::Lexeme() : Lexeme(std::string()) { }

Lexeme::Lexeme(std::string token)
{
	this->token = token;
}


std::string Lexeme::GetToken()
{
	return this->token;
}


int Lexeme::OperationPriority() {
	throw new NotImplementedException(token);
}

