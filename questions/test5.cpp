#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

class Car {
public:
    // ... Person members ...
    ~Car() {
        cout << "Car dtor\n";
    }
};

class Taxi : public Car {
public:
    ~Taxi() {
        cout << "Taxi dtor\n";
    }
};



int main(int argc, char const *argv[])
{
    Car* c2 = new Taxi;

    delete c2;

    return 0;
}
