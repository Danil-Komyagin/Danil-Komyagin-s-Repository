#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int n;
	cout << "Введите n - количество звёзд в основании" << endl;
	cin >> n;
	while ((n % 2 == 0) || (n < 3)) { cout << "Введите ещё раз" << endl; cin >> n;  }
	int p = (n - 1) / 2;
	int z = 1;
	for (int i = 1; i <= (n + 1) / 2; i++) {
		for (int j = 1; j <= p; j++) {
			cout <<" ";
		}
		p -= 1;
		for (int j = 1; j <= z; j++) {
			cout << "*";
		}
		z += 2;
		cout << endl;
	}
	return 0;
}