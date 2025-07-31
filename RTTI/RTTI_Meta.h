#pragma once

// This macro adds meta information to a type
#define GENERATE_META(Class) \
class Class; \
template<> struct Meta <Class> { \
static constexpr Classes Type = Classes::Class; \
};

// Predeclared struct for meta information
template<class T> struct Meta;

// Enum type classes
enum class Classes
{
    IRTTI, ClassA, ClassB, ClassC, ClassD, ClassE
};
