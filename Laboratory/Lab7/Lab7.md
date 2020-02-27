МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
​
### Отчёт по лабораторной работе № 7 <br/> по дисциплине "Программирование"
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

#### Тема: Изучение базовых возможностей IDE Qt Creator

#### Цель: изучить основные возможности создания и отладки программ в IDE Qt Creator.

###### 1. Как создать консольное приложение С++ в IDE Qt Creator без использования компонентов Qt?<br/>
Для того, чтобы создать консольное приложение С++ нужно:
* Из списка шаблонов выбрать "Проект без QT"

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img1.png" alt="Рис.1" width="600"/> <br/>Рис.1 Создание проекта без Qt
* Выберите консольное приложение , а затем выберите Далее.

###### 2. Как изменить цветовую схему (оформление) среды?
Для того, чтобы изменить цветовую схему (оформление) среды нужно:

* Перейти во вкладку Параметры --> Среда

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img3.png" alt="Рис.2" width="600"/> <br/> Рис.2 Переход в раздел Параметры

###### 3. Как закомментировать/раскомментировать блок кода средствами QT?
Для того, чтобы закомментировать/раскомментировать блок кода средствами QT нужно:

* Выделить блок кода и использовать сочетание клавиш:
1.Ctrl + / — закомментировать/раскомментировать блок кода;

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img4.png" alt="Рис.3" width="600"/> <br/> Рис.3 Сочетание клавишь, чтобы закомментировать блок кода

###### 4. Как открыть в проводнике Windows папку с проектом средствами QT?
Для того, чтобы открыть в проводнике Windows папку с проектом средствами QT нужно:

* Нажать ПКМ по проекту и нажать *Открыть папку в проводнике*

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img5.png" alt="Рис.5" width="600"/> <br/> Рис.4 Открытие папки с проектом в проводнике


###### 5. Какое расширение файла-проекта используется в QT?

PRO - расширение файла-проекта используется в QT

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img6.png" alt="Рис.6" width="600"/> <br/> Рис.5 Расширение файла-проекта

###### 6.Как запустить код без отладки?
Для того, чтобы запустить код без отладки нужно:
* С помощью сочетания клавишь ctrl+r

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img7.png" alt="Рис.7" width="600"/> <br/> Рис.6 Запуск без откладки

###### 7. Как запустить код в режиме отладки 
Для того, чтобы запустить код в отладке нужно:
* перейти во вкладку *Откладка* и нажать *Начать откладку*

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img8.png" alt="Рис.8" width="600"/> <br/> Рис.7 Запуск с откладкой

###### 8.Как установить/убрать точку останова (breakpoint)?
Для того, чтобы запустить код без отладки нужно:
* Перед номером строки, где его нужно поставить, нужно нажать ЛКМ и появится красный кружочек

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img9.png" alt="Рис.9" width="600"/> <br/> Рис.8 Точка останова (breakpoint)

###### 9.Создайте программу со следующим кодом.
```cpp
#include <iostream>
int main() {
    int i;
    double d;
    i = 5;
    d = 5;
    std::cout << i << d;
    return 0;
}
```
* Переключитесь в конфигурацию сборки Откладка

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img12.png" alt="Рис.12" width="600"/> <br/> Рис.9 Конфигурация сборки Откладка

* Установите breakpoint на 5, 6, 7 строках

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img13.png" alt="Рис.13" width="600"/> <br/> Рис.10 Breakpoint

* Запустите приложение щелкнув по кнопке с изображением жука.

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img14.png" alt="Рис.14" width="600"/> <br/> Рис.11 Запуск кода в откладке

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img15.png" alt="Рис.15" width="600"/> <br/> Рис.11 Запуск кода в откладке

* Какое значение содержит переменная i в 5й строке?

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img16.png" alt="Рис.16" width="600"/> <br/> Рис.12 Значение  переменной i в 5й строке

* Какое значение содержит переменная d в 6й строке?

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img17.png" alt="Рис.17" width="600"/> <br/> Рис.13 Значение  переменной d в 6й строке

* Какое значение содержит переменная i и d в 7й строке?

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img18.png" alt="Рис.18" width="600"/> <br/> Рис.14 Значение  переменной i и d в 7й строке

* Совпадают ли эти значения с теми, что вы получали в MSVS для соответствующих типов? Ответ: Нет


###### 10. Закройте проект и перейдите на вкладку «Начало» => «Примеры»:

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img19.png" alt="Рис.19" width="600"/> <br/> Рис.19 Закрытие проекта

###### 11. Выберите проект «Calculator Form Example». Для этого можно воспользоваться строкой поиска.

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img20.png" alt="Рис.20" width="600"/> <br/> Рис.20 Поиск

###### 12. Изучите (по желанию) описание проекта в открывшемся окне.

###### 13. Сейчас вы находитесь на вкладке «Проекты». Выберите комплект сборки.

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img21.png" alt="Рис.22" width="600"/> <br/> Рис.21 Выбор сборки


###### 14. Перейдите на вкладку «Редактор» и запустите сборку проекта.

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img22.png" alt="Рис.23" width="600"/> <br/> Рис.22 Сборка и запуск

###### 15. В инспекторе проекта выберите файл «main.cpp». В этом файле установите курсор на слово «show» в строке calculator.show(); и нажмите F1. Изучите справочную информацию. Таким же образом можно получить справку по любому объекту/методу/полю доступному в Qt.

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img23.png" alt="Рис.24" width="600"/> <br/> Рис.23 Документация

###### 16. В инспекторе проекта выберите файл «Формы» => «calculatorform.ui» и дважды счёлкните ЛКМ.
<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img24.png" alt="Рис.25" width="600"/> <br/> Рис.24 Форма


###### 17. Вы попали на вкладку «Дизайн». На форме замените английский текст на русский. Пересоберите проект.

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab7/img/img25.png" alt="Рис.25" width="600"/> <br/> Рис.25 Замена eng на rus

***Вывод: Я изучил основные возможности создания и отладки программ в QT***
