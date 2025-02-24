#include  "RTTI.h"

void IRTTI::FastContainer::push_back(const Classes newType)
{
    if (0 == _size)
    {
        ++_size;
        array = new Classes;
        *array = newType;
    }
    else
    {
        ++_size;
        Classes* NewArray = new Classes[_size];

        long long indexObject = _size - 1;
        for (long long i = 0, j = 0; i < _size - 1; ++i, ++j)
        {
            if (newType < array[i] && indexObject == _size - 1)
            {
                indexObject = j;
                ++j;
            }

            NewArray[j] = array[i];
        }
        NewArray[indexObject] = newType;

        delete[] array;
        array = NewArray;
    }
}

bool IRTTI::FastContainer::find(const Classes& Type) const
{
    long long low = 0;
    long long high = _size - 1;

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (static_cast<int>(array[mid]) == static_cast<int>(Type))
            return true;
        
        if (static_cast<int>(array[mid]) > static_cast<int>(Type))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;
}

void IRTTI::SetType(const Classes Type)
{
    this->type = Type;
    Tree.push_back(Type);
}

IRTTI::IRTTI()
{
    SetType(Classes::IRTTI);
}

Classes RTTI::GetType(const IRTTI* object)
{
    return object->type;
}
