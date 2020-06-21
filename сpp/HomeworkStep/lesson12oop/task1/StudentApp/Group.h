//Группа:
//	Поля:
//		Факультет;
//		Курс;
//		Количество студентов;
//		Студенты.
//	Методы:
//		Добавление студента в группу;
//		Удаление студента из группы(по позиции);
//		Вывод на экран всех студентов;

#pragma once
#include "Student.h"

class Group
{
private:
	char* faculty;
	int cource; 
	int size=0;
	Student *arr=nullptr;
public:
	Group(const char* f, const int c);
	Group();
	Group(const Group& obj);
	Group(Group&&obj)noexcept;
	~Group();
	const char* getFaculty()const;
	const int getCource()const;
	int getSize()const;
	void setFaculty(const char*val);
	void setCource(const int val);
	void Show()const;
	void AddStudent(const Student&obj);
	void DelStudent(int poz);
};

