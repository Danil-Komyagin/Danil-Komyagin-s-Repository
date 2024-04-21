#include <string>
#include <iostream>
using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmQuit = 101;

struct TEvent {
	int what;
	union {
		int command;
		struct {
			int message;
			int a;
		};
	};
};

class Object {
public:
	Object() {}
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual string Get_name() = 0;
	virtual void Get_Name() = 0;
	virtual void HandleEvent(const TEvent& e) = 0;
	~Object() {}
};

class Print : public Object {
protected:
	string name;
	string author;
public:
	Print() {
		name = "";
		author = "";
	}
	~Print(){}
	Print(string n, string a) {
		name = n;
		author = a;
	}
	Print(const Print& other) {
		name = other.name;
		author = other.author;
	}
	void Set_name(string n) {
		name = n;
	}
	void Set_author(string a) {
		author = a;
	}
	Print& operator =(const Print& p) {
		if (&p == this) {
			return *this;
		}
		this->name = p.name;
		this->author = p.author;
		return *this;

	}
	void Show() {
		cout << " Название: " << name << endl;
		cout << " Автор: " << author << endl;
	}
	void Input() {
		cout << " Введите название: ";
		cin >> name;
		cout << " Введите автора: ";
		cin >> author;
		cout << endl;
	}
	void Get_Name() {
		cout << name << endl;
	}
	string Get_name() { return name; }
	string Get_author() { return author; }
	void HandleEvent(const TEvent& e) {  
		if (e.what == evMessage) {
			switch (e.command){
			case cmGet: cout << "Название: " << Get_name() << endl; break;
			}
		}
	}
};
class Magazin : public Print {
protected: int pages;
public:
	~Magazin(){}
	Magazin() : Print(){
		pages = 0;
	}
	Magazin(string n, string a, int p) : Print(n, a) {
		pages = p;
	}
	Magazin(const Magazin& m) {
		name = m.name;
		author = m.author;
		pages = m.pages;
	}
	void Set_pages(int p) {
		pages = p;
	}
	Magazin& operator = (const Magazin& m) {
		if (&m == this) { return *this; }
		this->author = m.author;
		this->name = m.name;
		this->pages = m.pages;
		return *this;
	}
	void Show() {
		cout << "Название: " << name << endl;
		cout << "Автор: " << author << endl;
		cout << "Страницы: " << pages << endl;
	}
	void Input() {
		cout << "Введите название: ";
		cin >> name;
		cout << "Введите автора: ";
		cin >> author;
		cout << "Введите страницы: ";
		cin >> pages;
		cout << endl;
	}
	void Get_Name() {
		cout << name << endl;
	}
	string Get_name() { return name; }
	int Get_pages() { return pages; }
};


class Vector
{
public:
	Vector();
	Vector(int);
public:
	~Vector(void);
	void Add();
	void Del();
	void Show();
	void Get_Name();
	int operator()();
	void HandleEvent(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};
Vector::~Vector(void)
{
	if (beg != 0) { delete[] beg; }
	beg = 0;
}
Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
Vector::Vector()
{
	beg = 0;
	cur = 0;
	size = 0;
}
void Vector::Add()
{
	Object* p;
	cout << "1. Издательство: " << endl;
	cout << "2. Журнал: " << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		Print* a = new Print;
		a->Input();
		p = a;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
		if (y == 2)
		{
			Magazin* b = new Magazin;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}
void Vector::Show()
{
	if (cur == 0) cout << "Ничего не найдено" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}
void Vector::Get_Name() {
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		(*p)->Get_Name();
		p++;
	}
}
int Vector::operator ()() {
	return cur;
}
void Vector::Del()
{
	if (cur == 0) { return; }
	cur--;
}
void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}

class Dialog : public Vector {
protected:
	int EndState;
public:
	Dialog() : Vector(){
		EndState = 0;
	
	}
	~Dialog(){}
	void ClearEvent(TEvent& event){
		event.what = evNothing;
	}
	void EndExec() {
		EndState = 1;
	}
	void GetEvent(TEvent& event) {
		string opint = "m+-szq";
		string s;
		char code;
		cout << ">";
		cin >> s;
		code = s[0];
		if (opint.find(code) >= 0) {
			event.what = evMessage;
			switch (code) {
			case 'm':event.command = cmMake; break;
			case '+': event.command = cmAdd; break;
			case '-': event.command = cmDel; break;
			case 's': event.command = cmShow; break;
			case 'z': event.command = cmGet; break;
			case 'q': event.command = cmQuit; break;
			}
		}
		else event.what = evNothing;
	}
	void Execute() {
		TEvent event;
		do {
			EndState = 0;
			GetEvent(event);
			HandleEvent(event);
		} while (Valid());
	}
	bool Valid() {
		return EndState == 0;
	}
	void HandleEvent(TEvent& event) {
		if (event.what == evMessage) {
			switch (event.command) {
			case cmMake:
				cout << "Введите размер группы: " << endl;
				cin >> size;
				beg = new Object * [size];
				cur = 0;
				ClearEvent(event); break;
			case cmAdd:
				Add();
				ClearEvent(event); break;
			case cmDel:
				Del();
				ClearEvent(event); break;
			case cmShow:
				Show();
				ClearEvent(event); break;
			case cmGet:
				Get_Name();
				ClearEvent(event); break;
			case cmQuit:
				EndExec();
				ClearEvent(event); break;
			};
		}
	}
};
int main() {
	system("chcp 1251 > Null");
	cout << "m: Создать группу" << endl;
	cout << "+: Добавить элемент" << endl;
	cout << "-: Удалить элемент" << endl;
	cout << "s: Информация о членах группы" << endl;
	cout << "z: Информация о названиях элементов группы" << endl;
	cout << "q: Конец работы" << endl;
	Dialog d;
	d.Execute();
	return 0;
}
