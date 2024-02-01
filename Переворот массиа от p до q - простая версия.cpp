#include <iostream>
#include <time.h>
using namespace std;
const int n = 10;
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	int a[n];
	int p, q, r;
	cout << "Введите границы преобразования массива" << endl;
	cin >> p >> q;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 200 - 100;
		cout << a[i] << " ";
	}
	cout << endl;
	int i = p - 1;
	int j = q - 1;
	while (i < j) {
		r = a[i];
		a[i] = a[j];
		a[j] = r;
		i++;
		j--;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}