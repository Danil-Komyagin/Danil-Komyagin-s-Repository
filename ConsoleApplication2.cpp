#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    string bigmass[100];
    ifstream FileA("fa.txt");
    ofstream FileB("fb.txt");
    int m = 0;
    while (FileA.eof()==0) {
        int j = 0;
        string str;
        getline(FileA, str);
        string mass[30];  // Локальный массив для каждой строки
        for (int i = 0; i < size(str); i++) {
            if ((str[i] != ' ' )) {  //Каждое слово добавляем в массив
                mass[j] += str[i];
            }
            else { j++; }
        }
        for (int i = 0; i <= j; i++) { //Выводим малый массив и добавляем
            cout << mass[i] << " "; // элементы в большой, чтобы затем найти
            bigmass[m] = mass[i];
            m++;                    // максимальный
        }
        cout << endl;
        bool f = false;
        for (int i = 0; i <= j - 1; i++) {   //Проверяем малый массив на повторы 
            for (int g = i + 1; g <= j; g++) { 
                if ((mass[i] == mass[g]) && (mass[i] != " ")) f = true;
            }
        }
        if (f == true){ //Если есть повтор, добавляем строку в файл
            FileB << str << endl;
        }
    }
    FileA.close();
    FileB.close();
    int maxkol = 0;
    int num = 0;
    for (int i = 0; i <= m; i++) {
        int kol = 0;
        for (int j = 0; j < size(bigmass[i]); j++) {
            if (isdigit((bigmass[i])[j])) { kol += 1; }
        }
        if (kol > maxkol) { maxkol = kol; num = i + 1; }  
    }
    cout << num;
    return 0;
}







