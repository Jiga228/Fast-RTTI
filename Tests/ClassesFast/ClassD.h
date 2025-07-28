#pragma once

#include "ClassC.h"

GENERATE_META(ClassD)
class ClassD : public ClassC {
public:
	virtual int foo();
};