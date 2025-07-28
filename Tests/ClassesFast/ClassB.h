#pragma once

#include "ClassA.h"

GENERATE_META(ClassB)
class ClassB : public ClassA{
public:
	virtual int foo();
};