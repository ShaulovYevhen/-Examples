#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Student
{
private: //поля 
	char* name;
	int year;
public:
	Student(const char* name, int year);//конструктор класа
	Student();//конструктор по умролчанию
	Student(const Student&odj);//конструктор копирования принимает константную ссылку(lvalue) на обьект своего типа
	Student(Student&& odj)noexcept;// конструктор перемещения который принимает ссылку rvalue
	~Student();//деструктор
	int getYear()const;//геттер для возвращения значений
	void setYear(int val);//сеттер для установки и проверки значений 
	const char* getName()const;
	void setName(const char* val);
	void Show()const;
};

