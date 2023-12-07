#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int max, sovp, num, n, a;
    int i = 2;
    cout << "Введите количество элементов" << endl;
    cin >> n;
    cout << "Вводите элементы последовательности" << endl;
    cin >> a;
    max = a;
    sovp = 1;
    num = 1;
    while (i <= n) {
        cin >> a;
        if (a > max) { max = a; num = i; sovp = 1; }
        else { if (a == max){ sovp += 1; } }
        i += 1;
    }
    cout << "максимальное = " << max << endl;
    cout << "количество совпадений = " << sovp << endl;
    cout << "номер максимального = " << num << endl;
    return 0;
}