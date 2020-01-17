
#include <iostream>

int main() {
	setlocale(LC_ALL, "RUSSIAN");

	int a, b;
    	std::cin >> a >> b;
	
    	std::cout << "До: " << a << b << '\n';

    	std::swap(a, b);

    	std::cout << "После: " << a << b << '\n';
    	std::cout << "До: " << a << b << '\n';

   	a = a + b;
   	b = a - b;
    	a = a - b;

    	std::cout << "После: " << a << b << '\n';
	return 0;
}