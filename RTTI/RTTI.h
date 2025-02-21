#pragma once

#include "RTTI_Meta.h"

// Interface RTTI
GENERATE_META(IRTTI)
class IRTTI
{
    struct TreeArray
    {
        size_t size;
        Classes* Tree;
        void push_back(const Classes type);
        TreeArray();
    };
    TreeArray Tree;
    Classes type;
protected:
    void SetType(Classes type);
    
    IRTTI();
    ~IRTTI() = default;
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
        return Meta<Kind>::Type == type;
    }
    
    template<class To, class From>
    static To* dyn_cast(From* object)
    {
        IRTTI* InterfaceOfObject = static_cast<IRTTI*>(object);
        if (IsA<To>(InterfaceOfObject->type))
            return reinterpret_cast<To*>(object);

        const size_t coutType = InterfaceOfObject->Tree.size - 1;
        for (size_t i = 0; i < coutType; ++i)
        {
            if (InterfaceOfObject->Tree.Tree[i] == Meta<To>::Type)
                return reinterpret_cast<To*>(object);
        }
        
        return nullptr;
    }
};