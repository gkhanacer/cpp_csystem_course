#include <iostream>
#include <thread>
#include <atomic>
#include <syncstream>

std::atomic<bool> ga_start {false};

void func(char id)
{
    using namespace std::chrono;

    while (!ga_start)
    {
        std::osyncstream(std::cout) << "before\n";
        std::this_thread::yield(); // Provides a hint to the implementation to reschedule the execution of threads, allowing other threads to run.
        std::osyncstream(std::cout) << "after\n";
    }
    std::this_thread::sleep_for(500ms);
    std::osyncstream(std::cout) << id << '\n';
    std::osyncstream(std::cout) << "after loop\n";
    
}
int main()
{
    std::thread ar_t[26];

    for(char i{'A'}; auto & t : ar_t)
        t = std::thread(func, i++);

    ga_start = true;

    for(auto& t : ar_t)
        t.join();
    
}