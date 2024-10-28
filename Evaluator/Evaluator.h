#pragma once
#include "Lexeme.h"
#include <vector>
#include <regex>
#include <stack>
#include <map>
#include "VariableProvider.h"
#include "NotImplementedException.h"

using namespace std;

class Evaluator {	

private:
	
	class DefaultVariableProvider : public VariableProvider {
		Lexeme* ExtractValue(string token) override {
			throw new NotImplementedException(token);
		};
	};
	string expression;
	VariableProvider* variableProvider;
	stack <Lexeme*> operands;
	stack <Lexeme*> operations;
	map <string, Lexeme*> variables;

public:

	void SetExpression(string expression);
	Evaluator();
	Evaluator(VariableProvider* variableProvider);
	Lexeme* Evaluate();
	string GetExpression();

};