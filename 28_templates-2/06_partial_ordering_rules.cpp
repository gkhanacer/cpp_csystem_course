#include <iostream>
#include <string>

// partial ordering rules: daha specific olan seçilir!
template <typename T>
void func(T x)
{
    std::cout << "1" << '\n';
}

template <typename T>
void func(T *x)
{
    std::cout << "2" << '\n';
}

template <typename T>
void func(T **x)
{
    std::cout << "3" << '\n';
}


int main(int argc, char const *argv[])
{
    // int x = 10;
    // func(&x); // 2 

    // int x {24};
    // int *p {&x};
    // int** ptr{&p};
    // func(ptr); // 3  

    return 0;
}
