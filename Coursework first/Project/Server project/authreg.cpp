#include <authreg.h>

// Загрузка Json
QJsonDocument loadJson(QString fileName){
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}

//Сохранение Json в файл
void saveJson(QJsonDocument document, QString fileName){
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}


// Авторизация
bool authorization(QString login, QString password, QTcpSocket* socket)
{
    QByteArray QBpassword;
    // Хэширование
    QString passwordHash = QCryptographicHash::hash(QBpassword.append(password), QCryptographicHash::Sha256).toHex();

    //Получение данных файла
    QJsonDocument json;
    json = loadJson("auth.json");
    QJsonObject jsondoc = json.object();

    // Получение массива с пользователями
    QJsonValue v1 = jsondoc.value("users");
    QJsonArray arr = v1.toArray();

    // Перебор блоков с логинами и паролями, затем сравнение их с параметрами, переданными в функцию
    for(int i = 0; i < arr.size(); i++){
        if(login == arr[i].toObject().value("login").toString() && passwordHash == arr[i].toObject().value("password").toString()){
            socket->write("Authorized");
            return true;
        }
    }
    return false;
}


// Регистрация
void registration(QString login, QString password, QTcpSocket* socket)
{
    QByteArray QBpassword;

    // Хэширование
    QString passwordHash = QCryptographicHash::hash(QBpassword.append(password), QCryptographicHash::Sha256).toHex();

    // Получение данных файла
    QJsonDocument json = loadJson("auth.json");
    QJsonObject jsondoc = json.object();

    // Получение массива пользователей
    QJsonValue jval = jsondoc.value("users");
    QJsonArray arr = jval.toArray();

    // Проверка на уже существующего пользователя
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].toObject().value("login").toString() == login){
            socket->write("AlredyExist"); // Отправка информации о том, что пользователь уже существует
            return;
        }
    }

    // Создание блока логин и пароль
    QJsonObject insertJson = QJsonObject(
    {
    qMakePair(QString("login"), QJsonValue(login)),
    qMakePair(QString("password"), QJsonValue(passwordHash)),
    });

    //Занесение блока в конец
    arr.push_back(QJsonValue(insertJson));
    jsondoc.insert(QString("users"), QJsonValue(arr));

    // Конвертирование в документ
    QJsonDocument doc(jsondoc);

    // Сохранение и отправка информации о успешной регистрации
    saveJson(doc, "auth.json");
    socket->write("RegSuccessful");
}

