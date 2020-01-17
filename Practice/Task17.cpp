#include <iostream>
using namespace std;

// Возвращает индекс массы тела.  
double BMI(double weight, double height) {
	double BMI = weight / (height * height);
	return BMI;
}
// Принимает численное значение ИМТ и печатает на экран соответствующую категорию
void printBMI(double BMI) {
	if (BMI < 18.5)cout << "Underweight";
	else if ((BMI > 18.5 && BMI < 25.0) || abs(BMI-18.5)< 1e-7) cout << "Normal weight";
	else if ((BMI > 25.0 && BMI < 30.0 ) || abs(BMI - 25.0) < 1e-7 ) cout << "Overweight";
	else cout << "Obesity";
}



int main() {
	double h, m;
	cin >> m >> h;
	h=h/100.0;
	printBMI(BMI(m, h));
}