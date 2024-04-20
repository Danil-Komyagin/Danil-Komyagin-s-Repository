#include <iostream>
#include <cmath>
using namespace std;
class Progression {
private:
	double first;
	int second;
	double st(double a, double b) {
		int proizv = a;
		for (int i = 1; i < b; i++) {
			proizv *= a;
		}
		return proizv;
	}
public:
	Progression(int first, int second) {
		this->first = first;
		this->second = second;
	}
	double element(int j) {
		return first * st(second, j);
	}
};
int main() {
	system("chcp 1251 > Null");
	int f = 0, s = 0, el = 0;
	cout << "Введите элементы first и second: ";
	cin >> f >> s;
	Progression prog1(f, s);
	cout << "Введите номер вычисляемого элемента: ";
	cin >> el;
	cout << prog1.element(el);
	return 0;
}