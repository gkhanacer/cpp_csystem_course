#include <future>
#include <iostream>

// we can check whether get() function was called before or not.
// if called before -> false
// not called before -> true
int main(int argc, char const *argv[])
{
    std::promise<int> prom;
    auto ftr = prom.get_future();

    prom.set_value(10);
    std::cout << "val = " << ftr.get() << "\n";
    
    if (ftr.valid())
        std::cout << "future is valid. You can call get() function";
    else
        std::cout << "future is NOT valid. You cannot call get() function";

    return 0;
}
