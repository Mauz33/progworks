#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, i, j, s, q, l;
	cout << "Введите количество элементов n" << endl;
	cin >> n;
	int *arr = new int[n];
	cout << "Укажите значения элементов" << endl;
	for (i = 0; i < n; i++) //главный цикл
	{
		cout << endl;
		cin >> arr[i];
		for (j = 0; j <= i; j++) //сортировка введенных элементов по возрастанию
		{
			if (j == 0) //если введен только 1 элемент, то сортировка не требуется
				continue;
			else
				for (q = 0; q <= i - 1; q++) //порог стравнения элементов
				{
					if (arr[q] > arr[q + 1]) //проверка условия
					{
						swap(arr[q], arr[q + 1]); //меняем переменные местами, если условие==1
					}
				}
				
		}
		l = i;
		if (l > 4) //если циклов было больше 4, то проверку делать от 4, если меньше, то от i
			l = 4;
		for (s = l; s >= 0; s--)
		{
			cout << arr[s] << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}



#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, i, j, s, q, l;
	cout << "Введите количество элементов n" << endl;
	cin >> n;
	int *arr = new int[n];
	cout << "Укажите значения элементов" << endl;
	for (i = 0; i < n; i++) //главный цикл
	{
		cout << endl;
		cin >> arr[i];
		for (j = 0; j <= i; j++) //сортировка введенных элементов по возрастанию
		{
			if (j == 0) //если введен только 1 элемент, то сортировка не требуется
				continue;
			else
				for (q = 0; q <= i - 1; q++) //порог стравнения элементов
				{
					if (arr[q] > arr[q + 1]) //проверка условия
					{
						swap(arr[q], arr[q + 1]); //меняем переменные местами, если условие==1
					}
				}
				
		}
		l = i;
		if (l > 4) //если циклов было больше 4, то проверку делать от 4, если меньше, то от i
			l = 4;
		for (s = l; s >= 0; s--)
		{
			cout << arr[s] << " ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}







