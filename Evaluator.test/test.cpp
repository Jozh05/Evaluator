#include "pch.h"
#include <cstdio>
#include "..\\Evaluator\\LexemeFactory.h"
#include "..\\Evaluator\\Number.h"
#include "..\\Evaluator\\Comma.h"
#include <string.h>
#include "..\\Evaluator\\Evaluator.h"
#include "TestVariableProvider.h"


namespace LexemeFactoryTests
{

	TEST(LexemeFactoryTest, CreateOpeningParenthesIsOK) {
		Lexeme* lexeme = LexemeFactory::Create("(");
		EXPECT_EQ(lexeme->TypeName().compare("Parenthesis"), 0);
	}


	TEST(LexemeFactoryTest, CreateClosingParenthesIsOK) {
		Lexeme* lexeme = LexemeFactory::Create(")");
		EXPECT_EQ(lexeme->TypeName().compare("Parenthesis"), 0);
	}


	TEST(LexemeFactoryTest, CreateTrueBooleanisIsOK) {
		Lexeme* lexeme = LexemeFactory::Create("TrUe");
		EXPECT_EQ(lexeme->TypeName().compare("Boolean"), 0);
		EXPECT_EQ(lexeme->GetToken().compare("true"), 0);
	}

	TEST(LexemeFactoryTest, CreateFalseBooleanIsOK) {
		Lexeme* lexeme = LexemeFactory::Create("fALSe");
		EXPECT_EQ(lexeme->TypeName().compare("Boolean"), 0);
		EXPECT_EQ(lexeme->GetToken().compare("false"), 0);
	}

	TEST(LexemeFactoryTest, CreateNumberIsOK) {
		Lexeme* lexeme = LexemeFactory::Create("123.456");
		EXPECT_EQ(lexeme->TypeName().compare("Number"), 0);
		EXPECT_EQ(lexeme->GetToken().compare("123.456"), 0);
	}

	TEST(LexemeFactoryTest, CreateArithmeticOperationIsOK) {
		Lexeme* lexeme = LexemeFactory::Create("+");
		EXPECT_EQ(lexeme->TypeName().compare("Operation"), 0);
		EXPECT_EQ(lexeme->GetToken().compare("+"), 0);
	}

	TEST(LexemeFactoryTest, CreateConditionOperationIsOK) {
		Lexeme* lexeme = LexemeFactory::Create(">");
		EXPECT_EQ(lexeme->TypeName().compare("Operation"), 0);
		EXPECT_EQ(lexeme->GetToken().compare(">"), 0);
	}
}

namespace EvaluatorTests {
	TEST(EvaluateTest, GreaterThanEvaluateIsOK) {
		std::string expression = "3 > 2";
		Evaluator* evaluator = new Evaluator();
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("true"), 0);
		EXPECT_EQ(result->TypeName().compare("Boolean"), 0);
	}

	TEST(EvaluateTest, AddEvaluateIsOK) {
		std::string expression = "3 + 2";
		Evaluator* evaluator = new Evaluator();
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("5.000000"), 0);
		EXPECT_EQ(result->TypeName().compare("Number"), 0);
	}

	TEST(EvaluateTest, EvaluateIsOK) {
		std::string expression = "3 + (2 + 2) > 10";
		Evaluator* evaluator = new Evaluator();
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("false"), 0);
		EXPECT_EQ(result->TypeName().compare("Boolean"), 0);
	}

	TEST(EvaluateTest, SubEvaluateIsOK) {
		std::string expression = "3 - 2";
		Evaluator* evaluator = new Evaluator();
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("1.000000"), 0);
		EXPECT_EQ(result->TypeName().compare("Number"), 0);
	}

	TEST(EvaluateTest, MulEvaluateIsOK) {
		std::string expression = "3 * 2";
		Evaluator* evaluator = new Evaluator();
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("6.000000"), 0);
		EXPECT_EQ(result->TypeName().compare("Number"), 0);
	}

	TEST(EvaluateTest, OrEvaluateIsOK) {
		std::string expression = "4 * 9 / 6 - 4 > 1 or 3 < 2";
		Evaluator* evaluator = new Evaluator();
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("true"), 0);
		EXPECT_EQ(result->TypeName().compare("Boolean"), 0);
	}

	TEST(EvaluateTest, AndEvaluateIsOK) {
		std::string expression = "4 > 1 and 3 < 2";
		Evaluator* evaluator = new Evaluator();
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("false"), 0);
		EXPECT_EQ(result->TypeName().compare("Boolean"), 0);
	}

	TEST(EvaluateTest, ParenthesisExpressionEvaluateIsOK) {
		std::string expression = "42*(2-1)/(7*(1+1))*3";
		Evaluator* evaluator = new Evaluator();
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("9.000000"), 0);
		EXPECT_EQ(result->TypeName().compare("Number"), 0);
	}

	TEST(EvaluateTest, VariableProviderEvaluateIsOK) {
		std::string expression = "(A + B) = 30";
		Evaluator* evaluator = new Evaluator(new TestVariableProvider());
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("true"), 0);
		EXPECT_EQ(result->TypeName().compare("Boolean"), 0);
	}

	TEST(EvaluateTest, AndWithVariableProviderEvaluateIsOK) {
		std::string expression = "(a + B + A) = 30 and 20 < 30";
		Evaluator* evaluator = new Evaluator(new TestVariableProvider());
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("false"), 0);
		EXPECT_EQ(result->TypeName().compare("Boolean"), 0);
	}

	TEST(EvaluateTest, BoolVariableEvaluateIsOK) {
		std::string expression = "true or 40 < 30 = true";
		Evaluator* evaluator = new Evaluator(new TestVariableProvider());
		evaluator->SetExpression(expression);
		Lexeme* result = evaluator->Evaluate();
		EXPECT_EQ(result->GetToken().compare("true"), 0);
		EXPECT_EQ(result->TypeName().compare("Boolean"), 0);
	}
}