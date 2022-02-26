#include "Sentence.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Sentence s1{"C++ is a complex pl."};
    s1.print();

    // Sentence& r1 = s1;
    // Sentence& r2 = s1;
    // r1 = r2; // self assignment

    s1 = s1;

    // Sentence* ptr = &s1;
    // Sentence& r = s1;

    // s1 = *ptr;
    // *ptr = s1;
    // r = *ptr;

    s1.print();
    return 0;
}
