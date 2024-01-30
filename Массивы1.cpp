#include <iostream>
#include <time.h>
using namespace std;
const int n = 10;
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	int max, num;
	int k = 1;
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 200 - 100;
		cout << a[i] << " ";
	}
	cout << endl;
	max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) { max = a[i]; k = 1; num = i + 1; }
		else { if (a[i] == max) { k += 1; } }
	}
	cout << "max = " << max << " num = " << num << " k = " << k << endl;
	return 0;
}