#include <iostream>
#include <string>
using namespace std;

struct Node {
	char data;
	Node* next = nullptr;
	Node* prev = nullptr;
};
struct List {
	Node* head_node = nullptr;
};

int size_of_list(List& list);
void pushBack(List& list, char& data);
void push_on_position(List& list, char& data, const int& position);
void del_on_position(List& list, const int& position);
void print(List& list);

int main() {
	setlocale(LC_ALL, "RU");
	List list;
	string a, key;
	cout << "Cформируйте список: ";
	cin >> a;
	for (int i = 0; i < size(a); i++) {
		push_on_position(list, a[i], i + 1);
	}
	print(list);
	cout << endl << "Введите ключ для удаления: ";
	cin >> key;
	Node* current_node = list.head_node;
	int k = 1;
	while (current_node != nullptr) {
		if (current_node->data == key[0]) {
			if (current_node->prev == nullptr) {
				del_on_position(list, 0);
				current_node = list.head_node;
				k -= 1;
			}
			else {
				current_node = current_node->prev;
				del_on_position(list, k);
				k -= 1;
				current_node = current_node->next;
			}
		}
		else current_node = current_node->next;
		k += 1;
	}
	print(list);
	int num, kol;
	cout << "Задайте номер, перед которым нужно добавить элементы: ";
	cin >> num;
	cout << "Задайте количество добавляемых элементов: ";
	cin >> kol;
	for (int i = 1; i <= kol; i++) {
		cout << "Введите элемент № " << i << ": ";
		string add;
		cin >> add;
		push_on_position(list, add[0], num);
	}
	print(list);
	return 0;
}

void pushBack(List& list, char& data) {
	Node* new_node = new Node;
	new_node->data = data;
	if (list.head_node == nullptr) {
		list.head_node = new_node;
		return;
	}
	Node* current_node = list.head_node;
	while (current_node->next != nullptr) {
		current_node = current_node->next;
	}
	new_node->prev = current_node;
	current_node->next = new_node;
}
void push_on_position(List& list, char& data, const int& position) {
	Node* new_node = new Node;
	new_node->data = data;
	if (list.head_node == nullptr) {
		list.head_node = new_node;
		return;
	}
	if (position > size_of_list(list)) {
		pushBack(list, data);
		return;
	}
	if ((position == 0) || (position == 1)) {
		new_node->prev = nullptr;
		new_node->next = list.head_node;
		list.head_node = new_node;
		return;
	}
	Node* current_node = list.head_node;
	for (int i = 1; i < position; i++) {
		current_node = current_node->next;
	}
	current_node->prev->next = new_node;
	new_node->prev = current_node->prev;
	new_node->next = current_node;
	current_node->prev = new_node;
}
void del_on_position(List& list, const int& position) {
	Node* current_node = new Node;
	if ((position == 0) || (position == 1)) {
		current_node = list.head_node;
		list.head_node = list.head_node->next;
		delete current_node;
		return;
	}
	current_node = list.head_node;
	if (position >= size_of_list(list)) {
		while (current_node->next != nullptr) {
			current_node = current_node->next;
		}
		current_node->prev->next = nullptr;
		delete current_node;
		return;
	}
	for (int i = 1; i != position; i++) {
		current_node = current_node->next;
	}
	current_node->prev->next = current_node->next;
	current_node->next->prev = current_node->prev;
	delete current_node;
}
int size_of_list(List& list) {
	if (list.head_node == nullptr) {
		return 0;
	}
	Node* current_node = list.head_node;
	int s = 0;
	while (current_node != nullptr) {
		s += 1;
		current_node = current_node->next;
	}
	return s;
}

void print(List& list) {
	if (list.head_node == nullptr) {
		cout << "Empty list" << endl;
	}
	else {
		Node* current_node = list.head_node;
		while (current_node != nullptr) {
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
		cout << endl;
	}
}