#include <future>
#include <iostream>

using namespace std::literals;

// function
void func(std::promise<int>&& iprom)
{
    std::this_thread::sleep_for(5s);
    iprom.set_value(20);
}


int main(int argc, char const *argv[])
{
    std::promise<int> prom;
    auto ftr = prom.get_future();
    
    std::thread th{func, std::move(prom)};

    std::future_status status{};
       
    do
    {
        status = ftr.wait_for(200ms);
        std::cout << ".... doing some work here\n";
    } while (status != std::future_status::ready);

    
    std::cout << "return value is : " << ftr.get() << '\n';

    th.join();
    
    return 0;
}
