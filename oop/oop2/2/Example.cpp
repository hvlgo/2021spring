#include <iostream>
#include "Example.h"

using namespace std;

	int Example::count = 0;// (2)

Example::Example(int data) {
	this->data = data;
	count++;
	number = count;
	cout << "Example #" << count << " is created" << endl;// (3)
}

void Example::getData() {
	cout << "The data of Example #" << number << " is " << data << endl;// (4)
}

Example::~Example() {
	cout << "Example #" << number << " is destroyed" << endl;// (5)
}