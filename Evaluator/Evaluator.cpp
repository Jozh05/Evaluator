#include "Evaluator.h"
#include "LexemeFactory.h"
#include "Operation.h"

Evaluator::Evaluator() : Evaluator(new DefaultVariableProvider()){}


Evaluator::Evaluator(VariableProvider* variableProvider) {
	this->variableProvider = variableProvider;
	expression = string();
}



void Evaluator::SetExpression(string expression) {
	while (!operands.empty())
		operands.pop();
	while (!operations.empty())
		operations.pop();
	this->expression = expression;
}


Lexeme* Evaluator::Evaluate() {
	regex expr("and|or|[a-zA-Z][a-zA-Z0-9_]*|[0-9]*\\.?[0-9]+|[\\/]|[+]|[-]|[*]|('.*?')|[(]|[)]|[!<>=]{1,2}|,|[|]{2}");
	vector<smatch> lexemes{ sregex_iterator(expression.begin(), expression.end(), expr), sregex_iterator()};
	for (int i = 0; i < lexemes.size(); i++) {
		Lexeme* lexeme = LexemeFactory::Create(lexemes[i].str());
		if (lexeme->TypeName() == "TheEnd")
			break;
		if (lexeme->TypeName() == "Operation") {
			while (!operations.empty()) {
				Lexeme* operation = operations.top();
				if (LexemeFactory::IsParenthesis(operation->GetToken()))
					break;
				if (operation->OperationPriority() < lexeme->OperationPriority())
					break;
				operations.pop();
				operands.push(((Operation*)operation)->Evaluate(operands));
			}
			operations.push(lexeme);
		}
		else if (lexeme->TypeName() == "Identificator") {
			std::string token = lexeme->GetToken();
			if (variables.count(token) == 0) {
				variables[token] = variableProvider->ExtractValue(token);
			}
			operands.push(variables[token]);
		}
		else if (lexeme->TypeName() == "Parenthesis") {
			if (lexeme->GetToken() == "(")
				operations.push(lexeme);
			else {
				while (!operations.empty()) {
					Lexeme* operation = operations.top();
					operations.pop();
					if (operation->TypeName() == "Parenthesis")
						break;
					operands.push(((Operation*)operation)->Evaluate(operands));
				}
			}
		}
		else if (lexeme->TypeName() == "Number" || lexeme->TypeName() == "Boolean") 
			operands.push(lexeme);
	}
	
	while (!operations.empty()) {
		Lexeme* operation = operations.top();
		operations.pop();
		operands.push(((Operation*)operation)->Evaluate(operands));
	}
	
	Lexeme* result = operands.top();
	operands.pop();
	return result;
}


string Evaluator::GetExpression() {
	return expression;
}



