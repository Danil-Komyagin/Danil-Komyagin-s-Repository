#include <iostream>
#include "Метод цепочек.h"
#include "Линейное пробирование.h"
using namespace std;

int main() {
	system("chcp 1251 > Null");
	srand(time(NULL));
	/*
	Hashtable1 table1;
	for (int i = 0; i < 40; i++) {
		add1(table1, date(), fio(), number());
	}
	cout << "Создана hash - таблица: Число коллизий:" << collision_counter << endl;
	print(table1);
	cout << "Введите дату рождения человека, которого хотите удалить: ";
	string datedel;
	cin >> datedel;
	if (del1(table1, datedel)) {
		cout << "Человек с датой рождения " << datedel << " успешно удалён" << endl;
	}
	else {
		cout << "Такого человека на обнаружено...";
	}
	print(table1);
	*/
	Hashtable table;
	for (int i = 0; i < 100; i++) {
		add(table, date(), fio(), number());
	}
	cout << "Создана hash - таблица: Число коллизий:" << collision_counter << endl;
	print(table);
	cout << "Введите дату рождения человека, которого хотите удалить: ";
	string datedel;
	cin >> datedel;
	if (delkey(table, datedel)) {
		cout << "Человек с датой рождения " << datedel << " успешно удалён" << endl;
	}
	else {
		cout << "Такого человека на обнаружено...";
	}
	print(table);
	return 0;
}
