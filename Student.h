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
		cout << " ���: " << student.name << endl;
		cout << " �������: " << student.age << endl;
		cout << " �������: " << student.subject << endl;
		switch (student.mark) {
		case 1: cout << " ��������! " << endl;
		case 2: cout << " �������������������� ������ 2 " << endl; break;
		case 3: cout << " ������������������ ������ 3 " << endl; break;
		case 4: cout << " ������� ������ 4 " << endl; break;
		case 5: cout << " �������� ������ 5 " << endl; break;
		default:
			cout << " ����� ������ �� ����������! " << endl; break;
		}
		cout << endl;
		return os;
	}
	friend istream& operator >> (istream& is, Student& student) {
		cout << "������� ���: " << endl;
		is >> student.name;
		cout << "������� �������: " << endl;
		is >> student.age;
		cout << "������� ������: " << endl;
		is >> student.mark;
		cout << "������� �������: " << endl;
		is >> student.subject;
		return is;
	}
	void output() override {
		cout << " ���: " << this->name << endl;
		cout << " �������: " << this->age << endl;
		cout << " ������: " << this->mark << endl;
		cout << " �������: " << this->subject << endl;
		cout << endl;
	}
};