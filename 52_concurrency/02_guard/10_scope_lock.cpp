#include <mutex>
#include <thread>
#include <iostream>

std::mutex a_mtx;
std::mutex b_mtx;

using namespace std::literals;

void func()
{
    std::scoped_lock<std::mutex, std::mutex> guard {a_mtx, b_mtx};
    std::this_thread::sleep_for(100ms);
    std::cout << "func()" << std::endl;
}

void foo()
{
    std::scoped_lock guard {a_mtx, b_mtx}; // CTAD
    std::this_thread::sleep_for(100ms);
    std::cout << "bar()" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::thread t1{func};
    std::thread t2{foo};
    t1.join();
    t2.join();

    return 0;
}
