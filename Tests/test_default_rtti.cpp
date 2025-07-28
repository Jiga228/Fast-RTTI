#include <iostream>

#include "ClassesDefault/ClassA.h"
#include "ClassesDefault/ClassB.h"
#include "ClassesDefault/ClassC.h"
#include "ClassesDefault/ClassD.h"
#include "ClassesDefault/ClassE.h"

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
                d1 = dynamic_cast<ClassD*>(a);
            second = clock();
            realTime += second - first;
        }
        std::cout << "dynami_cast: " << realTime / 100 << "ms\n";
        realTime = 0;

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
                d1 = dynamic_cast<ClassC*>(a);
            second = clock();
            realTime += second - first;
        }
        std::cout << "dynami_cast: " << realTime / 100 << "ms\n";
        realTime = 0;

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
                d1 = dynamic_cast<ClassE*>(a);
            second = clock();
            realTime += second - first;
        }
        std::cout << "dynami_cast: " << realTime / 100 << "ms\n";
        realTime = 0;

        if (d1 != nullptr)
            d1->foo();
    }
}
