#include<string>
#include<iostream>

void print(const std::string& str)
{
	std::cout << "[" << str << "] [" << str.size() << "/" << str.capacity() << "]\n";
}


int main(int argc, char const *argv[])
{
    std::string s{"gokhan acer"};
    s[4] = 's';
    print(s);

    std::string n{"necati"};
    n.replace(2, 3, "MURAT");
    print(n);

    int x = 123232;
    auto ss = std::to_string(x);
    print(ss);

    std::string sss{"asf"};
    auto ass = sss.substr(1, 1);
    print(ass);

    return 0;
}
