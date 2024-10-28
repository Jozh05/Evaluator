#include "Operation.h"
#include "Lexeme.h"
#include "Number.h"
#include "Boolean.h"
#include "InvalidOperation.h"
#include "LexemeFactory.h"


Operation::Operation() : Lexeme("*") { }
Operation::Operation(std::string token) : Lexeme(token) { }

std::string Operation::TypeName()
{
	return "Operation";
}

Lexeme* Operation::Evaluate(std::stack <Lexeme*>& operands) {
	
	Lexeme* operand2 = operands.top();
	operands.pop();
	Lexeme* operand1 = operands.top();
	operands.pop();
	std::string token = this->GetToken();
	if (token == "+" ) 
		return Add(operand1, operand2);
	if (token == ">")
		return GreaterThan(operand1, operand2);
	if (token == "<")
		return LessThan(operand1, operand2);
	if (token == "<=")
		return LessThanOrEqualTo(operand1, operand2);
	if (token == ">=")
		return GreaterThanOrEqualTo(operand1, operand2);
	if (token == "and")
		return And(operand1, operand2);
	if (token == "or")
		return Or(operand1, operand2);
	if (token == "-")
		return Sub(operand1, operand2);
	if (token == "*")
		return Mul(operand1, operand2);
	if (token == "/")
		return Div(operand1, operand2);
	if (token == "=")
		return EqualTo(operand1, operand2);
	if (token == "!=" || token == "<>")
		return NotEqualTo(operand1, operand2);
	throw new InvalidOperation(token);
}

Lexeme* Operation::Add(Lexeme* operand1, Lexeme* operand2) {
	double op2 = stod(operand2->GetToken());
	double op1 = stod(operand1->GetToken());
	return new Number(std::to_string(op1 + op2));
}

Lexeme* Operation::GreaterThan(Lexeme* operand1, Lexeme* operand2) {
	double op2 = stod(operand2->GetToken());
	double op1 = stod(operand1->GetToken());
	return new Boolean(op1 > op2 ? "true" : "false");
}


Lexeme* Operation::Sub(Lexeme* operand1, Lexeme* operand2) {
	double op2 = stod(operand2->GetToken());
	double op1 = stod(operand1->GetToken());
	return new Number(std::to_string(op1 - op2));
}


Lexeme* Operation::Mul(Lexeme* operand1, Lexeme* operand2) {
	double op2 = stod(operand2->GetToken());
	double op1 = stod(operand1->GetToken());
	return new Number(std::to_string(op1 * op2));
}


Lexeme* Operation::Div(Lexeme* operand1, Lexeme* operand2) {
	double op2 = stod(operand2->GetToken());
	double op1 = stod(operand1->GetToken());
	if (op2 == (double)0)
		throw new invalid_argument(std::to_string(op2));
	return new Number(std::to_string(op1 / op2));
}


Lexeme* Operation::EqualTo(Lexeme* operand1, Lexeme* operand2) {
	if (LexemeFactory::IsNumber(operand1->GetToken()) && LexemeFactory::IsNumber(operand2->GetToken())) {
		double op2 = stod(operand2->GetToken());
		double op1 = stod(operand1->GetToken());
		return new Boolean(op1 == op2 ? "true" : "false");
	}
	if (LexemeFactory::IsBoolean(operand1->GetToken()) && LexemeFactory::IsBoolean(operand2->GetToken())) {
		bool op2 = operand2->GetToken() == "true" ? true : false;
		bool op1 = operand1->GetToken() == "true" ? true : false;
		return new Boolean(op1 == op2 ? "true" : "false");
	}
}


Lexeme* Operation::GreaterThanOrEqualTo(Lexeme* operand1, Lexeme* operand2) {
	if (LexemeFactory::IsNumber(operand1->GetToken()) && LexemeFactory::IsNumber(operand2->GetToken())) {
		double op2 = stod(operand2->GetToken());
		double op1 = stod(operand1->GetToken());
		return new Boolean(op1 >= op2 ? "true" : "false");
	}
}


Lexeme* Operation::LessThan(Lexeme* operand1, Lexeme* operand2) {
	double op2 = stod(operand2->GetToken());
	double op1 = stod(operand1->GetToken());
	return new Boolean(op1 < op2 ? "true" : "false");
}


Lexeme* Operation::LessThanOrEqualTo(Lexeme* operand1, Lexeme* operand2) {
	double op2 = stod(operand2->GetToken());
	double op1 = stod(operand1->GetToken());
	return new Boolean(op1 <= op2 ? "true" : "false");
}


Lexeme* Operation::NotEqualTo(Lexeme* operand1, Lexeme* operand2) {
	bool result = EqualTo(operand1, operand2)->GetToken() == "true" ? true : false;
	return new Boolean( !result ? "true" : "false");
}


Lexeme* Operation::And(Lexeme* operand1, Lexeme* operand2) {
	bool op1 = operand1->GetToken() == "true" ? true : false;
	bool op2 = operand2->GetToken() == "true" ? true : false;
	return new Boolean(op1 && op2 ? "true" : "false");
}


Lexeme* Operation::Or(Lexeme* operand1, Lexeme* operand2) {
	bool op1 = operand1->GetToken() == "true" ? true : false;
	bool op2 = operand2->GetToken() == "true" ? true : false;
	return new Boolean(op1 || op2 ? "true" : "false");
}


int Operation::OperationPriority() {
	
	if (GetToken() == "or")
		return 1;
	if (GetToken() == "and")
		return 1;
	if (GetToken() == "=")
		return 2;
	if (GetToken() == ">")
		return 2;
	if (GetToken() == ">=")
		return 2;
	if (GetToken() == "<")
		return 2;
	if (GetToken() == "<=")
		return 2;
	if (GetToken() == "+")
		return 3;
	if (GetToken() == "-")
		return 3;
	if (GetToken() == "*")
		return 4;
	if (GetToken() == "/")
		return 4;
	return 0;
}