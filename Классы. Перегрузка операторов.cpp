#include <iostream>
using namespace std;

class Pair {
    int first;
    double second;
public:
    Pair(){
        first = 0;
        second = 0;
    }
    Pair(int f, double s) {
        first = f;
        second = s;
    }
    Pair(const Pair& other) {
        this->first = other.first;
        this->second = other.second;
    }
    ~Pair() {
        cout << "\nDestructor!" << endl;
    }
    void setFirst(int f) {
        first = f;
    }
    void setSecond(double s) {
        second = s;
    }
    void setBoth(int f, double s) {
        first = f;
        second = s;
    }
    void getFirst() {
        cout << first << endl;
    }
    void getSecond() {
        cout << second << endl;
    }
    void getBoth() {
        cout << first << " : " << second << endl;
    }
    Pair& operator = (Pair& s) {
        this->first = s.first;
        this->second = s.second;
        return *this;
    }
    Pair& operator + (Pair& s) {
        this->first += s.first;
        this->second += s.second;
        return *this;
    }
    Pair& operator - (Pair& s) {
        this->first -= s.first;
        this->second -= s.second;
        return *this;
    }
    Pair& operator ++ () {    // Префиксный инкремент;
        ++this->first;
        ++this->second;
        return *this;
    }
    Pair& operator ++ (int) {  // Постфиксный инкремент
        int tx = first;
        int ty = second;
        Pair tmp(tx, ty);
        this->first++;
        this->second++;
        return tmp;
    }
    Pair& operator -- () {
        --this->first;
        --this->second;
        return *this;
    }
    Pair& operator -- (int) {
        int tx = first;
        int ty = second;
        Pair tmp(tx, ty);
        this->first--;
        this->second--;
        return tmp;
    }
    friend ostream& operator <<(ostream& os, const Pair& a) {
        os << "First = " << a.first;
        os << "Second = " << a.second;
        return os;
    }
    friend istream& operator >>(istream& is, Pair& a) {
        is >> a.first >> a.second;
        return is;
    }
    Pair& operator + (int a) {
        this->first += a;
        return *this;
    }
    Pair& operator + (double a) {
        this->second += a;
        return *this;
    }
};

int main() {
    system("chcp 1251 > Null");

    Pair a(10, 12.4);
    Pair b(15, 17.6);

    a = a + 14.7;
    a.getBoth();

    a = a + 14;
    a.getBoth();

    a = a + b;
    a.getBoth();

    b = a;
    b.getBoth();

    ++a;
    ++b;

    cout << a << b;

    return 0;
}


