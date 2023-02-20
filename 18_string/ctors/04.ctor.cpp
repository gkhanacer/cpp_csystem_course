#include <string>
#include <iostream>

void print(const std::string& str)
{
	std::cout << "[" << str << "] [" << str.size() << "/" << str.capacity() << "]\n";
}

int main()
{
	char buffer[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };

	std::string s1(buffer); //c-string ctor
	print(s1);

    std::string s2(buffer, buffer + 10);  // range ctor
    print(s2);

    std::string s3(buffer + 10, buffer + 15); // range ctor
    print(s3);

    std::string s4(buffer, 10); // data ctor. ilk adresten basla n tane eleman al
    print(s4);

    std::string s5(buffer + 35, 5);
    print(s5);

    std::string s6(buffer, 500); // ub
    print(s6);
}