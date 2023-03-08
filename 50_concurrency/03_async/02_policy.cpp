#include <iostream>
#include <thread>
#include <future>

int foo(int x)
{
	std::cout << "foo called! x = " << x << "\n";
    
    return x * x;
}

class Myclass {};

Myclass bar() {
    auto c = Myclass{};
    return c;
}

int main()
{
    // 1. async
    std::future<int> ft1 = std::async(std::launch::async, foo, 5);
    auto val = ft1.get(); // if workload is complted, there is no block. We can get return type directly. If not, it blocks like join()
    std::cout << "val = " << val << '\n';

    // 2.deferred
    auto ft2 = std::async(std::launch::deferred, foo, 2);
    auto val2 = ft2.get(); // If deferred, the function is called when the get() is called.
    std::cout << "val2 = " << val2 << '\n';

    // 3. depends on compiler
    auto ft3 = std::async(std::launch::async | std::launch::deferred, foo, 3);
    auto val3 = ft3.get();
    std::cout << "val3 = " << val3 << '\n';

    // To guarantee of calling function, we should storage the return type, and then call get() method.

    // get() function is called only ONCE!!!! Second or more calls are UB. Generally returns exception

}