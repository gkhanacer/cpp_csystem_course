#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

std::once_flag gflag; // define global once_flag

using namespace std::literals;

void func()
{
    std::this_thread::sleep_for(100ms);

    std::call_once(gflag, [](){
        std::cout << " registered in func.\n";
    });
}

void bar()
{
    std::this_thread::sleep_for(100ms);

    std::call_once(gflag, [](){
        std::cout << " registered in bar.\n";
    });
}


int main(int argc, char const *argv[])
{
    std::vector<std::thread> tvec;

    for (size_t i = 0; i < 10; i++)
    {
        if (i % 2 == 0) tvec.emplace_back(func);
        else tvec.emplace_back(bar);
    }

    for (auto & th : tvec)
    {
        th.join();
    }
    
    
    return 0;
}
