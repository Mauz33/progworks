#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	double digit, ans = 1;
	int pow;
	cin >> digit >> pow;
	int Pow = pow;
	while (pow != 0) {
		ans = ans * digit;
		pow=abs(pow)-1;
	}
	if (Pow > 0) {
		cout << "Ответ: " << ans;
	}
	else if (Pow < 0 && digit == 0) {
		cout << "Неопределенно";
	}
	else if (Pow < 0) {
		cout << "Ответ: " << 1.0/ans;
	}
	else if (Pow == 0) {
		ans = 1;
		cout << "Ответ: " << ans ;
	}
	
	
}
