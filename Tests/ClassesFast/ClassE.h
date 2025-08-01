#pragma once

#include "ClassD.h"

GENERATE_META(ClassE)
class ClassE : public ClassD
{
public:
	ClassE();
	virtual int foo();
};