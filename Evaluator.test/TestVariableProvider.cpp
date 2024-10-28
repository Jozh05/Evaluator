#include "pch.h"
#include "TestVariableProvider.h"
#include "..\Evaluator\Number.h"
#include "..\Evaluator\Boolean.h"
#include "..\Evaluator\NotImplementedException.h"

Lexeme* TestVariableProvider::ExtractValue(string token) {
	if (token.compare("A") == 0)
		return new Number("10");
	if (token.compare("true") == 0)
		return new Boolean("true");
	if (token.compare("B") == 0)
		return new Number("20");
	if (token.compare("a") == 0)
		return new Number("30");
	throw new NotImplementedException(token);
}