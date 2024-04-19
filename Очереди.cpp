#include <string>
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next = nullptr;
};
struct Queue {
    Node* head_node = nullptr;
    Node* tail_node = nullptr;
};

void push(Queue& queue, char data);
void print(Queue& queue);
void del(Queue& queue);
int size_queue(Queue& queue);

int main() {
    setlocale(LC_ALL, "RU");
    Queue queue1;
    Queue queue2;
    string a, key;
    int num, kol;
    int i = 0;
    cout << "Введите очередь: ";
    cin >> a;
    for (int i = 0; i < size(a); i++) {
        push(queue1, a[i]);
    }
    print(queue1);
    cout << "Введите ключ для удаления: ";
    cin >> key;
    while (queue1.head_node != nullptr) {
        if (queue1.head_node->data == key[0]) {
            del(queue1);
        }
        else {
            push(queue2, queue1.head_node->data);
            del(queue1);
        }
    }
    print(queue2);
    cout << "Введите номер, перед которым нужно поставить элемены: ";
    cin >> num;
    while (i < num - 1) {
        if (queue2.head_node != nullptr) {
            push(queue1, queue2.head_node->data);
            del(queue2);
        }
        i += 1;
    }
    cout << "Введите количество элементов для ввода: ";
    cin >> kol;
    for (int i = 0; i < kol; i++) {
        string a;
        cout << "Введите элемент № " << i + 1 << ": ";
        cin >> a;
        push(queue1, a[0]);
    }
    while (queue2.head_node != nullptr) {
        push(queue1, queue2.head_node->data);
        del(queue2);
    }
    print(queue1);
    return 0;
}

void push(Queue& queue, char data) {
    Node* new_node = new Node;
    new_node->data = data;
    if (queue.head_node == nullptr) {
        queue.head_node = new_node;
        queue.tail_node = new_node;
    }
    else {
        queue.tail_node->next = new_node;
        queue.tail_node = new_node;
    }
}
void print(Queue& queue) {
    if (queue.head_node == nullptr) {
        cout << "Empty queue" << endl;
    }
    Node* current_node = queue.head_node;
    cout << "Начало -> ";
    while (current_node != nullptr) {
        cout << current_node->data << " -> ";
        current_node = current_node->next;
    }
    cout << "Конец" << endl;
}
void del(Queue& queue) {
    if (queue.head_node == nullptr) {
        return;
    }
    else {
        Node* current_node = queue.head_node;
        queue.head_node = queue.head_node->next;
        delete current_node;
    }
}
int size_queue(Queue& queue) {
    if (queue.head_node == nullptr) {
        return 0;
    }
    else {
        int s = 0;
        Node* current_node = queue.head_node;
        while (current_node != nullptr) {
            s += 1;
            current_node = current_node->next;
        }
        return s;
    }
}

    

