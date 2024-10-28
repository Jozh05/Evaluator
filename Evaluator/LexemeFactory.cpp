#include "LexemeFactory.h"
#include "Boolean.h"
#include "Comma.h"
#include "Number.h"
#include "Operation.h"
#include "Parenthesis.h"
#include "TheEnd.h"
#include <utility>
#include <cstdio>
#include <algorithm>
#include "InvalidNumberException.h"
#include "InvalidOperation.h" 
#include <regex>
#include "Identificator.h"



Lexeme* LexemeFactory::Create(std::string token)
{
	if (!token.empty())
	{
		if (IsBoolean(token))
		{
			std::transform(token.begin(), token.end(), token.begin(), [](unsigned char c) { return std::tolower(c); });
			return new Boolean(token);
		}
		if (IsComma(token))
			return new Comma();

		if (IsNumber(token))
			return new Number(token);
		
		if (IsCondition(token))
			return new Operation(token);

		if (IsIdentificator(token))
			return new Identificator(token);

		if (IsOperation(token))
			return new Operation(token);
		
		if (IsParenthesis(token))
			return new Parenthesis(token);
	}
	return new TheEnd();
}





static bool icompare_pred(unsigned char a, unsigned char b)
{
	return std::tolower(a) == std::tolower(b);
}


static bool icompare(std::string const& a, std::string const& b)
{
	if (a.length() == b.length())
		return std::equal(b.begin(), b.end(), a.begin(), icompare_pred);
	return false;
}



bool LexemeFactory::IsBoolean(std::string token)
{
	const std::string  True = "true";
	const std::string  False = "false";
	return icompare(token, "true") || icompare(token, "false");
}


bool LexemeFactory::IsComma(std::string token)
{
	return token == ",";
}


bool LexemeFactory::IsCondition(std::string token)
{
	if (regex_match(token, (regex)"[!<>=]{1,2}")) {
		if (token.length() == 2 && (token[0] == '=' || token == "><" || token == "!!"))
			throw new InvalidOperation("Invalid operation");
		return true;
	}
	return regex_match(token, (regex)"and|or");
}


bool LexemeFactory::IsIdentificator(std::string token)
{
	return regex_match(token, (regex)"[a-zA-Z][a-zA-Z0-9_]*");
}



bool LexemeFactory::IsNumber(std::string token)
{
	try {
		stod(token);
		return true;
	}
	catch (invalid_argument) {
		return false;
	}
}



bool LexemeFactory::IsOperation(std::string token)
{
	if (regex_match(token, (regex)"[\\/]|[+]|[-]|[*]"))
		return true;
	return false;
}


bool LexemeFactory::IsParenthesis(std::string token)
{
	return token == "(" || token == ")";
}

