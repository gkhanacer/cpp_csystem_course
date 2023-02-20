#include <thread>
#include <iostream>



void foo() {}

int main(int argc, char const *argv[])
{
    std::thread tx {foo};
    tx.join(); // it will wait until complete task. Then tx will be not joinable.
    try
    {
        tx.join(); // not joinable. error. InvalidArgument
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
 
 
    return 0;
}
