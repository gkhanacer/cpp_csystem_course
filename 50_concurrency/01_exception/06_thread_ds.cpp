#include <iostream>
#include <thread>
#include <stdexcept>
#include <vector>
#include <mutex>



void cprint(char c)
{
    using namespace std::literals;

    for(int i = 0; i < 1000; ++i)
    {
        std::cout << c;
        std::this_thread::sleep_for(50ms);
    }
}
int main()
{
    
    std::vector<std::thread> tvec;

    for(int i = 0; i < 26; ++i)
    {
        tvec.emplace_back(cprint, i + 'A');
    }

    for(auto& t : tvec)
        t.join();
    
}