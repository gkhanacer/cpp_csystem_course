#include <mutex>
#include <thread>
#include <iostream>


class Nec {
public:
    void func()
    {
        std::lock_guard guard{mtx};
        std::cout << "func called\n";
        foo(); 
        std::cout << "func finished\n";
    }

    void foo()
    {
        std::lock_guard guard{mtx}; 
        std::cout << "foo called\n";
        std::cout << "foo finished\n";
    }

private:
    std::recursive_mutex mtx;
};

int main(int argc, char const *argv[])
{
    Nec nec;

    try
    {
        nec.func();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
