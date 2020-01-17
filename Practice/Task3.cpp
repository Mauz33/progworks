#include <iostream>

#define result(x, y) std::cout << x + y << ' ' << x - y << ' ' << x * y << ' ' << x / y << '\n'

int main() {
	void task3() {
    int int1, int2;
    std::cin >> int1 >> int2;
    result(int1, int2);

    double double1, double2;
    std::cin >> double1 >> double2;
    result(double1, double2);

    int int21;
    double double21;
    std::cin >> int21 >> double21;
    result(int21, double21);

    double double31;
    int int31;
    std::cin >> double31 >> int31;
    result(double31, int31);
}
}
