#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
using namespace std;

int main() {
	system("chcp 1251 > Null");

	Person d("Dima", 23);
	d.output();

	Student s("Chtmistry", 2);

	s.output();

	Student a("Alex", 25, "IT", 4);

	a.output();

	return 0;
}

