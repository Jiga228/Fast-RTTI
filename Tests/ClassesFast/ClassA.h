#pragma once

#include "RTTI.h"

GENERATE_META(ClassA)
class ClassA : public IRTTI {
public:
	virtual int foo();
};