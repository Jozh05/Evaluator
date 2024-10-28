#include "Identificator.h"

Identificator::Identificator() : Lexeme() {};

Identificator::Identificator(std::string token) : Lexeme(token) {};

std::string Identificator::TypeName() {
	return "Identificator";
}