#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "RU");
    int x, n;
    int s = 0;
    int i = 1;
    int u = 1;

    cout << "Введите х и количество элементов n" << endl;
    cin >> x >> n;

    while (i <= n) {
        s = s + u;
        u = u * x / i;
        i += 1;
    }
    cout << s;
    return 0;
}