#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0)); 
	int digit;
	int ans = 1;
	cout << "Приветствую! Проверьте вашу удачи и отгадайте загаднное число от 0 до 100 \nУ вас в наличии 5 попыток\nВведите число: ";
	int a = rand() % 101;
	int i = 0; 
	while (ans == 1) { 
		cin >> digit;
		if (digit > a)
			cout << "Загаданное число меньше" << endl;
		else if (digit < a)
			cout << "Загаданное число больше" << endl;
		else {
			cout << "Число угадано";
			break; 
		}
		i++; 
		if (i == 5) {
			int a = 0 + rand() % 101;
			cout << "Желаете продолжить? Нажмите 1 для согласие, НЕ 1 для отказа: ";
			cin >> ans;
			if (ans != 1) cout << "Загададанное число - " << a;
			i = 0;
		}
	}
}
