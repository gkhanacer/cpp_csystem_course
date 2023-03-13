#include <mutex>
#include <thread>
#include <iostream>

unsigned long long counter = 0;
std::mutex mtx;

void func()
{
    mtx.lock();
    std::unique_lock<std::mutex> guard {mtx, std::adopt_lock}; 
    for(unsigned long long i = 0; i < 1'000'000ull; ++i)
        ++counter;
}

int main(int argc, char const *argv[])
{
    std::thread t1{func};
    std::thread t2{func};
    std::thread t3{func};
    std::thread t4{func};
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << counter << '\n';    

    return 0;
}
