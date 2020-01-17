#include <iostream>
using namespace std;

void swap(int* digit1, int* digit2) {
	int t = *digit1;
	*digit1 = *digit2;
	*digit2 = t;
}

void info(const int* digit) {
	cout << "Адрес: " << digit << "; Значение: " << *digit << ";" << endl;
}

int msort(int* digit1, int* digit2, int* digit3) {
	if (*digit3 < *digit2) swap(digit3, digit2);
	if (*digit3 < *digit1) swap(digit3, digit1);
	if (*digit2 < *digit1) swap(digit2, digit1);
	return *digit3;
}

int* add(int* digit1, const int* digit2) {
	*digit1 = *digit1 + *digit2;
	return digit1;
}

int main()
{
	setlocale(LC_ALL, "");
	int a = 1, b = 2, c = 3;
	info(&a);
	info(&b);
	info(&c);
	cout << "Максимум: " << msort(&a, &b, &c) << endl;
	info(add(&b, add(&a, &c) ));
	system("pause");
}