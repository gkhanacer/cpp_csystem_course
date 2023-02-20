#include <string>
#include <iostream>

void print(const std::string &str)
{
	std::cout << "[" << str << "] [" << str.size() << "/" << str.capacity() << "]\n";
}


int main(int argc, char const *argv[])
{
    std::string s1; // default ctor
    print(s1);

    std::string s2 {"gokhan acer"}; // c-string ctor
    print(s2);

    std::string s3 {s2}; //copy ctor
    print(s3);

    std::string s4 { std::move(s3) }; //move ctor
    print(s4);

    return 0;
}
