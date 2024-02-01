#include <iostream>
#include <time.h>
using namespace std;
const int n = 10;
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	int a[n];
	int k, r;
	cout << "Введите длину сдвига массива" << endl;
	cin >> k;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 200 - 100;
		cout << a[i] << " ";
	}
	cout << endl;
	for (int j = 1; j <= k; j++) {
		r = a[0];
		for (int i = 0; i <= n - 2; i++) {
			a[i] = a[i + 1];
		}
		a[n - 1] = r;
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

	return 0;
}