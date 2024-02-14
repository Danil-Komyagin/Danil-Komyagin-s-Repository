#include <iostream>
#include <time.h>
using namespace std;
template <typename Type>
void f(Type *a, int n) {
    for (int i = 0; i < n - 2; i++) {
        if ((a[i] == 0) && (a[i+2] == 0)) {
            for (int j = i + 1; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n -= 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
template <typename t>
void f2(t (*a)[10], int stroki) {
    for (int i = 0; i < 10; i+=2) {
        for (int j = 0; j < 10; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    srand(time(NULL));
    double a[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            a[i][j] = rand() % 100 - 0.12;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    f2(a, 10);
    cout << endl;
    int b[] = { 0, 43, 0, 254, 234, 23, 4, 0, 65, 35, 0, 34, 0, 8 };
    for (int i = 0; i < size(b); i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    f(b, 14);
	return 0;
}