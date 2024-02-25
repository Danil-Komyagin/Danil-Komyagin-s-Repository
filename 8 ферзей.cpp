#include <iostream>
using namespace std;

void setQueen(int i, int j);
void resetQueen(int i, int j);
void printBoard(int(*board)[8], int str);
bool tryQueen(int i);

int board[8][8] = { 0 };   // Создание массива-доски

int main() {
	tryQueen(0);
	for (int i = 0; i < 8; i++) {   // Вывод итогового положения фигур
		for (int j = 0; j < 8; j++) {
			if (*(*(board + i) + j) == -1) cout << " Q ";
			else cout << " * ";
		}
		cout << endl;
	}
	return 0;
}
void printBoard(int(*board)[8], int str) {  // Функция выводит массив - доску с текущими значениями
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < 8; j++) {
			if (*(*(board + i) + j) == -1) cout << " Q ";
			else cout << " " << *(*(board + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}
bool tryQueen(int i) {					// Функция проверяет, можно ли поставить ферзя на данную позицию. 
	bool result = false;				// В цикле проверяются все элементы строки; если элемент равен 0,
	for (int j = 0; j < 8; j++) {		// На данную позицию ставится ферзь.Далее выполняется переход на следующую строку.
		if (*(*(board + i) + j) == 0) {	// Если в какой - либо из последующих строк ни в один столбец нельзя поставить ферзя,
			setQueen(i, j);				// Выполняется переход на предыдущий шаг, и ферзь ставится уже на следующую допустимую позицию.
			if (i == 7) result = true; 
			else {
				result = tryQueen(i + 1);
				if (result == false) resetQueen(i, j);
			}
		}
	}
	return result;
}
void setQueen(int i, int j) {
	for (int x = 0; x < 8; x++) {  // Функция ставит ферзя и отмечает те позиции, 
		*(*(board + x) + j) += 1;  // Которые находятся под ударом ферзя: 
		*(*(board + i) + x) += 1;  // Прибавляет 1 к значениям элементов.
		int c;
		c = j - i + x;
		if (c >= 0 && c < 8) *(*(board + x) + c) += 1;
		c = j + i - x;
		if (c >= 0 && c < 8) *(*(board + x) + c) += 1;
	}
	*(*(board + i) + j) = -1;
	printBoard(board, 8);
}
void resetQueen(int i, int j) {
	for (int x = 0; x < 8; x++) { // Функция убирает с позиции ферзя и отнимает 1 с тех позиций,
		*(*(board + x) + j) -= 1; // Которые находились под ударом этого ферзя.
		*(*(board + i) + x) -= 1;
		int c;
		c = j - i + x;
		if (c >= 0 && c < 8) *(*(board + x) + c) -= 1;
		c = j + i - x;
		if (c >= 0 && c < 8) *(*(board + x) + c) -= 1;
	}
	*(*(board + i) + j) = 0;
	printBoard(board, 8);
}