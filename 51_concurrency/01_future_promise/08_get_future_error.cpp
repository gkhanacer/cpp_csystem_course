    #include <future>
#include <iostream>

// promise & future ise ONE TIME COMM. CHANNER
// We can only set & get one time. If we try more than 1, std::future_error is thrown.
int main(int argc, char const *argv[])
{
    std::promise<int> prom;
    auto ftr = prom.get_future();


    prom.set_value(10);
    std::cout << "val = " << ftr.get() << "\n";
    try
    {
        auto val = ftr.get();
    }
    catch(const std::future_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
