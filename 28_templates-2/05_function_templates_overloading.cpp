#include <iostream>
#include <string>

template <typename T>
void func (T x) 
{
    std::cout << "1" << '\n';
}

template <typename T>
void func (T x, T y) 
{
    std::cout << "2" << '\n';
}
 

int main(int argc, char const *argv[])
{
    func(10);
    return 0;
}
