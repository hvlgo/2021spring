#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];
	
	for (int i = 0; i < n; i++)
		e[i] = new Example(i);
			
	static Example six(2333);
	for (int i; i < n; i++)
	{
		e[i]->getData();
	}
	for (int i = 0; i < n; i++)
	{
		delete e[i];
	}
	six.getData();// (6)
	
	cout << "--------create_example is over--------\n";
}

Example first(23);// (7)

int main() {

	cout << "--------main_function is ready--------\n";
	Example second(233);// (8)
		
	create_example(3);
	Example seven(23333);
	first.getData();
	second.getData();
	seven.getData();// (9)

	cout << "--------main_function is over---------\n";

	return 0;
}
