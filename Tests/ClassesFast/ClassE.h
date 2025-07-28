#pragma once

#include "ClassD.h"

GENERATE_META(ClassE)
class ClassE : public ClassD
{
public:
	virtual int foo();
};