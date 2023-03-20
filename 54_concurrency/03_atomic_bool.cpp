#include <iostream>
#include <atomic>

template <typename T>
class Atomic {
public:
    operator T()const 
    {
        return value;
    }
private:
    T value;
};

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha;

    std::atomic<bool> flag_1;
    std::atomic flag_2 = false; // CTAD

    // getter
    std::cout << "flag_1 = " << flag_1 << '\n'; // calls operatorT() function
    std::cout << "flag_2 = " << flag_2 << '\n';
    // std::atomic<bool> flag3 {flag_1}; // not movable
    // flag_1 = flag_2; // not copyable
    
    // setters
    flag_1 = true;
    flag_2 = false;
    flag_1.store(false);
    flag_2.store(true);
    std::cout << "flag_1 = " << flag_1 << '\n'; // calls operatorT() function
    std::cout << "flag_2 = " << flag_2 << '\n';

    auto b = flag_1.exchange(true); // get latest value.set with param.
    std::cout << "b = " << b << '\n';
    std::cout << "flag_1 = " << flag_1 << '\n';

    // getter
    std::cout << "flag_1 = " << flag_1.load() << '\n'; // load() function can get memory order parameter. defaul sequential consistancy
    std::cout << "flag_2 = " << flag_2.load() << '\n';

    return 0;
}
