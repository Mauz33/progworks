#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int n = 20;
	double a[20];
	double min, max;
	for (int i = 0; i < n; i++) {
		a[i] = -100 + rand() % 201;
	}
	min = a[0];
	max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] < min) min = a[i];
		if (a[i] > max) max = a[i];
		cout << a[i] << " "; ;
	}
	cout << endl;
	cout << min << endl;
	cout << max;
}
//rand() % 101 - это от 0 до 100 включительно
//отнимем от этого диапазона 100
//Получим от - 100 до 0
//чтоб было от - 100 до 100 надо сделать rand % 201 - 100
