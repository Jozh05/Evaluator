#pragma once
#include "Lexeme.h"
#include <string>

class Identificator : public Lexeme{
public:
	Identificator();
	Identificator(std::string token);
	std::string TypeName() override;
};