#include <iostream>

// bir fonksiyonun parametresinin referans olması

void funcP(int *ptr) {
    *ptr = 999;
}

// call-by-value
void bar(int x) {
    x = 999;
}

// call-by-reference
void func(int &r) {
    r = 999;
}

int main(int argc, char const *argv[])
{
    int ival{ 3 };
    std::cout << ival << std::endl;

    bar(ival);
    std::cout << ival << std::endl;

    func(ival);
    std::cout << ival << std::endl;

    return 0;
}
