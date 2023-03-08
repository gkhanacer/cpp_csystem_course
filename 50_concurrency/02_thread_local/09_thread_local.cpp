#include <iostream>
#include <thread>
#include <atomic>
#include <syncstream>

thread_local int tval { 0 };

void func(const std::string& thread_name)
{
    ++tval; // doesnt require sync
    std::osyncstream{std::cout} << "tval in thread " << thread_name << " is " << tval << "\n";
    
}
int main()
{
    std::thread ta{func, "a"};
    std::thread tb{func, "b"};
    ta.join();
    tb.join();    
}