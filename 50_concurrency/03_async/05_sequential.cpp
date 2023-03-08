#include <iostream>
#include <thread>
#include <future>

int foo()
{
    return 1;
}

int func()
{
    return 1;
}

int main()
{
    auto ft_foo = std::async(foo);
    auto ft_func = std::async(func);  

    auto x = ft_foo.get() + ft_func.get(); // which one is run first? unspecified.
}