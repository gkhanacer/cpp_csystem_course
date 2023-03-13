#include <mutex>
#include <thread>
#include <iostream>

std::mutex a_mtx;
std::mutex b_mtx;

using namespace std::literals;

void func()
{
    std::lock(a_mtx, b_mtx);
    std::lock_guard guard1 {a_mtx, std::adopt_lock};
    std::lock_guard guard2 {b_mtx, std::adopt_lock};
    std::this_thread::sleep_for(100ms);
    std::cout << "func()" << std::endl;
}

void foo()
{
    std::lock(a_mtx, b_mtx);
    std::lock_guard guard1 {a_mtx, std::adopt_lock};
    std::lock_guard guard2 {b_mtx, std::adopt_lock};
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
