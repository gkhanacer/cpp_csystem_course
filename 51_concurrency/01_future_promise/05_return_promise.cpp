#include <future>
#include <iostream>

// function can return promise objects
std::promise<int> sum_square(int x, int y)
{
    std::promise<int> prom;
    prom.set_value(x * x + y * y);
    return prom;
}

int main(int argc, char const *argv[])
{
    int x {90}, y{15};  

    std::promise<int> sum_square_prom = sum_square(x , y);
    
    std::future<int> ftr_sum_square = sum_square_prom.get_future();

    std::thread tss {sum_square, x, y};

    std::cout << ftr_sum_square.get() << '\n';

    tss.join();
    return 0;
}
