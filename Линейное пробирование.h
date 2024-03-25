#pragma once
#include "Метод цепочек.h"
#include <string>
#include <iostream>
using namespace std;

struct Element {
	string key = "";
	string value = "";
	int number;
};
struct Hashtable1 {
	Element *massel = new Element[M];
	Hashtable1() {
		for (int i = 0; i < M; i++) {
			massel[i].key = "";
			massel[i].number = 0;
			massel[i].value = "";
		}
	}
};
bool add1(Hashtable1& table, string key, string value, int number) {
	int hash = gethash(key);
	if (table.massel[hash].key == "") {
		table.massel[hash].key = key;
		table.massel[hash].number = number;
		table.massel[hash].value = value;
		return true;
	}
	else {
		for (int i = hash + 1; i < (hash + M); i++) {
			if (table.massel[i % M].key == "") {
				table.massel[i % M].key = key;
				table.massel[i % M].number = number;
				table.massel[i % M].value = value;
				collision_counter++;
				return true;
			}
		}
	}
	cout << "Таблица переполнена..." << endl;
	return false;
}
bool del1(Hashtable1& table, string key) {
	int hash = gethash(key);
	if (table.massel[hash].key == key) {
		table.massel[hash].key = "";
		table.massel[hash].number = 0;
		table.massel[hash].value = "";
		return true;
	}
	else {
		for (int i = hash + 1; i < (hash + M); i++) {
			if (table.massel[i].key == key) {
				table.massel[hash].key = "";
				table.massel[hash].number = 0;
				table.massel[hash].value = "";
				return true;
			}
		}
	}
	return false;
}
void print(Hashtable1& table) {
	for (int i = 0; i < M; i++) {
		cout << endl << "Ячейка №" << i + 1 << endl;
		cout << "[" << table.massel[i].value << " " << table.massel[i].key << " " << table.massel[i].number << " ] " << endl;
	}
	cout << endl;
}