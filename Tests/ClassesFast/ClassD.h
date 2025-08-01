#pragma once

#include "ClassC.h"

GENERATE_META(ClassD)
class ClassD : public ClassC {
public:
	ClassD();
	virtual int foo();
};