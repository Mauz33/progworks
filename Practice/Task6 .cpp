#include <iostream>
#include <iomanip> // Для управления выводом
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    // Настроим вывод 4х знаков после точки
    cout << fixed;
    cout << setprecision(4);

    double a, b, c, x1, x2, D;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0)
        cout << "х принимает любое значение" << endl;
	else if (a == 0 && b == 0 && c != 0) {
        cout << "Уравнение не существует" << endl;
    }
    else if (a == 0 && b != 0 && c != 0) {
        x1 = (-c) / b;
        cout << "x = " << x1 << endl;
    }
    else if (a == 0 && b != 0 && c == 0)
        cout << "x = 0" << endl
    else if (a != 0 && b == 0 && c == 0)
        cout << "x = 0" << endl;
    else {
        D = b * b - 4 * a * c;
        if (D < 0) {
            cout << "Дейсвительных корней нет" << endl
        }
        else if (D == 0) {
            x1 = -b / (2 * a);
            cout << "x = " << x1 << endl;
        }
        else {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
}
