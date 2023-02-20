#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <exception>

using std::cout;
using std::exception;
using std::string;

void func4() {
    std::runtime_error e("func4 ");
    throw 10;
}

void func3() {
    cout << " func3 ";
    func4();
}

void func2() {
    try {
        func3();
    }
    catch(const exception& e) {
        cout << "10 ";
        throw 2;
    }
    catch(...) {
        cout << "5 ";
        throw std::runtime_error("two ");
    }
}

void func1() {
    func2();
    cout << " func1 ";
    throw 1;
}


int main(int argc, char const *argv[])
{
    try
    {
        func1();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}

