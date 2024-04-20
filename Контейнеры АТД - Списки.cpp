#include <iostream>
using namespace std;
int MAX_SIZE = 30;
class Error {
	string message;
public:
	Error(string s) {
		message = s;
	}
	void what() {
		cout << message << endl;
	}
};
struct Node {
	int data;
	Node* next_node = nullptr;
	Node* prev_node = nullptr;
};
class List {
	int size;
	Node* head_node;
	Node* tail_node;
public:
	List();
	List(int size);
	List(int size, int data);
	List(const List& list);
	~List();
	int front();
	int back();
	void push_back(int data);
	void push_front(int data);
	int pop_back();
	int pop_front();
	bool is_empty();
	int operator () ();
	List& operator = (const List& list);
	int& operator [] (int index);
	List operator * (List& list);
	friend istream& operator >> (istream& is, const List& list);
	friend ostream& operator << (ostream& os, const List& list);
};
List::List() {
	this->size = 0;
}
List::List(int size) {
	this->size = size;
	if (size > 0) {
		Node* node = new Node;
		this->head_node = node;
		this->tail_node = node;
		for (int i = 1; i < size; i++) {
			Node* new_node = new Node;
			tail_node->next_node = new_node;
			new_node->prev_node = tail_node;
			tail_node = new_node;
		}
		tail_node->next_node = nullptr;
	}
	else {
		this->head_node = nullptr;
		this->tail_node = nullptr;
	}
}
List::List(int size, int data) {
	if (size > 30 || size == 0) throw Error("Размер введён неправильно"); 
	this->size = size;
	if (size > 0) {
		Node* node = new Node;
		node->data = data;
		this->head_node = node;
		this->tail_node = node;
		for (int i = 1; i < size; i++) {
			Node* new_node = new Node;
			new_node->data = data;
			tail_node->next_node = new_node;
			new_node->prev_node = tail_node;
			tail_node = new_node;
		}
		tail_node->next_node = nullptr;
	}
	else {
		this->head_node = nullptr;
		this->tail_node = nullptr;
	}
}
List::List(const List& list) {
	this->head_node = nullptr;
	this->tail_node = nullptr;
	this->size = 0;
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		this->push_back(current_node->data);
		current_node = current_node->next_node;
	}
}
List::~List() {
	Node* current_node = this->head_node;
	while (current_node != nullptr) {
		Node* next = current_node->next_node;
		delete current_node;
		current_node = next;
	}
	this->head_node = nullptr;
}
void List::push_back(int data) {
	if (size == MAX_SIZE) throw Error("Добавление элементов невозможно");
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next_node = nullptr;
	if (this->head_node == nullptr) {
		this->head_node = new_node;
		this->tail_node = new_node;
	}
	else {
		tail_node->next_node = new_node;
		new_node->prev_node = tail_node;
		tail_node = new_node;
	}
	this->size++;
}
void List::push_front(int data) {
	if (size == MAX_SIZE) throw Error("Добавление элементов невозможно");
	Node* new_node = new Node;
	new_node->data = data;
	if (this->head_node == nullptr) {
		this->head_node = new_node;
		this->tail_node = new_node;
		this->size++;
	}
	else {
		head_node->prev_node = new_node;
		new_node->next_node = head_node;
		head_node = new_node;
		this->size++;
	}
}
int List::front() {
	return this->head_node->data;
}
int List::back() {
	return this->tail_node->data;
}
int List::pop_back() {
	int temp;
	if (this->tail_node != nullptr) {
		Node* curr = this->tail_node;
		tail_node = curr->prev_node;
		temp = curr->data;
		tail_node->next_node = nullptr;
		this->size--;
	}
	return temp;
}
int List::pop_front() {
	int temp;
	if (this->head_node != nullptr) {
		Node* curr = head_node;
		head_node = curr->next_node;
		temp = curr->data;
		head_node->prev_node = nullptr;
		this->size--;
	}
	return temp;
}
bool List::is_empty() {
	return this->size == 0;
}
List& List::operator = (const List& list) {
	cout << " Оператор присваивания " << endl;
	if (this == &list) {
		return *this;
	}
	while (head_node != nullptr) {
		Node* temp = head_node;
		head_node = head_node->next_node;
		delete temp;
	}
	size = 0;
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		push_back(current_node->data);
		current_node = current_node->next_node;
	}
	return *this;
}
int& List::operator [] (int index) {
	if (index < 0) throw Error("Индекс введён неправильно");                                 //2
	if (index >= size) throw Error("Индекс введён неправильно");                                 //3
	Node* current_node = this->head_node;
	for (int i = 1; i < index; i++) {
		current_node = current_node->next_node;
	}
	return current_node->data;

}
int List::operator() (){
	return this->size;
}
List List::operator * (List& list) {
	int temp_size;
	if (this->size > list.size) {
		temp_size = list.size;
	}
	else { temp_size = this->size; }
	List temp(temp_size, 0);
	for (int i = 0; i < temp_size; i++) {
		temp[i] = (*this)[i] * list[i];
	}
	return temp;
}
ostream& operator << (ostream& os, const List& list) {
	if (list.size == 0) { cout << "Empty list" << endl; return os; }
	os << endl << " Вывод элементов списка " << endl;
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		os << current_node->data << " ";
		current_node = current_node->next_node;
	}
	os << endl << " Вывод элементов списка завершён " << endl;
	return os;
}
istream& operator >> (istream& is, const List& list) {
	cout << endl << " Ввод элементов списка: " << endl;
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		is >> current_node->data;
		current_node = current_node->next_node;
	}
	cout << endl << " Ввод элементов завершён " << endl;
	return is;
}
int main() {
	system("chcp 1251 > Null");
	srand(time(NULL));
	try {
		List l1(100, 6);
	}
	catch (Error e) {
		e.what();
	}
		return 0;
}

