#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

std::once_flag gflag; // define global once_flag

void func(int id)
{
    std::call_once(gflag, [id](){ //call_once calls only one thread, other threads wait for this process, and then all keep on.
        std::cout << id << " thread called.\n";
    });
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> tvec;

    for (size_t i = 0; i < 10; i++)
    {
        tvec.emplace_back(func, i);
    }

    for (auto & th : tvec)
    {
        th.join();
    }
    
    
    return 0;
}
