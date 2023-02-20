#include <exception>
#include <stdexcept>
#include<iostream>

using namespace std;

void handle_excepion()
{
    cout << "handle_exception\n";
    throw;
}

void func()
{
    try
    {
        throw std::out_of_range("range hatasi");
    }
    catch(const std::exception& e)
    {
        std::cerr << "hata icinde yakalandi:" << e.what() << '\n';
        handle_excepion();
    }
}

int main(int argc, char const *argv[])
{
    try
    {
        func();
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "hata icinde yakalandi out of range" <<  '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << "hata icinde yakalandi exception" <<  '\n';
    }
    
    return 0;
}
