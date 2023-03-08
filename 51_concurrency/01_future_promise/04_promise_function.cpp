#include <future>
#include <iostream>

// function
void sum_square(std::promise<int>&& prom, int x, int y)
{
    prom.set_value(x * x + y * 8);
}

// function object / functor class
struct Div
{
    void operator()(std::promise<int>&& prom, int x, int y)const
    {
        prom.set_value(x/y);
    }
};

int main(int argc, char const *argv[])
{
    int x {90}, y{15};  

    std::promise<int> sum_square_prom;
    std::promise<int> div_prom;
    std::future<int> ftr_sum_square = sum_square_prom.get_future();
    std::future<int> ftr_div = div_prom.get_future();

    std::thread tss {sum_square, std::move(sum_square_prom), x, y};
    std::thread td {Div{}, std::move(div_prom), x, y};

    std::cout << ftr_sum_square.get() << '\n';
    std::cout << ftr_div.get() << '\n';

    tss.join();
    td.join();
    return 0;
}
