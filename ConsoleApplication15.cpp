#include <iostream>
using namespace std;
void h(int n, int start, int end) {
	if (n == 1) {
		cout << "Перемещение 1 диска с " << start << " на " << end << endl;
	}
	else {
		int temp = 6 - start - end;
		h(n - 1, start, temp);
		cout << "Перемещение " << n << "диска с " << start << " на " << end << endl;
		h(n - 1, temp, end);
	}
}
int main() {
	setlocale(LC_ALL, "RU");
	h(3, 1, 2);
	return 0;
}
