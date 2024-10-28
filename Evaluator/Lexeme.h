
#ifndef __LEXEME_H
#define __LEXEME_H

#include <string>

class Lexeme
{
public:
	Lexeme();
	Lexeme(std::string);
	std::string GetToken();
	virtual std::string TypeName() = 0;
	virtual int OperationPriority();
private:
	std::string token;
};

#endif
