#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, d, x1, x2;
    cin >> a >> b >> c;
    if (a != 0)
        if (b!=0)
            if (c != 0) {
                d = b * b - 4 * a * c;
                if (d != 0) {
                    x1 = ((-1 * b + sqrt(d)) / (2 * a)); x2 = ((-1 * b - sqrt(d)) / (2 * a)); cout << x1 << " " << x2 << endl;
                }
                else cout << "d<0";
            }
            else { x1 = 0; x2 = (-1 * b / a); cout << x1 << " " << x2; }
        else {
            if (c == 0) { x1 = 0; x2 = 0; cout << 0 << " " << 0; }
            if (c != 0) { int m = -1 * c - a; x1 = sqrt(m); x2 = -1 * sqrt(m); cout << x1 << " " << x2; }   
        }
    else { x1 = -1 * c / b; cout << x1; }

    return 0;
}
