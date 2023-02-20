#include <thread>
#include <iostream>


void func() {
    for (size_t i = 0; i < 100000; i++)
    {
        std::cout << '*';
    }
    
}

void foo() {
    for (size_t i = 0; i < 100000; i++)
    {
        std::cout << '?';
    }
    
}

void bar() {
    for (size_t i = 0; i < 100000; i++)
    {
        std::cout << '+';
    }
    
}

int main(int argc, char const *argv[])
{ 
    std::thread t1 {func};
    std::thread t2 {foo};
    std::thread t3 {bar};
    for (size_t i = 0; i < 100000; i++)
    {
        std::cout << '.';
    }
    t1.join(); 
    t2.join(); 
    t3.join(); 


    return 0;
}
