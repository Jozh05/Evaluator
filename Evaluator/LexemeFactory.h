#pragma once
#ifndef __LEXEME_FACTORY_H
#define __LEXEME_FACTORY_H

#include "Lexeme.h"
#include <string>


class LexemeFactory
{
public:
	static Lexeme* Create(std::string token);
	static bool IsBoolean(std::string token);
	static bool IsCondition(std::string token);
	static bool IsComma(std::string token);
	static bool IsIdentificator(std::string token);
	static bool IsNumber(std::string token);
	static bool IsOperation(std::string token);
	static bool IsParenthesis(std::string token);
};

#endif