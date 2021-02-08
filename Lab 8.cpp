#include <iostream>
#include <string>
using namespace std;

struct students
{
	string name;
	string surname1;
	string surname;
	string phonenumber;
	int mark1; int mark2; int mark3;
};
	
int main()
{
	system("chcp 1251>nul");
	int n = -1, m = -1, i;
	string surnamecheck = "ааа";

	students N1 = {"Георгий", "Андреевич", "Монин", "+7(902)45-67928", 5, 2, 2};
	students N2 = { "Никита", "Алексеевич", "Коваленко", "+7(908)277-1780", 5, 5, 5 };
	students N3 = { "Алексей", "Павлович", "Солдатов", "+7(902)45-32228", 3, 4, 2 };
	students N4 = { "Иван", "Иванович", "Иванов", "+7(902)55-64238", 2, 4, 3 };
	students N5 = { "Петр", "Алексеевич", "Романов", "+7(961)18-59348", 2, 5, 3 };
	students N6 = { "Александр", "Мамонов", "Александрович", "+7(961)22-58651", 5, 5, 5 };
	
	students a[6] = { N6, N1, N2, N3, N4, N5 };
	for (i = 1; i < 6; i++)
	cout << " " << i << ") " << '\t' << a[i].name << endl << '\t' << a[i].surname1 << endl << '\t' << a[i].surname << endl << '\t' << a[i].phonenumber << endl << '\t' << a[i].mark1 << " "  << a[i].mark2 << " "  << a[i].mark3 << endl << endl;
	
	while (n < 1 || n>5)
	{
		cout << "Введи номер, который нужно удалить: "; cin >> n;
	}
	while (m < 1 || m >5)
	{
		cout << "Введи среднее арифметическое оценок: "; cin >> m;
	}

	while (surnamecheck != "Монин" && surnamecheck != "Коваленко" && surnamecheck != "Солдатов" && surnamecheck != "Иванов" && surnamecheck != "Романов")
	{
		cout << "Введи фамилию, после которой добавить элемент: "; cin >> surnamecheck;
	}

	cout << "Изменения:" << endl;
	i = 1;

	while (i != n && a[i].surname != surnamecheck && i < 6)
	{
		cout << '\t' << a[i].name << endl << '\t' << a[i].surname1 << endl << '\t' << a[i].surname << endl << '\t' << a[i].phonenumber << endl << '\t' << a[i].mark1 << " " << a[i].mark2 << " " << a[i].mark3 << endl << endl;
		i++;
	}

	if (i == n && (a[i].mark1 + a[i].mark2 + a[i].mark3)/3 < m) i++;
	
	if (a[i].surname == surnamecheck)
	{
		cout << '\t' << a[i].name << endl << '\t' << a[i].surname1 << endl << '\t' << a[i].surname << endl << '\t' << a[i].phonenumber << endl << '\t' << a[i].mark1 << " " << a[i].mark2 << " " << a[i].mark3 << endl << endl;
		i++;
		cout  << '\t' << a[0].name << endl << '\t' << a[0].surname1 << endl << '\t' << a[0].surname << endl << '\t' << a[0].phonenumber << endl << '\t' << a[0].mark1 << " " << a[0].mark2 << " " << a[0].mark3 << endl << endl;
	}

	while (i != n && a[i].surname != surnamecheck && i<6)
	{
		cout  << '\t' << a[i].name << endl << '\t' << a[i].surname1 << endl << '\t' << a[i].surname << endl << '\t' << a[i].phonenumber << endl << '\t' << a[i].mark1 << " " << a[i].mark2 << " " << a[i].mark3 << endl << endl;
		i++;
	}

	if (i == n && (a[i].mark1 + a[i].mark2 + a[i].mark3) / 3 < m) i++;

	if (a[i].surname == surnamecheck)
	{
		cout << '\t' << a[i].name << endl << '\t' << a[i].surname1 << endl << '\t' << a[i].surname << endl << '\t' << a[i].phonenumber << endl << '\t' << a[i].mark1 << " " << a[i].mark2 << " " << a[i].mark3 << endl << endl;
		i++;
		cout << '\t' << a[0].name << endl << '\t' << a[0].surname1 << endl << '\t' << a[0].surname << endl << '\t' << a[0].phonenumber << endl << '\t' << a[0].mark1 << " " << a[0].mark2 << " " << a[0].mark3 << endl << endl;
	}

	while (i < 6)
	{
		cout << '\t' << a[i].name << endl << '\t' << a[i].surname1 << endl << '\t' << a[i].surname << endl << '\t' << a[i].phonenumber << endl << '\t' << a[i].mark1 << " " << a[i].mark2 << " " << a[i].mark3 << endl << endl;
		i++;
	}
}					