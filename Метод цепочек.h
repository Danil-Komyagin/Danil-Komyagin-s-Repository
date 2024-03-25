#pragma once
#include <iostream>
#include <string>
#include <ctime>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
const int M = 40;
const double A = M_PI_4;
int collision_counter = 0;
struct Node {
	string key = "";
	string value = "";
	int number;
	Node* next = nullptr;
	Node* prev = nullptr;
};
struct Hashtable {
	Node* tablemass[M];
	Hashtable() {
		for (int i = 0; i < M; i++) {
			tablemass[i] = nullptr;
		}
	}
};
double mod1(double k) {
	int zpart = static_cast<int>(k);
	return k - zpart;
}
int gethash(double k) {
	return static_cast<int>(M * mod1(k * A));
}
int gethash(string str) {
	int n = 0;
	for (int i = 0; i < str.size(); i++) {
		n += static_cast<int>(pow(str[i], 2) * M_2_SQRTPI + abs(str[i]) * M_SQRT1_2);
	}
	return gethash(abs(n));
}
bool add(Hashtable& table, string key, string value, int number) {
	Node* new_node = new Node;
	new_node->number = number;
	new_node->key = key;
	new_node->value = value;
	new_node->next = nullptr;
	new_node->prev = nullptr;
	int hash = gethash(key);
	if (table.tablemass[hash] == nullptr) {
		table.tablemass[hash] = new_node;
		return true;
	}
	else {
		Node* current_node = table.tablemass[hash];
		while (current_node->next != nullptr) {
			current_node = current_node->next;
		}
		current_node->next = new_node;
		new_node->prev = current_node;
		collision_counter++;
	}
}
bool delkey(Hashtable& table, string key) {
	int hash = gethash(key);
	Node* current_node = table.tablemass[hash];
	while (current_node != nullptr) {
		if (current_node->key == key) {
			if (current_node->prev != nullptr) {
				current_node->prev->next = current_node->next;
			}
			else {
				table.tablemass[hash] = current_node->next;
			}
			if (current_node->next != nullptr) {
				current_node->next->prev = current_node->prev;
			}
			delete current_node;
			return true;
		}
		current_node = current_node->next;
	}
	return false;
}
void print(Hashtable& table) {
	for (int i = 0; i < M; i++) {
		Node* current_node = table.tablemass[i];
		cout << endl << "������ �" << i + 1 << endl;
		int k = 1;
		while (current_node != nullptr) {
			cout << k << "." << "[" << current_node->value << " " << current_node->key << " " << current_node->number << " ] " << endl;
			current_node = current_node->next;
			k += 1;
		}
		cout << endl;
	}
}
string fio() {
	static int a = 0;
	string names[] = { "������� ������� �����������", "������ ������ ���������", "��������� ������ ����������", "�������� ������� ���������", "����� ����� �������",
"�������� ������ ��������������", "����������� ������� ��������", "������� ������� ��������", "�������� ��� ��������", "��������� ϸ�� �����������", "������ ������� ����������", "����� ����� ����������",
"������� ����� ����������", "�������� ����� ���������", "��������� �������� ���������", "������� ������� ����������", "������ ������� ����������", "������ ����� ����������", "������� �������� ��������",
"�������� �������� ����������", "������� ������ ����������", "������ ����� ����������", "����� ����� ��������", "��������� �������� ��������", "�������� ����� ���������", "������� �������� ���������",
"����� ϸ�� ���������", "������� ��������� ��������", "C������ ������� ������������","������������ ������� ���������","������� ����� ����������", "�������� ���������� ���������", "��������� ���� �������",
"������ ���� ��������", "������� ����� ��������", "��������� ������� ���������", "������ ����� ������������","������� ������� ���������", "������ ������ ��������", "���������� ��������� �������������",
"������ ������ ���������", "�������� ��� ����������", "������� ������ ����������", "����� ���� �����", "��������� ������� ����������", "��������� ���� ���������", "������� ������ ����������", "������ ����� �������",
"����� ���� ��������", "���������� �������� ������������", "������ ��������� ��������", "������� ������ ��������", "��������� ���� ����������", "���������� ������ �����������", "������� ������� ��������",
"������� ���� ����������", "�������� ���� ����������","�������� ������ ��������","���������� ����� ��������", "C�������� ����� ���������", "������ ��� ���������", "���������� ����� ���������", "��������� ���� ����������",
"������� ��������� �������", "������� ������� ����������", "����� ������ ����������", "��������� ��������� ����������", "�������� �������� ����������", "������� ������� ���������", "������ ����� ���������",
"��������� ��������� ��������", "��������� ��������� ���������", "��������� ����� ����������", "�������� �������� �������������", "�������� ������� ��������", "������ ���� ����������", "��������� ������� �����",
"��������� ���� ����������", "�������� ����� ��������", "��������� ���� �����", "�������� ������ ����������", "����������� ��� ���������", "��������� ������ ���������", "���������� ����� ��������", "��������� ���� �������",
"������� ������ �������", "�������� �������� Ը�������", "�������� ���� �������", "������ ����� ���������", "������� ��������� ��������", "�������� �������� ����������", "��������� ��������� �������������",
"������ ������ ����������", "�������� ����� ���������", "���������� ����� ����������", "����� ������ ���������", "������� ����� ��������", "����� ������� ��������", "����� ����� ���������", "������ ������ ���������",
	};
	return names[a++];
}
string date() {
	int day = rand() % 31 + 1;
	int month = rand() % 12 + 1;
	int year = rand() % 75 + 1950;
	string ds = to_string(day);
	string ms = to_string(month);
	string ys = to_string(year);
	if (ds.size() == 1) {
		ds = '0' + ds;
	}
	if (ms.size() == 1) {
		ms = '0' + ms;
	}
	return ds + '.' + ms + '.' + ys;
}
int number() {
	return rand() % 1000000 + 600000;
}