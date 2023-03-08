#include <future>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::promise<int> prom;

    std::future<int> ftr = prom.get_future(); 


    auto val = ftr.get(); // promise wasnt set, however we called get. It blocks. So, we prefer wait_for or wait_until

    std::cout << "val = " << val;

    return 0;
}