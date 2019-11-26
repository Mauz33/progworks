#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int digit1, digit2; //чилсло1, число2;
	char oper; // Знак операции, которая будет выполняться
	cin >> digit1 >> oper >> digit2;
	switch (oper) {
		case '+': cout << digit1 + digit2; break;
		case '-': cout << digit1 - digit2; break;
		case '*': cout << digit1 * digit2; break;
		case '/': cout << digit1 / digit2; break;
		default: cout << "Ошибка";

	}
}