#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ans = ans * i;
	}
	cout << "Ответ: " << ans;



}













//Второй способ
//#include <iostream>
//using namespace std;
//
//int F(int n)
//{
//	if (n < 0)
//		return 0;
//	if (n == 0)
//		return 1;
//	else // Во всех остальных случаях
//		return n * F(n - 1); // делаем рекурсию.
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	int n;
//	cout << "Введите число: ";
//	cin >> n;
//	cout << "Факториал " << n << " = " << F(n);
//	return 0;
//}