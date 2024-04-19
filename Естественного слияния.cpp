#include <iostream>
#include <vector>
using namespace std;

bool issort(int* mass, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (mass[i] > mass[i + 1]) {
            return 0;
        }
    }
    return 1;
}
void merge2s(int* mass, int start, vector<int>& serie1, vector<int>& serie2){
    int l = serie1.size() + serie2.size();
    for (int j = start; j < start + l; j++) {
        bool f = true;
        if (serie1.size() > 0 && serie2.size() > 0) {
            if (serie1.front() <= serie2.front()) {
                mass[j] = serie1.front();
                serie1.erase(serie1.begin());
                f = false;
            }
            else {
                mass[j] = serie2.front();
                serie2.erase(serie2.begin());
                f = false;
            }
        }
        if (serie1.size() > 0 && f) {
            mass[j] = serie1.front();
            serie1.erase(serie1.begin());
            f = false;
        }
        if (serie2.size() > 0 && f) {
            mass[j] = serie2.front();
            serie2.erase(serie2.begin());
            f = false;
        }
    } 
}
void merge(int* mass, int lenmass) {
    vector <int> serie1;
    vector <int> serie2;
    int a = 1;
    while (issort(mass, lenmass) == 0) {
        int j = 0;
        while (j < lenmass) {
            int start = j;

            bool f = true;
            while ((j < lenmass) && f) {
                if (mass[j] <= mass[j + 1]) {
                    serie1.push_back(mass[j]);
                }
                else {
                    f = false;
                    serie1.push_back(mass[j]);
                }
                j++;
            }
            for (int i = 0; i < serie1.size(); i++) {
                cout << serie1[i] << " ";
            }
            cout << endl;
            f = true;
            while ((j < lenmass) && f) {
                if (mass[j] <= mass[j + 1]) {
                    serie2.push_back(mass[j]);
                }
                else {
                    f = false;
                    serie2.push_back(mass[j]);
                }
                j++;
            }
            for (int i = 0; i < serie2.size(); i++) {
                cout << serie2[i] << " ";
            }
            cout << endl;
            merge2s(mass, start, serie1, serie2);
            a++;
        }
    }
    for (int i = 0; i < lenmass; i++) {
        cout << mass[i] << " ";
    }
}
int main() {
    system("chcp 1251>Null");
    int* mass = new int[15] {3, 42, 56, 34,14,-7, 64, 4, 15, 45, 53, 12, 23, 54, 0};
    merge(mass, 15);
    return 0;
}