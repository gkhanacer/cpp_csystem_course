#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std::literals;

std::string get_str_letters(int n)
{
    std::string s(n, '\0');

    std::generate_n(s.begin(), n, [](){ return rand() % 26 + 'A'; });
    std::this_thread::sleep_for(3s);
    return s;
}

std::string get_str_digits(int n)
{
    std::string s(n, '\0');

    std::generate_n(s.begin(), n, [](){ return rand() % 10 + '0'; });
    std::this_thread::sleep_for(3s);
    return s;
}


int main(int argc, char const *argv[])
{
    auto start = std::chrono::steady_clock::now();
    
    auto ft1 = std::async(std::launch::async, get_str_letters, 20);
    auto ft2 = std::async(std::launch::async, get_str_digits, 20);

    // get() function will be called automaticaly for ft1 and ft2 end of the program.
}
