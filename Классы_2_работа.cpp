#include <iostream>
using namespace std;

class Salary {
	string FIO;
	double bonus;
	int premia;
public:
	Salary() {
		FIO = "noname";
		bonus = 0;
		premia = 0;
	}
	Salary(string f, double b, int p) {
		FIO = f;
		bonus = b;
		premia = p;
	}
	Salary(const Salary& other) {
		FIO = other.FIO;
		bonus = other.bonus;
		premia = other.premia;
	}
	~Salary() {
		cout << endl << "Destructor! ";
	}
	string getfio() {
		return FIO;
	}
	double getbonus() {
		return bonus;
	}
	int getpremia() {
		return premia;
	}
	void setfio(string fio) {
		FIO = fio;
	}
	void setbonus(double b) {
		bonus = b;
	}
	void setpremia(int p) {
		premia = p;
	}
	void print() {
		cout << "ФИО: " << FIO << " Оклад: " << bonus << " Премия: " << premia << endl;
	}
};


int main() {
	system("chcp 1251 > Null");

	Salary zp("Medvedev Daniil Sergeevich", 900000, 150);
	zp.print();

	cout << endl << zp.getfio() << " " << zp.getbonus() << " " << zp.getpremia();

	zp.setbonus(14);
	zp.setfio("Rublev Andrew Andreevich");
	zp.setpremia(100);
	
	cout << endl;

	zp.print();
	

	return 0;
}
