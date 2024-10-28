#pragma once
#ifndef __OPERATION_H
#define __OPERATION_H

#include "Lexeme.h"
#include <stack>
#include <string>

class Operation : public Lexeme
{
private:
	
	static Lexeme* Add(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* GreaterThan(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* Div(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* Mul(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* Sub(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* GreaterThanOrEqualTo(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* LessThan(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* LessThanOrEqualTo(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* EqualTo(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* NotEqualTo(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* And(Lexeme* operand1, Lexeme* operand2);
	static Lexeme* Or(Lexeme* operand1, Lexeme* operand2);

public:

	Operation();
	Operation(std::string token);
	std::string TypeName() override;
	Lexeme* Evaluate(std::stack <Lexeme*>& operands);
	int OperationPriority() override;
};

#endif