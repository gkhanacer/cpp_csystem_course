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
	std::future<int> ft1 = std::async(foo, 5);
    auto ft2 = std::async(foo, 5);

    auto ft3 = std::async(bar);


    auto val = ft1.get();
    std::cout << "val = " << val << '\n';

    
}