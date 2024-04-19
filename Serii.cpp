#include <iostream>
using namespace std;
int bin(int* a, int n, int key) {
	int left = 0;
	int right = n - 1;
	int mid;
	bool f = true;
	while (left<=right) {
		mid = (left + right) / 2;
		if (a[mid] < key) {
			left = mid + 1;
		}
		if (a[mid] > key) {
			right = mid - 1;
		}
		if (a[mid] == key) {
			return mid + 1;
		}
	}
	return -1;
}
int lin(int* a, int n, int key) {
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			return i + 1;
		}
	}
	return -1;
}
int middle(int* a, int l, int r, int key) {
	return l + (key - a[l]) * (r - l) / (a[r] - a[l]);
}
int interpol(int* a, int l, int r, int key) {
	int mid = middle(a, l, r, key);
	while (a[mid] != key) {
		if (a[mid] < key) {
			mid = middle(a, mid + 1, r, key);
		}
		else mid = middle(a, l, mid - 1, key);
	}
	return mid + 1;
}
int main() {
	system("chcp 1251>Null");
	int mass[] = { 3, 5, 6, 32, 45, 2343, 546765, 4389537 };
	cout << "Ваш массив:";
	for (int i = 0; i < 8; i++) { cout << mass[i] << " "; }
	cout << "Элемент для поиска = 6" << endl;
	cout << endl << "Интерполяционный поиск: ваш элемент под номером: " << interpol(mass, 0, size(mass), 6) << endl;
	cout << "Линейный поиск: ваш элемент под номером: " << lin(mass, size(mass), 6) << endl;
	cout << "Бинарный поиск: ваш элемент под номером: " << bin(mass, size(mass), 6) << endl;
	return 0;
}