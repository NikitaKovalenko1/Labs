#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = -2, k = -5;
	while (size < 1)
	{
		cout << "Введи размерность массива: "; cin >> size;
	}
	
	string* a1 = new string[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Введи " << i + 1 << " строку:" << "\t"; cin >> a1[i];
	}

	while (k < 1 || k > size)
	{
		cout << "Введи, сколько строк нужно удалить: "; cin >> k;
	}

	for (int j = 1; j <= k; j++)
		for (int i = 0; i < size - 1; i++)
			a1[i] = a1[i + 1];

	string* a2 = new string[size-k];
	for (int i = 0; i < size - k; i++)
		a2[i] = a1[i];
	delete[] a1;

	cout << "Массив с изменениями: " << endl;
	for (int i = 0; i < size - k; i++)
	{
		cout << i + 1 << ")    " << a2[i] << endl;
	}
}