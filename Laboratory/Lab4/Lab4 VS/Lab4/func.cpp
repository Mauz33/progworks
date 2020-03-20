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
