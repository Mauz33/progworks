#include <iostream>
#include <ctime>
#include "func.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	char symbol;
	symbol = ' ';

	while (symbol != 'X' && symbol != '0') {
		std::cout << "Выбор символа ('Х' или '0'): ";
		std::cin >> symbol;
	}

	Game cross_zero = initGame(symbol);

	while (!updateGame(&cross_zero))
	{
		if (cross_zero.isUserTurn)userTurn(&cross_zero);
		else botTurn(&cross_zero);
		updateDisplay(cross_zero);
	}
	if (cross_zero.status == USER_WIN)std::cout << "Вы победили!";
	else if (cross_zero.status == BOT_WIN)std::cout << "Вы проиграли!";
	else std::cout << "Ничья!";
}