#include <future>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::promise<int> prom;

    std::future<int> ftr = prom.get_future(); // promise object doesnt need to be set to get future object. 

    if (ftr.valid())  // get was not called yet.
        std::cout << "future object is valid.\n";
    else
        std::cout << "future object is not valid.\n";

    return 0;
}
