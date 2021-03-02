#include <iostream>
#include <string>
#include <list>
using namespace std;


template <typename T>
class List
{
public:
	List();
	void push_back(T data);
	int GetSize() { return Size; }

	T& operator[](const int index);

	void insert(T value, int index);

private:
	template <typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node <T> *head;
};


template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node <T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current!=nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}  
}

template<typename T>
void List<T>::insert(T value, int index)
{
	Node<T>* previous = this->head;

	for (int i = 0; i < index - 1; i++)
	{
		previous = previous->pNext;
	}

	Node<T> *newNode = new Node<T>(value, previous->pNext);
	previous->pNext = newNode;
	Size++;
}


struct DoubleList
{
	int data;
	DoubleList *next;
	DoubleList *prev;
};
DoubleList *head;

void AddList(int value, int position)
{
	DoubleList *node = new DoubleList;
	node->data = value;
	if (head == NULL)
	{
		node->next = node;
		node->prev = node;
		head = node;
	}
	else
	{
		DoubleList *p = head;
		for (int i = position; i > 0; i--) p = p->next;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
}

int DeleteList(int position)
{
	if (head == NULL) { cout << "\nСписок пуст\n\n"; return 0; }
	if (head == head->next)
	{
		delete head;
		head = NULL;
	}
	else
	{
		DoubleList *a = head;
		for (int i = position; i > 1; i--) a = a->next;
		if (a == head) head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
}

void PrintList()
{
		DoubleList *a = head;
		do
		{
			cout << a->data << " ";
			a = a->next;
		} while (a != head); cout << "\n\n";
}



void single_list()
{
	List<char> lst;
	char k;
	int numbersCount = -1;
	while (numbersCount <= 0)
	{
		cout << "Введи количество элементов в списке: ";
		cin >> numbersCount;
	}

	cout << "Введи элементы списка:" << endl;
	for (int i = 0; i < numbersCount; i++)
	{
		cout << i << ")";
		cin >> k;
		lst.push_back(k);
	}
	cout << "Новый список:" << endl;

	for (int i = 1; i < lst.GetSize(); i = i + 2)
	{
		lst.insert('A', i);
	}


	for (int i = 0; i < lst.GetSize(); i++)
		cout << i << ")" << lst[i] << " ";
}

void double_list()
{
	int numbersCount = -1;
	int k, j=-1;
	while (numbersCount <= 0)
	{
		cout << "Введи количество элементов в списке: ";
		cin >> numbersCount;
	}

	cout << "Введи элементы списка:" << endl;
	for (int i = 0; i < numbersCount; i++)
	{
		cin >> k;
		AddList(k, i);
		if (k % 2 == 0) j = i+1;
	}
	if (j == -1)
		cout << "Четных элементов нет";
	else
	{
		DeleteList(j);
		cout << "Измененный список: \t";
		PrintList();
	}
}

void double_listSTL()
{
	

	int numbersCount = -1, j, k;

	while (numbersCount <= 0)
	{
		cout << "Введи количество элементов в списке: ";
		cin >> numbersCount;
	}

	list<int> newList;
	cout << "Введи элементы списка: " << endl;
	for (int i = 0; i < numbersCount; i++)
	{
		cin >> j;
		newList.push_back(j);
		if (j % 2 == 0) k = i;
	}

	auto it = newList.begin();
	advance(it, k);
	newList.erase(it);

	cout << "Измененный список: " << endl;
	for (auto i = newList.begin(); i != newList.end(); i++)
		cout << *i << " ";
}

void stack()
{
	int numbersCount = -1, j = 0;
	while (numbersCount <= 0)
	{
		cout << "Введи количество элементов в стеке: ";
		cin >> numbersCount;
	}

	char* a1 = new char[numbersCount];
	cout << "Вводи элементы стека: ";
	for (int i = numbersCount - 1; i >= 0; i--)
		cin >> a1[i];

	cout << "Стек: ";
	for (int i = 0; i < numbersCount; i++)
		cout << i << ")" << a1[i] << " ";

	char* a2 = new char[numbersCount];
	for (int i = 0; i < numbersCount * 2; i++)
		if (i % 2 != 0)
		{
			a2[i] = 'A';
		}
		else
		{
			a2[i] = a1[j];
			j++;
		}
	cout << "\nНовый стек: ";
	for (int i = 0; i < numbersCount * 2; i++)
		cout << i << ")" << a2[i] << " ";
}

void queue()
{
	int numbersCount = -1, j = 0,k;
	while (numbersCount <= 0)
	{
		cout << "Введи количество элементов в очереди: ";
		cin >> numbersCount;
	}

	char* a1 = new char[numbersCount];
	cout << "Вводи элементы очереди: ";
	for (int i = 0; i < numbersCount; i++)
	{
		cin >> a1[i];
		if (a1[i] % 2 == 0) k = i;
	}
		

	cout << "Очередь: ";
	for (int i = 0; i < numbersCount; i++)
		cout << i << ")" << a1[i] << " ";

	char* a2 = new char[numbersCount-1];
	for (int i = 0; i < k; i++)
			a2[i] = a1[i];

	for (int i = k + 1; i < numbersCount; i++)
		a2[i - 1] = a1[i];
		
	cout << "\nНовая очередь: ";
	for (int i = 0; i < numbersCount-1; i++)
		cout << i << ")" << a2[i] << " ";


}

int main()
{
	setlocale(LC_ALL, "ru");
	int menu = -1;

		while (menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5)
		{
			cout << "Выбери вид динамической структуры:" << endl << "\n" << "1) Односвязный список" << "\n" << "2) Двусвязный список" << "\n" << "3) Двусвязный список stl" << "\n" << "4) Стек" << "\n" << "5) Очередь" << "\n" ;
			cout << "\nВвод: ";
			cin >> menu;
		}

		if (menu == 1) single_list();
		if (menu == 2) double_list();
		if (menu == 3) double_listSTL();
		if (menu == 4) stack();
		if (menu == 5) queue();
}