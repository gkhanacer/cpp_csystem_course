#include <iostream>
#include <thread>
#include <stdexcept>
#include <vector>
#include <mutex>

std::vector<std::exception_ptr> g_ex_vec;
std::mutex g_mutex;

void f1()
{
    throw std::runtime_error{"exceptionn from f1"};
}

void f2()
{
    throw std::runtime_error{"exceptionn from f2"};
}

void th_func1()
{
    try
    {
        f1();
    }
    catch(const std::exception& e)
    {
        std::lock_guard guard{g_mutex};
        g_ex_vec.push_back(std::current_exception());
    }
}

void th_func2()
{
    try
    {
        f2();
    }
    catch(const std::exception& e)
    {
        std::lock_guard guard{g_mutex};
        g_ex_vec.push_back(std::current_exception());
    }
}

int main()
{
    std::thread t1{th_func1};
    std::thread t2{th_func2};
    t1.join();
    t2.join();

    for(auto const & ex : g_ex_vec)
    {
        try
        {
            if (ex != nullptr)
                std::rethrow_exception(ex);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
}