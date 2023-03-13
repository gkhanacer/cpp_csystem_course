#include <mutex>
#include <thread>
#include <iostream>

std::mutex mtx;

int main(int argc, char const *argv[])
{
    using namespace std::literals;

    try
    {
        mtx.lock();
        std::this_thread::sleep_for(1s);
        mtx.lock(); // ub
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
      
    return 0;
}