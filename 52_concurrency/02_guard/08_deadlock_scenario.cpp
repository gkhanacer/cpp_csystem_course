#include <mutex>
#include <thread>
#include <iostream>

std::mutex a_mtx;
std::mutex b_mtx;

using namespace std::literals;

void func()
{
    a_mtx.lock();
    std::this_thread::sleep_for(100ms);
    b_mtx.lock();
    std::cout << "func()" << std::endl;
    a_mtx.unlock();
    b_mtx.unlock();
}

void foo()
{
    b_mtx.lock();
    std::this_thread::sleep_for(100ms);
    a_mtx.lock();
    std::cout << "bar()" << std::endl;
    a_mtx.unlock();
    b_mtx.unlock();
}

int main(int argc, char const *argv[])
{
    std::thread t1{func};
    std::thread t2{foo};
    t1.join();
    t2.join();

    return 0;
}
