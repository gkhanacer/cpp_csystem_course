#include <future>
#include <iostream>

// promise & future ise ONE TIME COMM. CHANNER
// We can only set & get one time. If we try more than 1, std::future_error is thrown.
int main(int argc, char const *argv[])
{
    std::promise<int> prom;
    prom.set_value(10);

    try
    {
        prom.set_value(1);
    }
    catch(const std::future_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
