#include <iostream>
#include <thread>
#include <atomic>
#include <syncstream>

thread_local int tval { 0 };

void func(int *p)
{
    *p = 42;
    std::osyncstream{std::cout} << "tval is " << tval << "\n";   
}
int main()
{
    std::osyncstream{std::cout} << "tval is " << tval << "\n";
    tval = 9;
    std::osyncstream{std::cout} << "tval is " << tval << "\n";

    std::thread ta{func, &tval};
    ta.join();
    std::osyncstream{std::cout} << "tval is " << tval << "\n";
}

