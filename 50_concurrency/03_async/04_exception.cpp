#include <iostream>
#include <thread>
#include <future>

int foo(int x)
{
	// throw std::runtime_error{ "error from func\n"};
    return 1;
}

int main()
{
    try
    {
        std::future<int> ft1 = std::async(foo, 5);   // outcome can take exception object.
        auto val = ft1.get();   
        std::cout << "return val = " << val;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}