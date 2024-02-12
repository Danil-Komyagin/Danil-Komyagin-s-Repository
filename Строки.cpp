#include <iostream>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	system("chcp, 1251");
	system("cls");
	string str;
	getline(cin, str);
	char mass[] = "0123456789 qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	int a = 0;    // Индекс первого элемента слова
	int i = 0;	  // Переменная, использующаяся для перебора символов в слове
	bool f = true;
	while (str[i] != '\0') {  
		for (int j = 0; (j < size(mass) - 1) && (f == true); j++) {  // Проверка текущего символа строки
			if (str[i] == mass[j] || str[i] == ' ') f = false;
		}
		if (f == true) {				//Если символ не найден в массиве, удаляем слово до пробела
			while (str[a] != ' ') {
				str.erase(a, 1);
			}
			str.erase(a, 1); // Удаляем и пробел тоже
			i = a;			// Индекс текущего символа равен индексу первого символа нового слова
		}
		else i++;           // Если символ найден среди разрешённых, переходим к следующему элементу
		if (str[i] == ' ') {
			a = i + 1;
		}
		f = true;
	}
	cout << str;
	cout << size(mass);
	return 0;
}