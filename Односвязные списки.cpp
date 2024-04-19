#include <iostream>
#include <string>
using namespace std;

struct Node {
	char data;
	Node* next = nullptr;
};
struct List {
	Node* head_node = nullptr;
};

int size_list(List& list);
void pushBack(List& list, char& data);
void push_to_the_position(List& list, char& data, const int& position);
void del_on_position(List& list, const int& position);
void print(List& list);

int main() {
	setlocale(LC_ALL, "RU");
	List list;
	string a, key;
	cout << "Сформируйте однонаправленный список: ";
	cin >> a;
	for (int i = 0; i < size(a); i++) {
		pushBack(list, a[i]);
	}
	print(list);
	cout << "Введите ключ для удаления: ";
	cin >> key;
	Node* current_node = list.head_node;
	int k = 1;
	while (current_node != nullptr) {
		if (current_node->data == key[0]) {
			Node* tmp = current_node->next;
			del_on_position(list, k);
			k -= 1;
			current_node = tmp;
		}
		else current_node = current_node->next;
		k += 1;
	}
	print(list);
	int num, kol;
	cout << "Введите номер, перед которым будут ставиться элементы: ";
	cin >> num;
	cout << "Введите количество вставляемых элементов: ";
	cin >> kol;
	for (int i = 0; i < kol; i++) {
		string n;
		cout << "Введите элемент № " << i + 1 << ": ";
		cin >> n;
		push_to_the_position(list, n[0], num);
	}
	print(list);
	return 0;
}

int size_list(List& list) {
	Node* current_node = list.head_node;
	int k = 0;
	while (current_node != nullptr) {
		k += 1;
		current_node = current_node->next;
	}
	return k;
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
	current_node->next = new_node;
}
void push_to_the_position(List& list, char& data, const int& position) {
	Node* new_node = new Node;
	new_node->data = data;
	if (position < 2) {
		new_node->next = list.head_node;
		list.head_node = new_node;
		return;
	}
	Node* current_node = list.head_node;
	if (position > size_list(list)) {
		pushBack(list, data);
		return;
	}
	for (int i = 1; i < position - 1; i++) {
		current_node = current_node->next;
	}
	new_node->next = current_node->next;
	current_node->next = new_node;
}
void del_on_position(List& list, const int& position) {
	if (list.head_node == nullptr) {
		return;
	}
	Node* current_node = list.head_node;
	if (position < 2) {
		list.head_node = list.head_node->next;
		delete current_node;
		return;
	}
	if (position >= size_list(list)) {
		while (current_node->next->next != nullptr) {
			current_node = current_node->next;
		}
		current_node->next = nullptr;
		return;
	}

	for (int i = 1; i != position - 1; i++) {
		current_node = current_node->next;
	}
	Node* delnode = current_node->next;
	current_node->next = current_node->next->next;
	delete delnode;
}
void print(List& list) {
	if (list.head_node == nullptr) {
		cout << "Empty list" << endl;
		return;
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