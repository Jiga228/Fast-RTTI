#include <iostream>

#include "ClassesFast/ClassA.h"
#include "ClassesFast/ClassB.h"
#include "ClassesFast/ClassC.h"
#include "ClassesFast/ClassD.h"
#include "ClassesFast/ClassE.h"

int main()
{
    ClassA* a = new ClassD();

    {
        std::cout << "[Direct type casting]\n";

        ClassD* d1;
        clock_t first, second;
        clock_t realTime = 0;

        for (int i = 0; i < 100; ++i)
        {
            first = clock();
            for (unsigned long long i = 0; i < 10000000; ++i)
                d1 = RTTI::dyn_cast<ClassD>(a);
            second = clock();
            realTime += second - first;
        }
        std::cout << "RTTI::dyn_cast: " << realTime / 100 << "ms\n";

        if (d1 != nullptr)
            d1->foo();
    }



    {
        std::cout << "[Possible type casting]\n";

        ClassC* d1;
        clock_t first, second;
        clock_t realTime = 0;

        for (int i = 0; i < 100; ++i)
        {
            first = clock();
            for (unsigned long long i = 0; i < 10000000; ++i)
                d1 = RTTI::dyn_cast<ClassC>(a);
            second = clock();
            realTime += second - first;
        }
        std::cout << "RTTI::dyn_cast: " << realTime / 100 << "ms\n";

        if (d1 != nullptr)
            d1->foo();
    }


    {
        std::cout << "[Not possible type casting]\n";

        ClassE* d1;
        clock_t first, second;
        clock_t realTime = 0;

        for (int i = 0; i < 100; ++i)
        {
            first = clock();
            for (unsigned long long i = 0; i < 10000000; ++i)
                d1 = RTTI::dyn_cast<ClassE>(a);
            second = clock();
            realTime += second - first;
        }
        std::cout << "RTTI::dyn_cast: " << realTime / 100 << "ms\n";

        if (d1 != nullptr)
            d1->foo();
    }
}
