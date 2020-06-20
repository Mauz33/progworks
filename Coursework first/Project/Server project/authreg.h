#ifndef AUTHREG_H
#define AUTHREG_H

#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTextStream>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QString>
#include <server.h>

QJsonDocument loadJson(QString fileName); // Загрузка данных из json файла

void saveJson(QJsonDocument document); // Сохранение данных в json файл

bool authorization(QString login, QString password, QTcpSocket* socket); // Авторизация

void registration(QString login, QString password, QTcpSocket* socket); // Регистрация
#endif // AUTHREG_H
