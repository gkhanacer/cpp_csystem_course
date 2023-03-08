#include <iostream>
#include <thread>
#include <atomic>
#include <syncstream>

std::mutex mtx;

void func(int id)
{
    int x = 0;
    static int y = 0;
    thread_local int z = 0;

    ++x;
    ++z;
    std::lock_guard guard{mtx};
    ++y;

    std::osyncstream{std::cout} << "thread id " << id << " x (automatic storage)     = " << x << "\n";   
    std::osyncstream{std::cout} << "thread id " << id << " x (static storage)     = " << y << "\n";   
    std::osyncstream{std::cout} << "thread id " << id << " x (thread_local storage)     = " << z << "\n";   
}

void foo(int id)
{
    func(id);
    func(id);
    func(id);
}

int main()
{
    using namespace std;

    thread tx {foo, 0};
    thread ty {foo, 1};
    thread tz {foo, 2};

    tx.join();
    ty.join();
    tz.join();
}