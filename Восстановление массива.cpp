#include <iostream>
#include <time.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	const int m = 4;
	const int n = 5;
	int a[m][n];
	int a2[m][n];
	int b[m*n];
	int s = 10;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) { //Выводим двумерный массив
			a[i][j] = s;
			cout << a[i][j] << " ";
			s += 1;
		}
		cout << endl;
	}
	cout << endl;
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {  // В одномерный массив помещаем строки двумерного
			b[c] = a[i][j];
			c += 1;
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {  // В одномерный массив помещаем столбцы двумерного
			b[c] = a[i][j];
			c += 1;
		}
	}
	for (int i = 0; i < c; i++) {
		cout << b[i] << " ";
	}
	for (int i = 0; i < n; i++) {
		for (int j = m * n; j < 2 * m * n; j += m) {
			if (b[i] == b[j]) {
				for (int c = 0; c < m; c++) {
					a2[c][i] = b[j];
					j++;
				}
			}
		}
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) { //Выводим двумерный массив
			cout << a2[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}