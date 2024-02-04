#include <iostream>
#include <time.h>
using namespace std;

void print(int mass[], int n) {
	for (int i = 0; i < n; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	int kol = 0;
	int n = 10;
	int *a = new int [n];
	int r = 0;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 200 - 100;  //Создаём и выводим массив случайных чисел
	}
	print(a, n);
	
	int k;
	cout << "Введите длину сдвига массива влево по кольцу, k раз" << endl;
	cin >> k;

	for (int j = 1; j <= k; j++) {
		int r = a[0];
		for (int i = 0; i < n - 1; i++) {
			a[i] = a[i + 1];
		}
		a[n - 1] = r;
	}
	print(a, n);


	for (int i = 1; i < n; i++) {
		for (int j = i; (j > 0) && (a[j - 1] < a[j]); j--) {
			int r = a[j];
			a[j] = a[j - 1];
			a[j - 1] = r;
		}
	}
	print(a, n);
	cout << "Отсортированный массив" << endl;

	for (int i = 0; i < n; i++) {				//Убираем нечётные элементы и сдвигаем всё влево
		while (abs(a[i]) % 2 == 1) {
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
			kol += 1;
		}
	}
	n -= kol;
	print(a, n);
	return 0;
}