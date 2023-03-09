#include <future>
#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    // std::packaged_task<double(double, double)> ptask([](double a, double b)
    // {
    //     return std::pow(a, b) + std::pow(b, a);
    // });

    // A wrapper which can give a future object.
    std::packaged_task ptask([](double a, double b)
    {
        return std::pow(a, b) + std::pow(b, a);
    });

    auto result = ptask.get_future();

    ptask(1.2, 3.4);

    std::cout << "result : " << result.get() << std::endl;
    return 0;
}
