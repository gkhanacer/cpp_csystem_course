#include <iostream>

void Swap(int* p, int* q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void Swap_ref(int& p, int& q) {
    int temp = p;
    p = q;
    q = temp;
}

int main(int argc, char const *argv[])
{
    int a = 454, b = 652;
    std::cout << "a: " << a << " - b: " << b << std::endl;
    Swap(&a, &b);
    std::cout << "a: " << a << " - b: " << b << std::endl;

    Swap_ref(a, b);
    std::cout << "a: " << a << " - b: " << b << std::endl;

    return 0;
}
