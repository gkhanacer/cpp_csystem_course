#include <iostream>
#include "Sentence.h"

void func(Sentence s)
{
    std::cout << "funct cagrildi\n";
    s.print();
}

int main(int argc, char const *argv[])
{
    Sentence s1{"yine yagmur yagiyor istanbulda"};
    s1.print();
    std::cout << "uzunluk: " << s1.len() << "\n";

    func(s1);
    getchar();
    s1.print();

    return 0;
}
