#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person {
protected:
	string subject;
	int mark;
public:
	Student() {
		subject = "no subject";
		mark = 0;
	}
	Student(string subject, int mark) {
		this->subject = subject;
		this->mark = mark;
	}
	Student(const Student& other) {
		this->mark = other.mark;
		this->name = other.name;
	}
	Student(string name, int age, string subject, int mark) : Person(name, age) {
		this->subject = subject;
		this->mark = mark;
	}
	void setmark(const int& mark) {
		this->mark = mark;
	}
	void setsubject(const string& subject) {
		this->subject = subject;
	}
	int getmark() {
		return this->mark;
	}
	string getsubject() {
		return this->subject;
	}
	friend ostream& operator << (ostream& os, Student& student) {
		cout << " Имя: " << student.name << endl;
		cout << " Возраст: " << student.age << endl;
		cout << " Предмет: " << student.subject << endl;
		switch (student.mark) {
		case 1: cout << " Колышник! " << endl;
		case 2: cout << " Неудовлетворительная оценка 2 " << endl; break;
		case 3: cout << " Удовлетворительная оценка 3 " << endl; break;
		case 4: cout << " Хорошая оценка 4 " << endl; break;
		case 5: cout << " Отличная оценка 5 " << endl; break;
		default:
			cout << " Такой оценки не существует! " << endl; break;
		}
		cout << endl;
		return os;
	}
	friend istream& operator >> (istream& is, Student& student) {
		cout << "Введите имя: " << endl;
		is >> student.name;
		cout << "Введите возраст: " << endl;
		is >> student.age;
		cout << "Введите оценку: " << endl;
		is >> student.mark;
		cout << "Введите предмет: " << endl;
		is >> student.subject;
		return is;
	}
	void output() override {
		cout << " Имя: " << this->name << endl;
		cout << " Возраст: " << this->age << endl;
		cout << " Оценка: " << this->mark << endl;
		cout << " Предмет: " << this->subject << endl;
		cout << endl;
	}
};