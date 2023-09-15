#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;


// 값 핸들링
// std::async,
// 혹은 argument
// future / promise

int fn()
{
	throw std::runtime_error("error");
}

int main()
{
	
	try
	{
		thread t1(fn);
		t1.join();
	}
	catch (...)
	{
		cout << "catched" << endl;

	}

	
}