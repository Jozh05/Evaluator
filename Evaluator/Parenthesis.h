#pragma once
#ifndef __PARENTHESIS_H
#define __PARENTHESIS_H

#include "Lexeme.h"
#include <string>

class Parenthesis : public Lexeme
{
public:
	Parenthesis();
	Parenthesis(std::string token);
	std::string TypeName() override;
};

#endif
