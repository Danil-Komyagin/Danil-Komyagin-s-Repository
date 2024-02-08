#include <iostream>
using namespace std;
int fact(int x) {
	if ((x == 1) || (x == 0)) return 1;
	if (x > 1) return x * fact(x - 1);
}
double f(double x, int n) {
	if (n>=0) return pow(x, 2*n + 1) / fact(2*n+1);
}   
double summ(double x, int n) {
	if (n == 0) {
		return x;
	}
	else return summ(x, n - 1) + f(x, n);
}

int main() {
	int x, n;
	cin >> x >> n;
	cout << summ(x, n);
	return 0;
}