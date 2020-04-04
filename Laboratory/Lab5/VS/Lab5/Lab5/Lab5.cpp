#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	struct train {
		int passengerId;
		bool survival;
		int pclass;
		string name;
		string sex;
		double age;
		int sibsp;
		int parch;
		string ticket;
		double fare;
		string cabin;
		char embarked;
	};

	string path = "train.csv";
	ifstream fin;
	fin.open(path);
	
	int numoflines = -1; // -1, т.к. первая строка информирующая и нам не нужна для счета
	string str;

	while (!fin.eof()) {		// Подсчет кол-ва строк
		getline(fin, str, '\r');
		numoflines++;
	}

	fin.seekg(80);				//fin.eof в данный момент true, т.к. дошел до конца документа, поэтому переходим в начало документа на вторую строку

	string* arr = new string[numoflines];	// Создаем  массив строк
	train* arrTrain = new train[numoflines];

	int i = 0;
	while (!fin.eof()) {
		getline(fin, arr[i], '\r');		// Заносим строки в массив
		int pos = 0;					// Позиция 
		int l = arr[i].length();		// Длина строки
		bool replace = true;			// Перменная для замены , на |
		while (pos < l) {				// Заменяем , на | , кроме , ,которые в " "
			if (arr[i][pos] == '"') replace = !replace;
			if (replace) {
				if (arr[i][pos] == ',') arr[i][pos] = '|';
			}
			pos++;
		}

		string split;
		stringstream stream(arr[i]);		//Переводим строки с инофрмацией в поток
		getline(stream, split, '|');		//Считываем строку до разделителя | и помещаем в строку stream

		int step = 0;
		while (stream) {
			stringstream info(split);
			switch (step) { 
			case 0: info >> arrTrain[i].passengerId;
				break;
			case 1: info >> arrTrain[i].survival;
				break;
			case 2: info >> arrTrain[i].pclass;
				break;
			case 3: getline(info, arrTrain[i].name);
				break;
			case 4: info >> arrTrain[i].sex;
				break;
			case 5: info >> arrTrain[i].age;
				break;
			case 6: info >> arrTrain[i].sibsp;
				break;
			case 7: info >> arrTrain[i].parch;
				break;
			case 8: getline(info, arrTrain[i].ticket);
				break;
			case 9: info >> arrTrain[i].fare;
				break;
			case 10: info >> arrTrain[i].cabin;
				break;
			case 11: info >> arrTrain[i].embarked;
				break;
			}
			step++;

			getline(stream, split, '|');
		}
		i++;
	}

	int survived = 0, first = 0, second = 0, third=0, femaleSurv=0, maleSurv=0, avrgCount = 0, avrgCount_fem = 0, avrgCount_male = 0, underAge_count = 0, embS = 0, embQ = 0, embC = 0;
	double avrgAge = 0, avrg_femAge = 0, avrg_maleAge = 0;
	string stPopulation;
	vector<int> underAgeID;

	for (int i = 0; i < numoflines; i++) {
		if (arrTrain[i].survival) {
			survived++;
			if (arrTrain[i].pclass == 1) first++;		//Первый класс
			else if (arrTrain[i].pclass == 2) second++;	//Второй класс
			else if (arrTrain[i].pclass == 3) third++;	//Третий класс
			if (arrTrain[i].sex == "female") femaleSurv++;	//Выжившие женского пола
			if (arrTrain[i].sex == "male") maleSurv++;		//Выжившие мужского пола
		}

		if (arrTrain[i].age > 0) {
			if (arrTrain[i].age < 18) underAgeID.push_back(arrTrain[i].passengerId);	// Занесение id тех, кому меньше 18 лет

			avrgAge += arrTrain[i].age;					// Сумма возрастов пассажиров
			avrgCount++;								// Кол-во пассажиров, у которых указн возраст
			if (arrTrain[i].sex == "female") {			
				avrg_femAge += arrTrain[i].age;			// Сумма возрастов пассажиров женского пола
				avrgCount_fem++;						// Кол-во пассажиров женского пола, у которых укаазн возраст
			}
			else if (arrTrain[i].sex == "male") {			
					avrg_maleAge += arrTrain[i].age;	// Сумма возрастов пассажиров мужского пола
					avrgCount_male++;					// Кол-во пассажиров мужского пола, у которых указан возраст
			}

			if (arrTrain[i].embarked == 'S') embS++;
			else if (arrTrain[i].embarked == 'Q') embQ++;
			else if (arrTrain[i].embarked == 'C') embC++;
		}
	}

	avrgAge = avrgAge / (double)avrgCount;	// Средний возраст пасажиров
	avrg_femAge = avrg_femAge / (double)avrgCount_fem; // Средний возраст пасажиров женского пола
	avrg_maleAge = avrg_maleAge / (double)avrgCount_male; // Средний возраст пасажиров мужского пола

	if (embC > embQ && embC > embS) stPopulation = "Cherbourg";			// Поиск штата с наибольшим населением
	else if (embQ > embC && embQ > embS) stPopulation = "Queenstown";
	else if (embS > embC && embS > embQ) stPopulation = "Southampton";
	
	ofstream output("sort.txt");										// Объект класса ofstream для вывода в файл

	output << "Общее число выживших: " << survived << std::endl;
	output << "Выживших из первого класса: " << first << std::endl;
	output << "Выживших из второго класса: " << second << std::endl;
	output << "Выживших их третьего класса: " << third << std::endl;
	output << "Выживших женщин: " << femaleSurv << std::endl;
	output << "Выживших мужчин: " << maleSurv << std::endl;
	cout << fixed;
	cout.precision(1);
	output << "Средний возраст всех пассажиров: " << avrgAge << std::endl;
	output << "Средний возраст женщин: " << avrg_femAge << std::endl;
	output << "Средний возраст мужчин: " << avrg_maleAge << std::endl;
	output << "Штат, в котором село больше всего пассажиров: " << stPopulation << std::endl;
	output << "Список идентификаторов несовершеннолетних пассажиров: " << underAgeID[0];

	for (int i = 1; i < underAgeID.size(); i++) {		// Вывод id тех, кому меньше 18
		output << ", "<< underAgeID[i];
	}


	fin.close();
}


