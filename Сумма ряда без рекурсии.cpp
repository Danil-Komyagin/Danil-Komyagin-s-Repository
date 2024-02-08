#include <iostream>
using namespace std;
int main() {
	int x, n;
	cin >> x >> n;
	double s = 0;
	for (int i = 0; i <= n; i+=1) {
		int fact = 1;
		for (int j = 1; j <= 2 * i + 1; j++) {
			fact *= j;
		}
		s += pow(x, 2 * i + 1) / fact;
	}
	cout << s;
	return 0;
}