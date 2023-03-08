#include <iostream>
#include <thread>
#include <future>

int f1()
{
    return 1;
}

int f2()
{
    return 2;
}

int f3()
{
    return 3;
}

class Myclass 
{
public:
    Myclass()
    {
        std::cout << "ctor\n";
    }
};

Myclass foo()
{
    Myclass x;
    return x;
}

int main()
{
	std::future<int> ft1 = std::async(std::launch::async, f1);
	std::future<int> ft2 = std::async(std::launch::async, f2);
	std::future<int> ft3 = std::async(std::launch::async, f3);


    std::cout << ft1.get() << "\n";
    std::cout << ft2.get() << "\n";
    std::cout << ft3.get() << "\n";

    std::async(std::launch::async, foo);    // not guarantee to call ctor.
}