МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
​
### Отчёт по лабораторной работе № 4 <br/> по дисциплине "Программирование"
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

#### Тема: Настройка Qt Creator для разработки приложений под android

#### Цель: 
1. Настроить IDE Qt Creator для разработки приложений под android ОС;
2. Изучить базовые понятия связанные с мобильной разработкой;
3. Научиться создавать мобильные приложения при помощи фреймворка Qt 5.14.

###### 1. Установка предварительно собранных компонент фреймворка Qt 5.14 для android <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img1.png" alt="Рис.1" width="600"/> <br/> Рис.1 Qt Maintenance Tool

Скачивание компонента ***Android***

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img2.png" alt="Рис.2" width="600"/> <br/> Рис.2 Обновление компонентов QT

###### 2. Установка JDK 8 <br/>

Проверка версии JDK

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img3.png" alt="Рис.3" width="600"/> <br/> Рис.3 Версия JDK

###### 3. Установка Android Studio

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img4.png" alt="Рис.4" width="600"/> <br/> Рис.4 Установка

После установки открылось данное окно, где предлагается установить/обновить компоненты для работы программы.

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img5.png" alt="Рис.5" width="600"/> <br/> Рис.5 Установка компонентов

Переходим в ***SDK MANAGER***

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img6.png" alt="Рис.6" width="600"/> <br/> Рис.6 Вкладка SDK Platforms

Далее переходим во вкладку ***SDK TOOLS***, cнимаем галочку ***HIDE OBSOLETE PACKAGES*** и отмечаем галочкой нужные нам компоненты. 

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img7.png" alt="Рис.7" width="600"/> <br/> Рис.7 Вкладка SDK Tools

Ставим галочку на ***SHOW PACKAGE DETAILS*** и выбираем нужные версии ***Android SDK Build-Tools 30-rc1*** и ***NDK (Side by side)***

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img8.png" alt="Рис.8" width="600"/> <br/> Рис.8 Выбор версии Android SDK Build-Tools 30-rc1

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img9.png" alt="Рис.9" width="600"/> <br/> Рис.9 Выбор версии NDK (Side by side)

###### 4. Настройка Qt Creator

Указываем пути JDK, SDK, NDK.

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img10.png" alt="Рис.10" width="600"/> <br/> Рис.10 Настройка во вкладке Android

Галочки стоят везде, значит настройка проведена корректно.

###### 4. Запуск проекта

Выбор проекта из общего списка

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img11.png" alt="Рис.11" width="600"/> <br/> Рис.11 Проект


Подключение смартфона к ПК

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img12.png" alt="Рис.12" width="600"/> <br/> Рис.12 Режим разработчика

Поиск совместимых устройств

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img13.png" alt="Рис.12" width="600"/> <br/> Рис.13 Совместимые устройства

Запуск приложения

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img14.png" alt="Рис.12" width="600"/> <br/> Рис.14 Приложение готово к запуску

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab8/img/img15.png" alt="Рис.12" width="600"/> <br/> Рис.15 Запущенное приложение



***Вывод: Я настроио IDE Qt Creator для разработки приложений под android ОС, изучил базовые понятия связанные с мобильной разработкой, научился создавать мобильные приложения при помощи фреймворка Qt 5.14.***
