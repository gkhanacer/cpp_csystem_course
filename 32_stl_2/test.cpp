// 1 100
// 3 hot
// 5 dog
// 3-5 hotdog
// other value

#include <iostream>

int main(int argc, char const *argv[])
{   
    static int N = 100;
    for(int i = 1; i <= N; ++i) 
    {
        std::string output;
        bool isHot = (i % 3 == 0);
        bool isDog = (i % 5 == 0);
        if (isHot || isDog) 
        {
            if (isHot) 
            {
                output += "hot";
            }

            if (isDog) 
            {
                output += "dog";
            }
        }   
        else 
        {
            output = std::to_string(i);
        }
        std::cout << output << '\n';
    }
    return 0;
}
