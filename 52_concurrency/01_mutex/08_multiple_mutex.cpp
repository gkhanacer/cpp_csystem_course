#include <mutex>
#include <thread>
#include <iostream>

unsigned long long counter = 0;

std::mutex mtx_func;
std::mutex mtx_foo;

void func()
{
    std::lock_guard<std::mutex> guard {mtx_func}; 
    for(int i = 0; i < 1'000; ++i)
        ++counter;
}

void foo()
{
    std::lock_guard<std::mutex> guard {mtx_foo}; 
    for(int i = 0; i < 1'000; ++i)
        ++counter;
}

int main(int argc, char const *argv[])
{
    std::thread t1{func};
    std::thread t2{foo};
    t1.join();
    t2.join();

    std::cout << counter << '\n';    // NOT GUARANTEE or 2000. Guard should be on same mutex.

    return 0;
}
