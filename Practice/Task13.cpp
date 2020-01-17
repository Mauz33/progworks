#include <iostream>
using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");
	int digit, k = 0, ans = 1; // digit - число, k - счетчик степени, ans - ответ
	cin >> digit;
	while (ans < digit) { // Выполняет до тех пор, пока число, которое мы считаем, меньше того числа, которое мы ввели
		ans = ans * 2;			// Например digit = 33. ans = 1 * 2 = 2        
		k++;				// ans = 1 * 2 = 2.  k=1 2<33
						// ans = 2 * 2 = 4.  k=2 4<33
						// ans = 4 * 2 = 8.  k=3 8<33
						// ans = 8 * 2 = 16. k=4 16<33
						// ans = 16 * 2 = 32. k=5 32<33
						// ans = 32 * 2 = 64  k=6 64>33. Цикл окончен. Ответ: 6
	}
	cout << k;
}

