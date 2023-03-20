#include <iostream>
#include <atomic>

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha;

    std::atomic<int> a = 10;
    std::cout << "a = " << a << '\n';
    
    int temp = a.load();
    while(!a.compare_exchange_weak(temp, temp * 60))
        ;
    
    std::cout << "a = " << a << '\n';
    return 0;
}

// LOGIC
// if a == expected:
//     a = desired
//     return true
// else:
//     expected = a
//     return false