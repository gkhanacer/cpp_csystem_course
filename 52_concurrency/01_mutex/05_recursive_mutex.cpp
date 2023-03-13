#include <mutex>
#include <thread>
#include <iostream>

int counter {};             // not atomic shared variable
std::recursive_mutex rmtx;     // counter mutex

void rfunc(char c, int n)
{
    if (n < 0)
        return;
    
    rmtx.lock();
    std::cout << c << ' ' << counter++ << '\n';
    rfunc(c, n-1);
    rmtx.unlock();
}

int main(int argc, char const *argv[])
{
    std::thread tx {rfunc, 'x', 10};
    std::thread ty {rfunc, 'y', 10};
    tx.join();
    ty.join();

    return 0;
}