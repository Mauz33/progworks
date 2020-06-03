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


