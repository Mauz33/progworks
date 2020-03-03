МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
​
### Отчёт по лабораторной работе № 3 <br/> по дисциплине "Программирование"
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

Симферополь, 2019
<br/><br/>

#### Тема: Дешифровка текста из изображения

#### Цель работы:
  1. Закрепить навыки разработки программ использующих операторы цикла;
  2. Закрепить навыки разработки программ использующих массивы;
  3. Освоить методы подключения сторонних библиотек.

#### Ход рыботы

#### Рисунок для декодирования
<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab3/img/pic3.bmp" alt="Рис.1" width="250"/> <br/> Рис.1 Рисунок для декодирования

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab3/img/img2.png" alt="Рис.2" width="250"/> <br/> Рис. 2. Ключ

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab3/img/img3.png" alt="Рис.3" width="250"/> <br/> Рис. 3. Создание папки include c файлом "libbmp.h"

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab3/img/img4.png" alt="Рис.4" width="250"/> <br/> Рис. 4. Подключение заголовочного файла

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab3/img/img5.png" alt="Рис.5" width="250"/> <br/> Рис. 5. Создание cpp файла в исходных файлах "libbmp.cpp" и подключение библиотеки

#### Код программы с декодированием изображения:

```c++
#include <iostream>
#include "libbmp.h"

int main()
{
	BmpImg image;
	image.read("pic3.bmp");
	
	int width = image.get_width();
	int height = image.get_height();
	char text[5000];
	char shift = 0;
	int position = 0;
	int counter = 0;
	int pixel;
	bool stop = false;

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			pixel = image.red_at(x, y);
			shift = shift << 1;			// 00000000
			if (pixel % 2 != 0) shift++;
			counter++;
			if (counter == 8) {
				text[position] = shift;
				position++;
				counter = 0;
				if (shift == '\0') {
					stop = true;
					break;
				}
			}

			pixel = image.green_at(x, y);
			shift = shift << 1;
			if (pixel % 2 != 0) shift++;
			counter++;
			if (counter == 8) {
				text[position] = shift;
				position++;
				counter = 0;
				if (shift == '\0') {
					stop = true;
					break;
				}
			}

			pixel = image.blue_at(x, y);
			shift = shift << 1;	
			if (pixel % 2 != 0) shift++;
			counter++;
			if (counter == 8) {
				text[position] = shift;
				position++;
				counter = 0;
				if (shift == '\0') {
					stop = true;
					break;
				}
			}
		}
		if (stop) break;
	}
	std::cout << text;
}
```

#### Результат:

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab3/img/img6.png" alt="Рис.6" width="250"/> <br/> Рис. 6. Результат работы кода


#### Вывод: я закрепил навыки разработки программ использующих операторы цикла, массивы и освоил методы подключения сторонних библиотек.
