#include <iostream>
#include <atomic>
#include <concepts>

template <std::integral T>
void atomic_inc(std::atomic<T>& x)
{
    T val {x};
    while(!x.compare_exchange_weak(val, val +1)) {}
}

int main(int argc, char const *argv[])
{
    std::atomic<int> a = 10;
    std::cout << "a = " << a << '\n';

    atomic_inc(a);
    std::cout << "a = " << a << '\n';
    
    return 0;
}
