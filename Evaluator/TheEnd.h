#pragma once
#ifndef __THEEND_H
#define __THEEND_H

#include "Lexeme.h"
#include <string>

class TheEnd : public Lexeme
{
public:
	std::string TypeName();
protected:
	static const std::string Name;
};

#endif
