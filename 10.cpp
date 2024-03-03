#include <iostream>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	cout << "Введите длину массива и номер строки для добавления" << endl;
	int kol, num;
	cin >> kol >> num;
	string copy;
	string* mass = new string[kol];
	string* mass2 = new string[kol + 1];
	for (int i = 0; i < kol; i++){
		cin >> *(mass + i);
		if (i == num - 1) copy = *(mass + i);
	}
	for (int i = 0; i < kol; i++) {
		*(mass2 + i) = *(mass + i);
	}
	*(mass2 + kol) = copy;
	for (int i = 0; i <= kol; i++) {
		cout << *(mass2 + i) << endl;
	}
	delete[] mass;
	delete[] mass2;
	return 0;
}


