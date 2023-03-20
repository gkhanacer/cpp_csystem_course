#include <iostream>
#include <atomic>

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha;

    std::atomic<int> a;
    std::cout << "a = " << a << '\n';
    std::cout << "a = " << a.load() << '\n';

    a.store(10);
    std::cout << "a = " << a << '\n';

    int expected = 10;
    std::cout << "expected = " << expected << '\n';

    bool result = a.compare_exchange_strong(expected, 50);

    std::cout << "a = " << a << '\n';
    std::cout << "result = " << result << '\n';
    std::cout << "expected = " << expected << '\n';

    return 0;
}

// LOGIC
// if a == expected:
//     a = desired
//     return true
// else:
//     expected = a
//     return false