--create database Hospital
--go
--use Hospital

--create table Departments
--(
--ID int identity(1,1) not null primary key,
--Building int not null CHECK(Building>0 AND Building<=5),
--Financing money not null CHECK(Financing>=0) default 0,
--Floor int not null CHECK(Floor>0),
--Name nvarchar(100) not null CHECK(Name !='') unique
--)

--create table Diseases
--(
--ID int identity(1,1) not null primary key,
--Name nvarchar(100) not null CHECK(Name !='') unique,
--Severity int not null CHECK(Severity>0) default 1
--)

--create table Doctors
--(
--ID int identity(1,1) not null primary key,
--Name nvarchar(max) not null CHECK(Name !=''),
--Phone char(10),
--Premium money not null CHECK(Premium>=0) default 0,
--Salary money not null CHECK(Salary>0),
--Surname nvarchar(max) not null CHECK(Surname !='')
--)

--create table Examinations
--(
--ID int identity(1,1) not null primary key,
--DayOfWeek int not null CHECK(DayOfWeek>0 AND DayOfWeek<8),
--EndTime time not null,
--Name nvarchar(100) not null CHECK(Name !='') unique,
--StartTime time not null CHECK(StartTime>'08:00:00' AND StartTime<'18:00:00'),
--check (EndTime > StartTime)
--)

--create table Wards
--(
--ID int identity(1,1) not null primary key,
--Building int not null CHECK(Building>0 AND Building<=5),
--Floor int not null CHECK(Floor>0),
--Name nvarchar(20) not null CHECK(Name !='') unique
--)

--INSERT INTO Departments
--(Building, Financing, Floor, Name)
--VALUES
--(1,1000,1, 'терапии'),
--(2,2222,2, 'неврологии'),
--(3,3333,3, 'кардиологии'),
--(4,4444,4, 'гастроэнтерологии'),
--(5,5555,5, 'гинекологии');

--INSERT INTO Diseases
--(Name, Severity)
--VALUES
--('Рак',10),
--('Спид',23),
--('Простуда',3),
--('Герпес',4),
--('Туберулёз',5);

--INSERT INTO Doctors
--(Name, Phone, Premium, Salary, Surname)
--VALUES
--('Евгений Григорьевич','+6112345', 5000, 10000, 'Царук'),
--('Юрий Валентинович','	+4312345', 4000, 11000, 'Нечипоренко'),
--('Василий Васильевич','+9941234', 3000, 12000, 'Храпач'),
--('Юрий Игоревич','+3551234', 2000, 13000, 'Заседа'),
--('Алла Олеговна','+2131234', 3000, 14000, 'Вергуленко');

--INSERT INTO Examinations
--(DayOfWeek, EndTime, Name, StartTime) 
--VALUES 
--(1,'12:00','Лучевая диагностика','08:10'),
--(2,'13:00','МР-ангиография','09:00'),
--(3,'14:00','Рентгенография','10:00'),
--(4,'15:00','УЗИ','11:00'),
--(5,'16:00','МРТ','12:00');

--INSERT INTO Wards
--(Building, Floor, Name)
--VALUES 
--(1,2,'Общая'),
--(1,3,'Эконом'),
--(1,4,'Стандарт'),
--(2,3,'Люкс'),
--(1,3,'Суперлюкс');

--1. Вывести содержимое таблицы палат.
--select * 
--FROM Wards

--2. Вывести фамилии и телефоны всех врачей.
--select Surname, Phone 
--FROM Doctors

--3. Вывести все этажи без повторений, на которых располагаются палаты
--select distinct Floor 
--from Wards

--4. Вывести названия заболеваний под именем “Name of Disease” и степень их тяжести под именем “Severity of Disease”
--select Name as 'Name of Disease' , Severity as 'Severity of Disease'
--FROM Diseases

--5. Использовать выражение FROM для любых трех таблиц базы данных, используя для них псевдонимы.
--select D.Name, E.Name, W.Name
--FROM Doctors AS D, Examinations AS E, Wards AS W

--6. Вывести названия отделений, расположенных в корпусе 5 и имеющих фонд финансирования менее 30000.
--select Name 
--FROM Departments 
--WHERE Building = 5 AND Financing < 30000

--7. Вывести названия отделений, расположенных в 3-м корпусе с фондом финансирования в диапазоне от 12000 до 15000.
--select Name 
--FROM Departments 
--WHERE Building = 3 AND Financing > 12000 and Financing < 15000 

--8. Вывести названия палат, расположенных в корпусах 4 и 5 на 1-м этаже.
--select Name 
--from Wards
--WHERE Building = 4 or Building = 5 and Floor = 1 

--9. Вывести названия, корпуса и фонды финансирования отделений, расположенных в корпусах 3 или 6 и имеющих
--фонд финансирования меньше 11000 или больше 25000.
--select Name , Financing
--from  Departments 
--WHERE (Building = 3 or Building = 6) AND Financing < 12000 and Financing > 15000

--10. Вывести фамилии врачей, чья зарплата (сумма ставки и надбавки) превышает 1500.
--select Surname
--from Doctors
--WHERE (Salary + Premium) > 1500

--11. Вывести фамилии врачей, у которых половина зарплаты превышает троекратную надбавку
--select Surname
--from Doctors
--WHERE Salary / 2 > Premium * 3

--12. Вывести названия обследований без повторений, проводимых в первые три дня недели с 12:00 до 15:00. 
--select distinct Name
--from Examinations 
--WHERE (DayOfWeek = 1 or DayOfWeek = 2 or DayOfWeek = 3) and StartTime = '12:00:00' and EndTime = '15:00:00'

--13. Вывести названия и номера корпусов отделений, расположенных в корпусах 1, 3, 8 или 10.
--select Name
--from  Departments 
--WHERE Building = 1 or Building = 3 or Building = 8 or Building = 10

--14. Вывести названия заболеваний всех степеней тяжести, кроме 1-й и 2-й.
--select Name
--FROM Diseases
--where Severity != 1 and Severity ! = 2

--15. Вывести названия отделений, которые не располагаются в 1-м или 3-м корпусе.
--select Name
--from  Departments 
--WHERE Building != 1 and Building != 3

--16. Вывести названия отделений, которые располагаются в 1-м или 3-м корпусе.
--select Name
--from  Departments 
--WHERE Building = 1 and Building = 3

--17. Вывести фамилии врачей, начинающиеся на букву “N”
--select Surname
--from Doctors
--where Surname LIKE 'N%'
