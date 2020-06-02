МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
​
### Отчёт по лабораторной работе № 9 <br/> по дисциплине "Программирование"
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

#### Тема: Тестирование при помощи Google Test Framework

#### Цель: 
1. Познакомиться с Google Test и Google Mock Framework;
2. Изучить базовые понятия относящийся к тестированию кода;
3. Научиться тестировать классы в среде разработки Qt Creator.

###### 1. tst_testdevisionbyzero.h <br/>

```cpp
#ifndef TST_TESTDIVISIONBYZERO_H
#define TST_TESTDIVISIONBYZERO_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IKeypad.h>
#include <ILatch.h>
#include <lockcontroller.h>

using namespace testing;

struct MockIKeypad : IKeypad{
    MOCK_METHOD(bool, isActive, (), (override));
    MOCK_METHOD(void, wait, (), (override));
    MOCK_METHOD(PasswordResponse, requestPassword, (), (override));
};

struct MockILatch: ILatch{
    MOCK_METHOD(bool, isActive, (), (override));
    MOCK_METHOD(DoorStatus, open, (), (override));
    MOCK_METHOD(DoorStatus, close, (), (override));
    MOCK_METHOD(DoorStatus, getDoorStatus, (), (override));
};

class FixtureLockController : public testing::Test{
public:
    LockController* lctrl;
    MockIKeypad IKeypad;
    MockILatch ILatch;
    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override{
        lctrl = new LockController(&IKeypad, &ILatch);
    }
    void TearDown() override{
        delete lctrl;
    }
};


TEST_F(FixtureLockController, OnceWait){
    EXPECT_CALL(IKeypad, wait).Times(1);
    lctrl->wait();
}

TEST_F(FixtureLockController, Closed_isDoorOpen){
    EXPECT_CALL(ILatch, getDoorStatus).Times(1).WillOnce(Return(DoorStatus::CLOSE));
    bool rtrn = lctrl->isDoorOpen();
    EXPECT_FALSE(rtrn);
}

TEST_F(FixtureLockController, Opened_isDoorOpen){
    EXPECT_CALL(ILatch, getDoorStatus).Times(1).WillOnce(Return(DoorStatus::OPEN));
    bool rtrn = lctrl->isDoorOpen();
    EXPECT_TRUE(rtrn);
}

TEST_F(FixtureLockController, UnlockDoor){
    EXPECT_CALL(ILatch, open).Times(1).WillOnce(Return(DoorStatus::OPEN));
    DoorStatus rtrn = lctrl->unlockDoor();
    EXPECT_EQ(rtrn, DoorStatus::OPEN);
}

TEST_F(FixtureLockController, CloseDoor){
    EXPECT_CALL(ILatch, close).Times(1).WillOnce(Return(DoorStatus::CLOSE));
    DoorStatus rtrn = lctrl->lockDoor();
    EXPECT_EQ(rtrn, DoorStatus::CLOSE);
}

TEST_F(FixtureLockController, HardWareOK){
    EXPECT_CALL(IKeypad, isActive).Times(1).WillOnce(Return(true));
    EXPECT_CALL(ILatch, isActive).Times(1).WillOnce(Return(true));
    HardWareStatus rtrn = lctrl->hardWareCheck();
    EXPECT_EQ(rtrn, HardWareStatus::OK);
}

TEST_F(FixtureLockController, HardWareERROR){
    delete lctrl;
    lctrl = new LockController(nullptr, &ILatch);
    EXPECT_CALL(IKeypad, isActive).Times(AtLeast(0)).WillOnce(Return(true));
    EXPECT_CALL(ILatch, isActive).Times(AtLeast(0)).WillOnce(Return(true));
    HardWareStatus rtrn = lctrl->hardWareCheck();
    EXPECT_EQ(rtrn, HardWareStatus::ERROR);
}

TEST_F(FixtureLockController, KeypadOK_LatchERROR){
    EXPECT_CALL(IKeypad, isActive).Times(AtLeast(0)).WillOnce(Return(true));
    EXPECT_CALL(ILatch, isActive).Times(AtLeast(0)).WillOnce(Return(false));
    HardWareStatus rtrn = lctrl->hardWareCheck();
    EXPECT_EQ(rtrn, HardWareStatus::ERROR);
}

TEST_F(FixtureLockController, PasswordOK){
    PasswordResponse pswrd;
    pswrd.password = "0000";
    pswrd.status = PasswordResponse::Status::OK;
    EXPECT_CALL(IKeypad, requestPassword).Times(1).WillOnce(Return(pswrd));
    bool rtrn = lctrl->isCorrectPassword();
    EXPECT_TRUE(rtrn);
}

TEST_F(FixtureLockController, PasswordERROR){
    PasswordResponse pswrd;
    pswrd.password = "7355608";
    pswrd.status = PasswordResponse::Status::OK;
    EXPECT_CALL(IKeypad, requestPassword).Times(1).WillOnce(Return(pswrd));
    bool rtrn = lctrl->isCorrectPassword();
    EXPECT_FALSE(rtrn);
}

TEST_F(FixtureLockController, PasswordResetOK){
    PasswordResponse pswrd1;
    PasswordResponse pswrd2;
    PasswordResponse pswrd3;

    pswrd1.status = PasswordResponse::Status::OK;
    pswrd2.status = PasswordResponse::Status::OK;
    pswrd3.status = PasswordResponse::Status::OK;

    pswrd1.password = "0000";
    pswrd2.password = "7355608";
    pswrd3.password = "7355608";

    EXPECT_CALL(IKeypad, requestPassword).Times(3).WillOnce(Return(pswrd1)).WillOnce(Return(pswrd2)).WillOnce(Return(pswrd3));
    lctrl->resetPassword();

    bool rtrn = lctrl->isCorrectPassword();
    EXPECT_TRUE(rtrn);
}

TEST_F(FixtureLockController, FewPasswordResetOK){
    PasswordResponse pswrd1;
    PasswordResponse pswrd2;
    PasswordResponse pswrd3;
    PasswordResponse pswrd4;
    PasswordResponse pswrd5;

    pswrd1.status = PasswordResponse::Status::OK;
    pswrd2.status = PasswordResponse::Status::OK;
    pswrd3.status = PasswordResponse::Status::OK;
    pswrd4.status = PasswordResponse::Status::OK;
    pswrd5.status = PasswordResponse::Status::OK;

    pswrd1.password = "0000";
    pswrd2.password = "9876";
    pswrd3.password = "9876";
    pswrd4.password = "1010";
    pswrd5.password = "1010";

    EXPECT_CALL(IKeypad, requestPassword).Times(5).WillOnce(Return(pswrd1)).WillOnce(Return(pswrd2)).WillOnce(Return(pswrd3)).WillOnce(Return(pswrd4)).WillOnce(Return(pswrd4));
    lctrl->resetPassword();
    lctrl->resetPassword();

    bool rtrn = lctrl->isCorrectPassword();
    EXPECT_TRUE(rtrn);
}

#endif // TST_TESTDIVISIONBYZERO_H
```
###### 2. Результаты тестов <br/>

<img src="https://raw.githubusercontent.com/Mauz33/progworks/master/Laboratory/Lab9/img/img1.png" alt="Рис.1" width="1000"/> <br/> Рис.1 Результаты тестов

###### 3. Устранение ошибки <br/>

Код с ошибкой <br/>
```cpp
DoorStatus LockController::lockDoor()
{
    return latch->open();
}
```
<br/>

Исправленный код <br/>
```cpp
DoorStatus LockController::lockDoor()
{
    return latch->close();
}
```
<br/>
Данная ошибку можно было допустить из-за невнимательности. Чтобы не писать заного метод, его просто скопировали, но забыли исправить.

**Вывод: Я познакомился с Google Test и Google Mock Framework, изучил базовые понятия относящийся к тестированию кода, научитлся тестировать классы в среде разработки Qt Creator.
