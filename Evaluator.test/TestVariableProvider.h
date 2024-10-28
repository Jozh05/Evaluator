#pragma once
#include "..\Evaluator\VariableProvider.h"

class TestVariableProvider : public VariableProvider {
public:
	Lexeme* ExtractValue(string token) override;
};