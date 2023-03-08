#include <iostream>
#include <thread>
#include <stdexcept>

std::exception_ptr exptr = nullptr;

void func(int x)
{
	std::cout << "func(int x) called! x = " << x << "\n";
    try
    {
        if (x % 2 == 0)
	        throw std::invalid_argument{ "invalid argument was passed\n" }; 
    }
    catch(const std::exception& e)
    {
        exptr = std::current_exception();
    }
    
    std::cout << "func(int x) finished." << "\n";
}

int main()
{
    std::thread t{ func, 10}; 
    t.join(); 
	try { 
        if (exptr)
            std::rethrow_exception(exptr);
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}

	//...
}