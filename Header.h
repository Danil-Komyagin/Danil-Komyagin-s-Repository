#pragma once
#include <iostream>
#include <string>
using namespace std;
void createtable(string& pattern, int d[]) {
	int len = pattern.length();
	for (int i = 0; i < 256; i++) {
		d[i] = len;
	}
	for (int i = 0; i < len - 1; i++) {
		d[(unsigned char)pattern[i]] = len - i - 1;
	}
}
void boyermoore(string& text, string& pattern) {
	int patlen = pattern.length();
	int textlen = text.length();
	int d[256];
	createtable(pattern, d);
	bool f = 0;
	for (int i = patlen - 1; i < textlen; i += d[(unsigned char)text[i]]) {
		int k = 0;
		while (k < patlen && (pattern[patlen - 1 - k] == text[i - k])) {
			k++;
		}
		if (k == patlen) {
			cout << "(БМ)Образ найден по номеру: " << i - patlen + 2 << endl;
			f = 1;
		}
	}
	if (!f) { cout << "Образ не найден в строке " << endl; }
}
void pref(string pattern, int* d) {
	d[0] = 0;
	int j = 0;
	int i = 1;
	while (i < pattern.length()) {
		if (pattern[i] == pattern[j]) {
			d[i] = j + 1;
			i++;
			j++;
		}
		else {
			if (j == 0) {
				d[i] = 0;
				i++;
			}
			else j = d[j - 1];
		}
	}
}
void kmp(string& text, string& pattern) {
	int* d = new int[pattern.length()];
	pref(pattern, d);
	int i = 0;
	int j = 0;
	bool f = 0;
	while (i < text.length()) {
		if (pattern[j] == text[i]) {
			i++;
			j++;
		}
		if (j == pattern.length()) {
			cout << "(КМП)Образ найден по номеру: " << i - pattern.length() + 1 << endl;
			j = d[j - 1];
			f = 1;
		}
		else if (i < text.length() && pattern[j] != text[i]) {
			if (j != 0) { j = d[j - 1]; }
			else i++;
		}
	}
	if (f == false) { cout << "Образ в строке не найден" << endl; }
}
void pramoi(string& str, string& key) {
	int a = str.length();
	int b = key.length();
	bool f2 = false;
	for (int i = 0; i < a - b + 1; i++) {
		if (str[i] == key[0]) {
			bool f = true;
			for (int j = 0; (j < b) && f; j++) {
				if (str[i] == key[j]) { i++; }
				else f = false;
			}
			if (f == true) {
				cout << "(ПР)Образ найден по номеру: " << i - b + 1 << endl;
				f2 = true;
			}
		}
	}
	if (!f2) cout << "Образ в строке не найден" << endl;
}