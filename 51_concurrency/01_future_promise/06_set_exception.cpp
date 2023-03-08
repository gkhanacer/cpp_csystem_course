#include <future>
#include <iostream>
#include <exception>

struct Div
{
    void operator()(std::promise<int>&& prom, int x, int y)const
    {
        try
        {
            if (y == 0)
            {
                auto err_str = "devide by zero error " + std::to_string(x) + " / " + std::to_string(y);
                throw std::runtime_error(err_str); 
            }
            prom.set_value(x / y);
        }
        catch(...)
        {
            prom.set_exception(std::current_exception());
        }
    }
};

void func(int x, int y)
{
    std::promise<int> div_prom;
    std::future<int> ftr_div = div_prom.get_future();

    std::thread td {Div{}, std::move(div_prom), x, y}; // there is no move here. because there is no move ctor call. We just sent rval to function.
    try
    {
        std::cout << ftr_div.get() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception caught: " << e.what() << '\n';
    }
    
    td.join();
}
int main(int argc, char const *argv[])
{
    func(12, 4);
    func(12, 0);
    return 0;
}
