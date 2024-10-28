#pragma once
#ifndef __NUMBER_H
#define __NUMBER_H

#include "Lexeme.h"
#include <string>

class Number : public Lexeme
{
public:
	Number();
	Number(std::string token);
	std::string TypeName() override;
};

#endif