#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Person : public Object {
protected:
	string name;
	int age;
public:
	Person() {
		this->name = "noname";
		this->age = 0;
	}
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	Person(const Person& other) {
		this->age = other.age;
		this->name = other.name;
	}
	string getname() {
		return this->name;
	}
	int getage() {
		return this->age;
	}
	void setname(string name) {
		this->name = name;
	}
	void setage(int age) {
		this->age = age;
	}

	friend ostream& operator << (ostream& os, const Person& person) {
		cout << " Имя: " << person.name << endl;
		cout << " Возраст: " << person.age << endl;
		cout << endl;
		return os;
	}
	friend istream& operator >> (istream& is, Person& person) {
		cout << "Введите имя: " << endl;
		is >> person.name;
		cout << "Введите возраст: " << endl;
		is >> person.age;
		return is;
	}
	Person& operator = (const Person& other) {
		this->age = other.age;
		this->name = other.name;
		return *this;
	}
	void output() override {
		cout << " Имя: " << this->name << endl;
		cout << " Возраст: " << this->age << endl;
		cout << endl;
	}
};