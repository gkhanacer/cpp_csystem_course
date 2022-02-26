#include <iostream>
#include "Sentence.h"

int main(int argc, char const *argv[])
{
    Sentence s1{"C++ is a complex pl."};
    s1.print();
    if(1)
    {
        Sentence s2{"Python is a good and easy pl."};
        s2 = s1;
        s2.print();
    }
    (void*)getchar();

    s1.print();

    return 0;
}
