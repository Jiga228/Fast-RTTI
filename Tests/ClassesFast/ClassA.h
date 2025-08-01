#pragma once

#include "RTTI.h"

GENERATE_META(ClassA)
class ClassA : public IRTTI {
public:
	ClassA();
	virtual int foo();
};