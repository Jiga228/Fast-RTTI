#include  "RTTI.h"

void IRTTI::TreeArray::push_back(const Classes type)
{
    size++;
    Classes* NewTree = new Classes[size];

    for (size_t i = 0; i < size - 1; ++i)
        NewTree[i] = Tree[i];

    NewTree[size - 1] = type;
}

IRTTI::TreeArray::TreeArray()
{
    Tree = new Classes;
    size = 1;
}

void IRTTI::SetType(const Classes type)
{
    this->type = type;
    //Tree.push_back(type);
}

IRTTI::IRTTI()
{
    SetType(Classes::IRTTI);
}

Classes IRTTI::RTTI_Kind() const
{
    return type;
}
