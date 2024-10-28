#pragma once
#include "Lexeme.h"

using namespace std;

class VariableProvider {
public:
	virtual Lexeme* ExtractValue(string identificator) = 0;
};