#include <iostream>
using namespace std;

void factorization(int n);

int main()
{
		int a;
		setlocale(LC_ALL, "ru");
		cin >> a;
		factorization(a);
		cout << endl;
}

void factorization(int n)
{
	setlocale(LC_ALL, "ru");
	int i = 0, j;
	if (n == 1) {
		cout << "-";
	}
	else if (n < 1) {
		cout << "Ошибка";
	}
	else {
		for (j = 2; j <= n; j++) {
			while (n % j == 0) {
				n = n / j;
				i++;
			}
			if (i > 1) {
				cout << j << "^" << i;
				if (n != 1) {
					cout << "*";
				}
			}
			else if (i == 1) {
				cout << j;
				if (n != 1) {
					cout << "*";
				}
			}
			i = 0;
		}
	}
}