#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	const int line = 10, column = 8;
	int array[line][column] = { };
	srand(time(0));
	int randLine = rand() % line, randColumn = rand() % column;
	array[randLine][randColumn] = 1;
	int chance = 5;

	while (chance) {
		int lineW, columnW;
		cin >> lineW >> columnW;
		if (lineW > 10 || columnW > 8 || lineW < 1 || columnW < 1) {
			cout << "Выход за предел массива" << endl;
			continue;
		}

		if (array[lineW][columnW] == 1) {
			cout << "Вы угадали\n";
			return 0;
		}
		else if (array[lineW][columnW] == 0) {
			cout << "Нет" << endl;
			chance--;
		}
		else {
			cout << "Эту уже проверяли" << endl;
		}
		array[lineW][columnW]--;
	}
}