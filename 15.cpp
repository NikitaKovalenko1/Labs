#include <iostream> 
using namespace std;

int board[8][8];
int rcount = 0;

void doska() //Инициализация двумерного массива ввиде шахматной доски
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
// Проверка совпадение с ходами других ферзей 
bool check(int a, int b)
{
	for (int i = 0; i < a; i++) {
		if (board[i][b]) return false;//Проверка совпадений по горизонтали и вертикали 
	}
	for (int i = 1; i <= a && b - i >= 0; i++) {
		if (board[a - i][b - i]) return false;//Проверка главной диагонали 
	}
	for (int i = 1; i <= a && b + i < 8; i++) {
		if (board[a - i][b + i]) return false;//Проверка побочной диагонали 
	}
	return true;
}

void variants(int a) {
	if (a == 8) {
		doska();
		cout << "Вариант решения задачи: " << ++rcount << endl;
	}
	for (int i = 0; i < 8; i++) {
		if (check(a, i)) {
			board[a][i] = 1;
			variants(a + 1);
			board[a][i] = 0;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	variants(0);
	system("pause");
	return 0;
}