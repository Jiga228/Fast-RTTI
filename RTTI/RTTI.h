#pragma once

#include "RTTI_Meta.h"

// Interface RTTI
GENERATE_META(IRTTI)
class IRTTI
{
    // Fast array
    class FastContainer final
    {
        long long _size = 0;
        Classes* array = nullptr;
    public:
        long long constexpr size() const { return _size; }
        void push_back(const Classes object);
        bool find(const Classes& Type) const;

        ~FastContainer();
    };
    FastContainer Tree;
    Classes type;
protected:
    // That method set type value and add type to inheritance tree
    void SetType(Classes Type);
    
    IRTTI();
    ~IRTTI() = default;
    
    friend class RTTI;
};

// RTTI methods
class RTTI final
{
    RTTI() = default;

public:
    template<class Kind>
    static bool IsA(const IRTTI* object)
    {
        return Meta<Kind>::Type == object->type;
    }

    // That method realized dynamic_cast
    template<class To, class From>
    static To* dyn_cast(From* object)
    {
        IRTTI* InterfaceOfObject = static_cast<IRTTI*>(object);
        if (IsA<To>(object))
            return reinterpret_cast<To*>(object);

        if (InterfaceOfObject->Tree.find(Meta<To>::Type))
            return reinterpret_cast<To*>(object);
        
        return nullptr;
    }

    // That method return real type object in the form of enum value
    static Classes GetType(const IRTTI* object);
};