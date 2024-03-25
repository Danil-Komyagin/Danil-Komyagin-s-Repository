#pragma once
#include <iostream>
#include <string>
#include <ctime>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
const int M = 40;
const double A = M_PI_4;
int collision_counter = 0;
struct Node {
	string key = "";
	string value = "";
	int number;
	Node* next = nullptr;
	Node* prev = nullptr;
};
struct Hashtable {
	Node* tablemass[M];
	Hashtable() {
		for (int i = 0; i < M; i++) {
			tablemass[i] = nullptr;
		}
	}
};
double mod1(double k) {
	int zpart = static_cast<int>(k);
	return k - zpart;
}
int gethash(double k) {
	return static_cast<int>(M * mod1(k * A));
}
int gethash(string str) {
	int n = 0;
	for (int i = 0; i < str.size(); i++) {
		n += static_cast<int>(pow(str[i], 2) * M_2_SQRTPI + abs(str[i]) * M_SQRT1_2);
	}
	return gethash(abs(n));
}
bool add(Hashtable& table, string key, string value, int number) {
	Node* new_node = new Node;
	new_node->number = number;
	new_node->key = key;
	new_node->value = value;
	new_node->next = nullptr;
	new_node->prev = nullptr;
	int hash = gethash(key);
	if (table.tablemass[hash] == nullptr) {
		table.tablemass[hash] = new_node;
		return true;
	}
	else {
		Node* current_node = table.tablemass[hash];
		while (current_node->next != nullptr) {
			current_node = current_node->next;
		}
		current_node->next = new_node;
		new_node->prev = current_node;
		collision_counter++;
	}
}
bool delkey(Hashtable& table, string key) {
	int hash = gethash(key);
	Node* current_node = table.tablemass[hash];
	while (current_node != nullptr) {
		if (current_node->key == key) {
			if (current_node->prev != nullptr) {
				current_node->prev->next = current_node->next;
			}
			else {
				table.tablemass[hash] = current_node->next;
			}
			if (current_node->next != nullptr) {
				current_node->next->prev = current_node->prev;
			}
			delete current_node;
			return true;
		}
		current_node = current_node->next;
	}
	return false;
}
void print(Hashtable& table) {
	for (int i = 0; i < M; i++) {
		Node* current_node = table.tablemass[i];
		cout << endl << "Ячейка №" << i + 1 << endl;
		int k = 1;
		while (current_node != nullptr) {
			cout << k << "." << "[" << current_node->value << " " << current_node->key << " " << current_node->number << " ] " << endl;
			current_node = current_node->next;
			k += 1;
		}
		cout << endl;
	}
}
string fio() {
	static int a = 0;
	string names[] = { "Зайцева Валерия Арсентьевна", "Климов Кирилл Демидович", "Румянцева Ксения Дмитриевна", "Воронова Варвара Никитична", "Гусев Игорь Никитич",
"Логинова Ариана Константиновна", "Овсянникова Валерия Семёновна", "Кузьмин Альберт Петрович", "Воронова Ева Артёмовна", "Кудрявцев Пётр Арсентьевич", "Осипов Дмитрий Евгеньевич", "Юдина Мария Дмитриевна",
"Зверева София Максимовна", "Белякова Амира Тихоновна", "Коновалов Мирослав Артурович", "Козлова Варвара Тимофеевна", "Иванов Ярослав Михайлович", "Клюева Мария Георгиевна", "Петрова Виктория Глебовна",
"Кулешова Василиса Максимовна", "Бирюков Виктор Максимович", "Лавров Денис Максимович", "Кузин Денис Артёмович", "Медведева Василиса Глебовна", "Данилова Агата Матвеевна", "Михеева Вероника Мироновна",
"Лукин Пётр Денисович", "Власова Анастасия Адамовна", "Cеменов Николай Владимирович","Александрова Евгения Матвеевна","Миронов Мирон Тимофеевич", "Федорова Александра Ильинична", "Казанцева Алёна Юрьевна",
"Зайцев Глеб Маркович", "Петрова Ольга Ивановна", "Григорьев Алексей Романович", "Попова Мария Владимировна","Поляков Дмитрий Денисович", "Исаева Ксения Ивановна", "Покровская Маргарита Александровна",
"Агеева Ульяна Романовна", "Яковлева Ева Николаевна", "Беляева Милана Робертовна", "Ильин Артём Лукич", "Горбунова Варвара Дмитриевна", "Васильева Майя Даниловна", "Михеева Марьям Георгиевна", "Чижова Мария Львовна",
"Гусев Артём Артёмович", "Тихомирова Вероника Всеволодовна", "Ширяев Александр Игоревич", "Федотов Платон Артёмович", "Гончарова Алёна Данииловна", "Коновалова Дарина Ярославовна", "Любимов Дмитрий Артёмович",
"Горшков Артём Кириллович", "Кузнецов Егор Николаевич","Романова Малика Адамовна","Кудрявцева София Ивановна", "Cофронова Софья Даниловна", "Иванов Лев Данилович", "Андрианова Мария Антоновна", "Коновалов Иван Даниилович",
"Блохина Маргарита Львовна", "Гордеев Николай Кириллович", "Сизов Никита Алексеевич", "Мельников Александр Кириллович", "Лазарева Вероника Максимовна", "Дроздов Дмитрий Сергеевич", "Беляев Тимур Матвеевич",
"Субботина Екатерина Артёмовна", "Пономарев Станислав Матвеевич", "Ларионова Арина Михайловна", "Логинова Василиса Александровна", "Гаврилов Дмитрий Адамович", "Климов Артём Степанович", "Григорьев Тимофей Ильич",
"Соловьева Ника Максимовна", "Бородина Арина Артёмовна", "Герасимов Адам Ильич", "Коротков Матвей Максимович", "Владимирова Зоя Романовна", "Журавлева Милана Матвеевна", "Овчинников Денис Маркович", "Агафонова Анна Юрьевна",
"Калинин Михаил Львович", "Филатова Виолетта Фёдоровна", "Дружинин Илья Никитич", "Седова Мария Макаровна", "Макаров Александр Олегович", "Федорова Ярослава Михайловна", "Воробьева Екатерина Александровна",
"Власов Никита Николаевич", "Балашова Алиса Мироновна", "Кондратова Арина Германовна", "Фомин Андрей Сергеевич", "Леонова Софья Егоровна", "Зотов Дмитрий Егорович", "Белов Борис Тимурович", "Фокина Оливия Демидовна",
	};
	return names[a++];
}
string date() {
	int day = rand() % 31 + 1;
	int month = rand() % 12 + 1;
	int year = rand() % 75 + 1950;
	string ds = to_string(day);
	string ms = to_string(month);
	string ys = to_string(year);
	if (ds.size() == 1) {
		ds = '0' + ds;
	}
	if (ms.size() == 1) {
		ms = '0' + ms;
	}
	return ds + '.' + ms + '.' + ys;
}
int number() {
	return rand() % 1000000 + 600000;
}