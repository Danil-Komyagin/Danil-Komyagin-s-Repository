#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main() {
	system("chcp 1251 > Null");
	string text, key;
	cout << "Введите строку для поиска: " << endl;
	getline(cin, text);
	cout << "Введите образ для поиска: " << endl;
	getline(cin, key);
	pramoi(text, key);
	kmp(text, key);
	boyermoore(text, key);
	return 0;
}
