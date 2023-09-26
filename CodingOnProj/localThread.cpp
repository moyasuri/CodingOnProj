#include<iostream>
#include<thread>

using namespace std;

int globalNum = 0;
thread_local int tlNum = 0;

// test2
void fn()
{
	int fnNum = 2;
	cout << "global Num" << globalNum << endl;
	cout << "thLocal Num" << tlNum << endl;

	globalNum++;
	tlNum++;

}
int main()
{
	using namespace chrono_literals;

	int mainNum = 1;
	thread t1(fn);
	this_thread::sleep_for(1s);
	thread t2(fn);

	t1.join();
	t2.join();
}
