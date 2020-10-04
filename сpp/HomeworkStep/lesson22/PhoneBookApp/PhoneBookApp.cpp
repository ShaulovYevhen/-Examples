//Создать класс «Телефонный справочник», хранящий информацию о
//контактах со следующими полями :
//− id; − имя;
//− фамилия;
//− адрес;
//− номер телефона.
//Реализовать следующие возможности :
//− добавление записи;
//− удаление записи;
//− сохранение в файл(перезапись);
//− загрузка из файла.

#include <iostream>
#include "Input_.h"
#include "PhoneBook.h"
#include <fstream>


int main()
{
	Input_ myInput;
	string d;
	Phone ph, pq;
	PhoneBook pb, ps;
	pb.addPhone(new Phone());
	pb.addPhone(new Phone("Petrov", "Pretro","Kyiv","380666096051","qaq123"));
	pb.addPhone(new Phone("Firre", "Preq", "NSF", "380666094343", "qaqw1"));
	pb.addPhone(new Phone("ASDas", "qweqwo", "GLA", "380666094545", "qaq13"));
	pb.show();
	pb.getPhone(1).show();
	pb.getPhone(1).saveBinary("2.txt");
	pq.openBinary("2.txt");
	pb.getPhone(1).save("3.txt");
	pq.open("3.txt");
	pq.show();
	pb.saveBinary("4.txt");
	pq.openBinary("4.txt");
	pb.save("5.txt");
	pq.open("5.txt");
	pq.show();
}


