#pragma once
#ifndef __COMMA_H
#define __COMMA_H

#include "Lexeme.h"
#include <string>

class Comma : public Lexeme
{
public:
	Comma();
	Comma(std::string);
	std::string TypeName() override;
};

#endif
