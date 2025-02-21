#pragma once

#include "RTTI_Meta.h"

// Interface RTTI
class IRTTI
{
protected:
    Classes type;
    virtual ~IRTTI() = default;
public:
    Classes RTTI_Kind() const;

    friend class RTTI;
};

// RTTI metods
class RTTI final
{
    RTTI() = default;
public:
    template<class Kind>
    static bool IsA(Classes type)
    {
        return Meta<Kind>::TypeStr == type;
    }
    template<class To, class From>
    static To* dyn_cast(From* object)
    {
        return IsA<To>(static_cast<IRTTI*>(object)->type) ? reinterpret_cast<To*>(object) : nullptr;
    }
};