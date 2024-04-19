#include <iostream>
#include <string>
using namespace std;

struct Node {
	char data;
	Node* prev = nullptr;
};
struct Stack {
	Node* head_node = nullptr;
};

void push(Stack& stack, char& data);
void print(Stack& stack);
int size_stack(Stack& stack);
void del_front(Stack& stack);

int main() {
	setlocale(LC_ALL, "RU");
	Stack stack1, stack2;
	cout << "Введите элементы стека: ";
	string a;
	cin >> a;
	for (int i = 0; i < size(a); i++) {
		push(stack1, a[i]);
	}
	cout << "Текущий стек: " << endl;
	print(stack1);
	string key;
	cout << "Введите ключ для удаления: ";
	cin >> key;
	cout << endl;
	while (stack1.head_node != nullptr) {
		if (stack1.head_node->data == key[0]) {
			del_front(stack1);
		}
		else {
			push(stack2, stack1.head_node->data);
			stack1.head_node = stack1.head_node->prev;
		}
	}
	print(stack2);
	int num;
	cout << "Введите позицию для ввода элементов: ";
	cin >> num;
	Node* current_node = stack2.head_node;
	for (int i = 1; i != num; i++) {
		if (current_node != nullptr) {
			push(stack1, current_node->data);
			current_node = current_node->prev;
		}
	}
	Node* new_node = new Node;
	cout << "Введите количество элементов для ввода: ";
	int kol;
	cin >> kol;
	for (int i = 1; i <= kol; i++) {
		cout << "Введите элемент № " << i << ": ";
		cin >> new_node->data;
		push(stack1, new_node->data);
	}
	while (current_node != nullptr) {
		push(stack1, current_node->data);
		current_node = current_node->prev;
	}
	print(stack1);
	return 0;
}

int size_stack(Stack& stack) {
	Node* current_node = stack.head_node;
	int k = 0;
	while (current_node != nullptr) {
		k += 1;
		current_node = current_node->prev;
	}
	return k;
}
void push(Stack& stack, char& data) {
	Node* new_node = new Node;
	new_node->data = data;
	if (stack.head_node == nullptr) {
		stack.head_node = new_node;
		return;
	}
	new_node->prev = stack.head_node;
	stack.head_node = new_node;
}
void print(Stack& stack) {
	Node* current_node = stack.head_node;
	while (current_node != nullptr) {
		cout << current_node->data << endl;
		current_node = current_node->prev;
	}
	cout << endl;
}
void del_front(Stack& stack) {
	if (stack.head_node == nullptr) {
		return;
	}
	Node* current_node = stack.head_node;
	stack.head_node = stack.head_node->prev;
	delete current_node;
}
