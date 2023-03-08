#include <future>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::promise<int> prom;

    std::future<int> ftr = prom.get_future(); 

    prom.set_value(991);

    auto val = ftr.get(); // get function has called. then future obhject is not valid now.

    if (ftr.valid())
        std::cout << "future object is valid.\n";
    else
        std::cout << "future object is not valid.\n";

    try
    {
        val = ftr.get();    // if we call get more time, UB, but lots of compiler throws exception (not guaranteed)
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
