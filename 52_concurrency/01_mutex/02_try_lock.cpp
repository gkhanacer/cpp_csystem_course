#include <mutex>
#include <thread>
#include <iostream>

int counter {};             // not atomic shared variable
std::mutex counter_mtx;     // counter mutex

void try_increase()
{
    for(int i = 0; i < 100'000; ++i) 
    {
        if (counter_mtx.try_lock())
        {
            ++counter;
            counter_mtx.unlock();
        }

        // counter_mtx.lock();
        // ++counter;
        // counter_mtx.unlock();
    }
}

int main(int argc, char const *argv[])
{
    std::thread ar_t[10];

    for (int i = 0; i < 10; ++i)
        ar_t[i] = std::thread{try_increase};

    for(auto& th : ar_t)
        th.join();

    std::cout << counter << '\n';    

    return 0;
}
