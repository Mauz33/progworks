МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
​
### Отчёт по лабораторной работе № 4 <br/> по дисциплине "Программирование"
<br/>
​
Студента 1 курса группы ПИ-б-о-191(1)<br/> 
Ещенко Максима Алексеевича <br/>
направления подготовки 09.03.04 "Программная инженерия"  
<br/>
​
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2019
<br/><br/>

#### Тема: Иксики-нолики

#### Цель: 
1. Закрепить навыки работы с перечислениями;
2. Закрепить навыки работы с структурами;
3. Освоить методы составления многофайловых программ.

###### 1. Основной файл main.cpp <br/>
```cpp
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
```

###### 2. Заголовочный файл func.h с защитой от повторного включения <br/>
```cpp
#pragma once

enum Status {
	PLAY,
	USER_WIN,
	BOT_WIN,
	NOT_WIN
};


struct Game {
	char board[3][3];
	bool isUserTurn;
	char userChar;
	char botChar;
	Status status;
};

Game initGame(char userChar);
void updateDisplay(const Game game);
void botTurn(Game* game);
void userTurn(Game* game);
bool updateGame(Game* game);
```

###### 3. Файл с реализацией func.cpp
```cpp
#include "func.h"
#include <iostream>
#include <ctime>


Game initGame(char userChar)
{
	Game start;
	srand(time(0));

	for (int i = 0; i < 3; i++) { // Очищаем поле
		for (int j = 0; j < 3; j++) {
			start.board[i][j] = ' ';
		}
	}

	start.isUserTurn = rand() % 2; // Определяем кто будет ходить первым. 1 - пользователь, 0 - бот.
	if (userChar == 'X') start.botChar = '0';
	else start.botChar = 'X';
	start.userChar = userChar;
	start.status = PLAY;
	return start;
}

void updateDisplay(const Game game)
{
	system("CLS");
	std::cout << "    1   2   3\n";
	std::cout << "  -------------\n";
	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << " | ";
		for (int j = 0; j < 3; j++) {
			std::cout << game.board[i][j] << " | ";
		}
		std::cout << "\n  -------------\n";
	}
}

void botTurn(Game* game)
{
	int counter = 0;
	int counter_bot = 0;
	int counter_user = 0;

	for (int i = 0; i < 3; i++) {							// Проверка есть ли заполненные клетки, чтобы походить в центр
		for (int j = 0; j < 3; j++) {
			if (game->board[i][j] == ' ') counter++;
		}
	}
	if (counter == 9) {
			game->board[1][1] = game->botChar;
			return;
	}
	counter = 0;

	for (int i = 0; i < 3; i++) {							
		if (game->board[i][i] == game->userChar) counter_user++;
		else if (game->board[i][i] == game->botChar) counter_bot++;
	}
	if (counter_bot == 2) {										
		for (int i = 0; i < 3; i++) {
			if (game->board[i][i] == ' ') {
				game->board[i][i] = game->botChar;
				return;
			}
		}
	}
	else if (counter_user == 2) {
		for (int i = 0; i < 3; i++) {
			if (game->board[i][i] == ' ') {
				game->board[i][i] = game->botChar;
				return;
			}
		}
	}
	counter_bot = 0;
	counter_user = 0;


	for (int i = 0; i < 3; i++) {						
		if (game->board[i][2 - i] == game->userChar) counter_user++;
		else if (game->board[i][2 - i] == game->botChar) counter_bot++;
	}
	if (counter_bot == 2) {										
		for (int i = 0; i < 3; i++) {
			if (game->board[i][2 - i] == ' ') {
				game->board[i][2 - i] = game->botChar;
				return;
			}
		}
	}
	else if (counter_user == 2) {
		for (int i = 0; i < 3; i++) {
			if (game->board[i][2 - i] == ' ') {
				game->board[i][2 - i] = game->botChar;
				return;
			}
		}
	}
	counter_bot = 0;
	counter_user = 0;


	for (int i = 0; i < 3; i++) {						
		if (game->board[i][i] == game->userChar) counter_user++;
		else if (game->board[i][i] == game->botChar) counter_bot++;
	}
	if (counter_bot == 2) {										
		for (int i = 0; i < 3; i++) {
			if (game->board[0][i] == ' ') {
				game->board[0][i] = game->botChar;
				return;
			}
		}
	}
	else if (counter_user == 2) {
		for (int i = 0; i < 3; i++) {
			if (game->board[0][i] == ' ') {
				game->board[0][i] = game->botChar;
				return;
			}
		}
	}
	counter_bot = 0;
	counter_user = 0;

	for (int i = 0; i < 3; i++) {							
		if (game->board[1][i] == game->userChar) counter_user++;
		else if (game->board[1][i] == game->botChar) counter_bot++;
	}
	if (counter_bot == 2) {										
		for (int i = 0; i < 3; i++) {
			if (game->board[1][i] == ' ') {
				game->board[1][i] = game->botChar;
				return;
			}
		}
	}
	else if (counter_user == 2) {
		for (int i = 0; i < 3; i++) {
			if (game->board[1][i] == ' ') {
				game->board[1][i] = game->botChar;
				return;
			}
		}
	}
	counter_bot = 0;
	counter_user = 0;


	for (int i = 0; i < 3; i++) {						
		if (game->board[2][i] == game->userChar) counter_user++;
		else if (game->board[2][i] == game->botChar) counter_bot++;
	}
	if (counter_bot == 2) {										
		for (int i = 0; i < 3; i++) {
			if (game->board[2][i] == ' ') {
				game->board[2][i] = game->botChar;
				return;
			}
		}
	}
	else if (counter_user == 2) {
		for (int i = 0; i < 3; i++) {
			if (game->board[2][i] == ' ') {
				game->board[2][i] = game->botChar;
				return;
			}
		}
	}
	counter_bot = 0;
	counter_user = 0;


	for (int i = 0; i < 3; i++) {						
		if (game->board[i][0] == game->userChar) counter_user++;
		else if (game->board[i][0] == game->botChar) counter_bot++;
	}
	if (counter_bot == 2) {										
		for (int i = 0; i < 3; i++) {
			if (game->board[i][0] == ' ') {
				game->board[i][0] = game->botChar;
				return;
			}
		}
	}
	else if (counter_user == 2) {
		for (int i = 0; i < 3; i++) {
			if (game->board[i][0] == ' ') {
				game->board[i][0] = game->botChar;
				return;
			}
		}
	}
	counter_bot = 0;
	counter_user = 0;


	for (int i = 0; i < 3; i++) {							
		if (game->board[i][1] == game->userChar) counter_user++;
		else if (game->board[i][1] == game->botChar) counter_bot++;
	}
	if (counter_bot == 2) {										
		for (int i = 0; i < 3; i++) {
			if (game->board[i][1] == ' ') {
				game->board[i][1] = game->botChar;
				return;
			}
		}
	}
	else if (counter_user == 2) {
		for (int i = 0; i < 3; i++) {
			if (game->board[i][1] == ' ') {
				game->board[i][1] = game->botChar;
				return;
			}
		}
	}
	counter_bot = 0;
	counter_user = 0;


	for (int i = 0; i < 3; i++) {							
		if (game->board[i][2] == game->userChar) counter_user++;
		else if (game->board[i][2] == game->botChar) counter_bot++;
	}
	if (counter_bot == 2) {										
		for (int i = 0; i < 3; i++) {
			if (game->board[i][2] == ' ') {
				game->board[i][2] = game->botChar;
				return;
			}
		}
	}
	else if (counter_user == 2) {
		for (int i = 0; i < 3; i++) {
			if (game->board[i][2] == ' ') {
				game->board[i][2] = game->botChar;
				return;
			}
		}
	}
	counter_bot = 0;
	counter_user = 0;

	srand(time(0));
	bool exit = false;
	while (!exit) {					// Если поставлен только один знак, то ход на рандом
		int x = rand() % 3;
		int y = rand() % 3;
		if (game->board[x][y] == ' ') {
			game->board[x][y] = game->botChar;
			exit = true;
			return;
		}
	}
}


void userTurn(Game* game) {
	int row, column;
	std::cout << "Ваш ход: ";
	std::cin >> row >> column;
	while (row < 1 || row > 3 || column < 1 || column > 3 || game->board[row - 1][column - 1] != ' ') {
		std::cout << "Неверные координаты" << std::endl;
		std::cout << "Ваш ход: ";
		std::cin >> row >> column;
	}
	game->board[row - 1][column - 1] = game->userChar;
}


void Winner(Game* game, int user, int bot) {
	if (user == 3)game->status = USER_WIN;
	else if (bot == 3)game->status = BOT_WIN;
}


bool updateGame(Game* game)
{
	int counter_segment = 0;
	int counter_user = 0;
	int counter_bot = 0;


	for (int i = 0; i < 3; i++) {								//Проверка строк
		counter_user = 0;
		counter_bot = 0;
		for (int k = 0; k < 3; k++) {
			if (game->board[i][k] == game->userChar) counter_user++;
			else if (game->board[i][k] == game->botChar) counter_bot++;
		}
		Winner(game, counter_user, counter_bot);
	}

	for (int i = 0; i < 3; i++) {								//Проверка столбцов
		counter_user = 0;
		counter_bot = 0;;
		for (int k = 0; k < 3; k++) {
			if (game->board[k][i] == game->userChar) counter_user++;
			else if (game->board[k][i] == game->botChar) counter_bot++;
		}
		Winner(game, counter_user, counter_bot);
	}
	
	counter_user = 0;
	counter_bot = 0;
	for (int i = 0; i < 3; i++) {								//Главная диагональ
		if (game->board[i][i] == game->userChar) counter_user++;
		else if (game->board[i][i] == game->botChar) counter_bot++;
	}
	Winner(game, counter_user, counter_bot);
	
	counter_user = 0;
	counter_bot = 0;
	for (int i = 0; i < 3; i++) {								//Побочная диагональ
		if (game->board[i][2 - i] == game->userChar) counter_user++;
		else if (game->board[i][2 - i] == game->botChar) counter_bot++;
	}
	Winner(game, counter_user, counter_bot);

	if (game->status == PLAY) {
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				if (game->board[i][k] == ' ')counter_segment++;
			}
		}
		if (!counter_segment) {
			game->status = NOT_WIN;
			return true;
		}
		game->isUserTurn = !game->isUserTurn;
		return false;
	}
	return true;
}

```


###### 4. Работа программы

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab4/img/img1.png" alt="Рис.1" width="600"/> <br/> Рис.1 Работа программы

***Вывод: Закрепить навыки работы с перечислениями, закрепил навыки работы с структурами, освоил методы составления многофайловых программ.***
