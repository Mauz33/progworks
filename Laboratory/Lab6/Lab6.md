МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
​
### Отчёт по лабораторной работе № 6 <br/> по дисциплине "Программирование"
<br/>
​
Студента 1 курса группы ПИ-б-о-191(1)<br/> 
Ещенко Максима Алексеевича <br/>
направления подготовки 09.03.04 "Программная инженерия"  
<br/>
​
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2020
<br/><br/>

#### Тема: Погодный информер

#### Цель: 
1. Закрепить навыки разработки многофайловыx приложений;
2. Изучить способы работы с API web-сервиса;
3. Изучить процесс сериализации/десериализации данных.

###### 1. Подключение httplib <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img1.png" alt="Рис.1" width="600"/> <br/> Рис.1 Путь к httplib

###### 2. Запуск сервера <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img2.png" alt="Рис.2" width="600"/> <br/> Рис.2 Код

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img3.png" alt="Рис.3" width="600"/> <br/> Рис.3 localhost:1234

###### 3. API <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img4.png" alt="Рис.4" width="600"/> <br/> Рис.4 API ключ

###### 4. Составление запроса <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img5.png" alt="Рис.5" width="600"/> <br/> Рис.5 Полученные данные по запросу

``` http://api.openweathermap.org/data/2.5/forecast?id=693805&appid=bd5e7136af20e8650e9cf52a7cf92fa3&mode=json&lang=en&units=metric``` Конечная ссылка. id-город, appid - API, mode - получить в формате JSON, lang - язык, units - единица измерения

###### 5. Получение данных <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img6.png" alt="Рис.6" width="600"/> <br/> Рис.6 Считывание данных по url

###### 6. Подключение nlohmann <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img7.png" alt="Рис.7" width="600"/> <br/> Рис.7 Подлючение библиотеки

###### 7. Парсинг с помощью библиотеки для работы с JSON <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img8.png" alt="Рис.8" width="600"/> <br/> Рис.8 Парсинг

###### 8. Шаблон <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img9.png" alt="Рис.9" width="600"/> <br/> Рис.9 Шаблон для работы

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img10.png" alt="Рис.10" width="600"/> <br/> Рис.10 Шаблон

###### 9. Итог <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab6/img/img11.png" alt="Рис.11" width="600"/> <br/> Рис.11 Результат работы


```cpp
#include <httplib/httplib.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace httplib;

std::string doubleToString(double digit) {
	std::stringstream sstr;
	sstr.precision(2);
	sstr << std::fixed << digit;
	return sstr.str();
}

bool replace(std::string& str, std::string orig, std::string repl) {
	int i = str.find(orig);
	if (i != -1) {
		str.replace(i, orig.length(), repl);
		return true;
	}
	return false;
}

// В этой функции формируем ответ сервера на запрос
void gen_response(const Request& req, Response& res) {
	char site[] = "api.openweathermap.org";
	char urlAPI[] = "/data/2.5/forecast?id=693805&appid=bd5e7136af20e8650e9cf52a7cf92fa3&mode=json&lang=en&units=metric";
	httplib::Client cli(site, 80);

	auto data = cli.Get(urlAPI);
	if (data && data->status == 200) {
		auto buffer = nlohmann::json::parse(data->body);

		std::ifstream file("Template.html");
		std::string cont = "", templ = "";

		std::string cityName = buffer["city"]["name"].get<std::string>();

		std::string lastDate;
		std::vector<std::string> dates;

		std::vector<std::string> icons;

		std::vector<std::string> temps;

		int iDates = 0, iIcons =  0, iTemps = 0 ;

		for (int i = 0; i < buffer["cnt"].get<int>(); i++) {
			std::string d = buffer["list"][i]["dt_txt"].get<std::string>();
			d = d.substr(0, d.find(" "));
			if (d != lastDate) {
				dates.push_back(d);
				icons.push_back(buffer["list"][i]["weather"][0]["icon"].get<std::string>());
				temps.push_back(doubleToString(buffer["list"][i]["main"]["temp"].get<double>()));
				lastDate = d;
			}
		}

		while (std::getline(file, cont)) {
			replace(cont, "{city.name}", cityName);
			if (replace(cont, "{list.dt}", dates[iDates])) iDates++;
			if (replace(cont, "{list.main.temp}", temps[iTemps])) iTemps++;
			if (replace(cont, "{list.weather.icon}", icons[iIcons])) iIcons++;
			
			
			templ += cont + '\n';
		}

		res.set_content(templ, "text/html");
	}
}

int main() {
	Server svr;                   
	svr.Get("/", gen_response);   
	svr.listen("localhost", 3000); 
}
```

Вывод: я закрепил навыки разработки многофайловыx приложений, изучил способы работы с API web-сервиса, изучил процесс сериализации/десериализации данных.
