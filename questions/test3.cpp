#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::cout;

class Car {
public:
    // ... Person members ...
   virtual void drive() {}
};

class Taxi : public Car {
public:
    virtual void drive() {}
};

class Limo : public Car {

};

class Taxi2 : public Taxi {

};


int main(int argc, char const *argv[])
{
    Car c1;
    Taxi c2;
    Limo c3;
    Taxi2 c4;

    Car *cp = &c2;
    cout << typeid(*cp).name()  << '\n'; 

    Car *cars[4] = {&c1, &c2, &c3, &c4};
    for (auto cp: cars){
        cout << (typeid(*cp) == typeid(c2)) << '\n'; 
    }

    return 0;
}
