#include <iostream>
#include <atomic>

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha;

    std::atomic<int> a = 10;
    std::cout << "a = " << a << '\n';
    
    int temp = a.load();
    /// other threads can change a at this stage.
    a.store(temp * 60);

    std::cout << "a = " << a << '\n';
    return 0;
}
