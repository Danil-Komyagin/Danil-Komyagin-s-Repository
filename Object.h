#pragma once
#include <iostream>
using namespace std;

class Object {
public:
	Object() {};
	virtual ~Object() {
		cout << " virtual object destructor " << endl;
	}
	virtual void output() = 0;
};