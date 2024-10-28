#pragma once
#ifndef __BOOLEAN_H
#define __BOOLEAN_H

#include "Lexeme.h"
#include <string>

class Boolean : public Lexeme
{
public:
	Boolean();
	Boolean(std::string);
	std::string TypeName() override;
};

#endif
