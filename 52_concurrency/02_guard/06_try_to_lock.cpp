#include <mutex>
#include <thread>
#include <iostream>

unsigned long long counter = 0;
std::mutex mtx;

void func()
{
    std::unique_lock<std::mutex> guard {mtx, std::try_to_lock};

    // if (guard.owns_lock())
    if (guard)  // operator bool
    {
        for(unsigned long long i = 0; i < 1'000'000ull; ++i)
            ++counter;
    }
    else
    {
        std::cout << "lock couldnt acquired.\n";
    }
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
