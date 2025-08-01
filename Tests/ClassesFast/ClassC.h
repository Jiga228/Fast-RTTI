#pragma once

#include "ClassB.h"

GENERATE_META(ClassC)
class ClassC : public ClassB {
public:
	ClassC();
	virtual int foo();
};