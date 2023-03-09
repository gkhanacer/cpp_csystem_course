#include <future>
#include <iostream>
#include <thread>

using namespace std::literals;

constexpr int x = 50;

long long fib(int n)
{
    return n < 3 ? 1 : fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[])
{
    
    auto ftr = std::async(fib, x);
    std::cout << "waif for response..\n";

    while (ftr.wait_for(100ms) == std::future_status::timeout)
    {
        std::cout << "." << std::flush;
    }

    auto result = ftr.get();
    std::cout << "answer : " << result << "\n";

    return 0;
}
