#include <iostream>
#include <thread>

void func()
{
	std::cout << "func called!\n";
    if(1)
	    throw std::runtime_error{ "runtime error exception from func\n" }; // this is another thread. So, it will call terminate function.
}

int main()
{

	try { // the exception does not be handled in this scope.
		std::thread t{ func }; 
		t.join(); // It waits for func to complete. However, it will throw an exception. And, this will not complete. Terminate
        // t.detach(); // If we use detach instead of join, the thread will work independent from main thread.

	}
	catch (const std::exception& ex) {
		std::cout << "exception caught: " << ex.what() << '\n';
	}

	//...
}