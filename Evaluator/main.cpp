#include "LexemeFactory.h"


int main()
{
	Lexeme* lexeme = LexemeFactory::Create("fALSe");
	printf(lexeme->TypeName().c_str());
	printf(lexeme->GetToken().c_str());
	return 0;
}