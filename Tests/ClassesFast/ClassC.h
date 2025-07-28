#pragma once

#include "ClassB.h"

GENERATE_META(ClassC)
class ClassC : public ClassB {
public:
	virtual int foo();
};