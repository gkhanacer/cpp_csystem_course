#include <iostream>
#include <ctime>
#include <cstdlib>

class Animal
{
public:
    virtual void eat() // Doğru
    // void eat()  // Yanlış 
    {
        std::cout << "animal is eating.\n";
    }
};

class Cat : public Animal
{
public:
    void eat()
     {
        std::cout << "cat is eating.\n";
    }
};

class Dog : public Animal
{
public:
    void eat()
    {
        std::cout << "Dog is eating.\n";
    }
};

class Tiger : public Animal
{
public:
    void eat()
    {
        std::cout << "Tiger is eating.\n";
    }
};


// Burada dynamic binding (late binding) var.
// Hangi fonsiyonun çağrıldığı Runtime'da belli oluyor.
// Function overloading static binding (early binding). Compile time'da hangi fonksiyonun çalıştığını bilir.
void animal_game(Animal& ra)
{
    ra.eat();
}

Animal * createAnimal() 
{
    using namespace std;

    switch (rand() % 3)
    {
    case 0: cout << "case cat\n"; return new Cat;
    case 1: cout << "case dog\n"; return new Dog;
    case 2: cout << "case tiger\n"; return new Tiger;
    }
}
int main(int argc, char const *argv[])
{
    Cat mycat;
    Dog mydog;
    Tiger mytiger;

    animal_game(mycat);
    animal_game(mydog);
    animal_game(mytiger);

    srand(static_cast<unsigned>(time(nullptr)));

    for (size_t i = 0; i < 100; i++)
    {
        animal_game(*createAnimal());
        getchar();
    }
    

    return 0;
}
