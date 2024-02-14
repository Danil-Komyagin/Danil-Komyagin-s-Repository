#include <iostream>
#include <math.h>
using namespace std;
double storona(double x1, double y1, double x2, double y2) {
    return sqrt((pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2)));
} //Функция storona вычисляет длину линии по указанным координатам точек
  // Порядок задания координат в функцию не нарушается!
double square(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = storona(x1, y1, x2, y2);//Функция вычисляет площадь треугольника по указанным координатам,
    double b = storona(x2, y2, x3, y3);//Вычисляя стороны треугольника с помощью функции storona и получая
    double c = storona(x3, y3, x1, y1);//Площадь при помощи формулы Герона. Возвращает значение площади.
    double p = (a + b + c) / 2;        //Порядок задания координат треугольника в функцию не нарушается!
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
double square1(int kol, ...) {     //Функция для вычисления площади треугольника с максимальной диагональю
    int* p = &kol + 2;          
    double *a = new double[kol];   //Создаётся массив, в котором будут храниться считанные координаты
    for (int i = 0; i < kol; i++) {//Координаты заносятся в массив поочерёдно, с помощью цикла for.
        a[i] = *p;
        p += 2;
    }
    cout << "Координаты точек: ";
    for (int i = 0; i < kol; i++) {
        cout<<a[i]<<" ";
    }
    cout << endl;
    double maxlen = 0; // Переменная, хранящая длину самой длинной диагонали
    double x11, y11, x22, y22, verx, very; //Координаты длинной диагонали и найденной вершины       
    for (int i = 0; i < kol - 5; i +=2 ) {
        double x1t = a[i];     //Диагональ берётся так, чтобы между вершинами,
        double y1t = a[i + 1]; //Из которых она выходит, по кратчайшему пути
        double x2t = a[i+4];   //Находилась только одна вершина, чтобы было
        double y2t = a[i + 5]; //Возможно построить из этих вершин треугольник.
        if (storona(x1t, y1t, x2t, y2t) > maxlen) {
            maxlen = storona(x1t, y1t, x2t, y2t);
            x11 = x1t;
            y11 = y1t;
            x22 = x2t;
            y22 = y2t;
            verx = a[i + 2];
            very = a[i + 3];
        }
    }
    if (storona(a[kol - 4], a[kol - 3], a[0], a[1]) > maxlen) {
        maxlen = storona(a[kol - 4], a[kol - 3], a[0], a[1]);
        x11 = a[kol - 4];
        y11 = a[kol - 3];
        x22 = a[0];
        y22 = a[1];
        verx = a[kol-2];
        very = a[kol-1];
    }
    if (storona(a[kol - 2], a[kol - 1], a[2], a[3]) > maxlen) {
        maxlen = storona(a[kol - 2], a[kol - 1], a[2], a[3]);
        x11 = a[kol - 2];
        y11 = a[kol - 1];
        x22 = a[2];
        y22 = a[3];
        verx = a[0];
        very = a[1];
    }
    double s = square(x11, y11, x22, y22, verx, very);
    cout << "Максимальная длина диагонали: " << maxlen << endl;
    cout <<"Координаты диагонали: " << x11 << " " << y11 << " " << x22 << " " << y22 << endl;
    cout <<"Координаты вершины(в зависимости от диагоналей): " << verx << " " << very << endl;
    cout <<"Площадь треугольника: " << s;
    return s;
}
int main() {
    setlocale(LC_ALL, "RU");
    square1(8, 1, -1, 3, 2, -4, 3, -6, -3);
    return 0;
}
