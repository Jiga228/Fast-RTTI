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

    // Convert enum to string
    [[nodiscard]]
    static const char* enum_to_string(const Classes type)
    {
        switch (type)
        {
        case Classes::IRTTI: return "IRTTI";
        default: return "Undefined";
        }
    }
    
    // That method allow compare given type with real type object
    template<class Kind>
    static bool IsA(const Classes type)
    {
        return Meta<Kind>::Type == type;
    }
public:
    template<class Kind>
    static bool IsA(const IRTTI* object)
    {
        return IsA<Kind>(object->type);
    }

    // That method realized dynamic_cast
    template<class To, class From>
    static To* dyn_cast(From* object)
    {
        IRTTI* InterfaceOfObject = static_cast<IRTTI*>(object);
        if (IsA<To>(InterfaceOfObject->type))
            return reinterpret_cast<To*>(object);

        if (InterfaceOfObject->Tree.find(Meta<To>::Type))
            return reinterpret_cast<To*>(object);
        
        return nullptr;
    }

    // That method return real type object in the form of enum value
    static Classes GetType(const IRTTI* object);

    // That method return real type in the form of string
    [[nodiscard]]
    static const char* GetTypeStr(const IRTTI* object);
};