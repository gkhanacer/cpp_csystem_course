#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
#include <syncstream>

int counter {};             // not atomic shared variable
std::timed_mutex counter_mtx;     // counter mutex

using namespace std::literals;

void try_increase(int i)
{
    if (counter_mtx.try_lock_for(50ms))
    {
        ++counter;
        std::this_thread::sleep_for(10ms);
        std::osyncstream{std::cout} << "thread : " << i << " in critic section.\n";
        counter_mtx.unlock();
    } else {
        std::osyncstream{std::cout} << "thread : " << i << " couldnt enter in critic section.\n";
    }
}

int main(int argc, char const *argv[])
{
    std::thread ar_t[10];

    for (int i = 0; i < 10; ++i)
        ar_t[i] = std::thread{try_increase, i};

    for(auto& th : ar_t)
        th.join();

    std::osyncstream{std::cout} << counter << '\n';    

    return 0;
}
