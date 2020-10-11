--create database Academy
--go
--use Academy
--create table Departments
--(
--ID int identity(1,1) not null primary key,
--Financing money not null CHECK(Financing>=0) default 0,
--Name nvarchar(100) not null CHECK(Name !='') unique
--)

--create table Faculties
--(
--ID int identity(1,1) not null primary key,
--Dean nvarchar(max) not null CHECK(Dean !=''),
--Name nvarchar(100) not null CHECK(Name !='') unique
--)

--create table Groups
--(
--ID int identity(1,1) not null primary key,
--Name nvarchar(10) not null CHECK(Name !='') unique,
--Rating int not null CHECK(Rating>=0 AND Rating<=5),
--Year int not null CHECK(Year>=1 AND Year<=5)
--)

--create table Teachers
--(
--ID int identity(1,1) not null primary key,
--EmploymentDate date not null CHECK(EmploymentDate>='01-01-1990'),
--IsAssistant bit not null default 0,
--IsProfessor bit not null default 0,
--Name nvarchar(max) not null CHECK(Name !=''),
--Position nvarchar(max) not null CHECK(Position !=''),
--Premium money not null CHECK(Premium>=0) default 0,
--Salary money not null CHECK(Salary>=0),
--Surname nvarchar(max) not null CHECK(Surname !='')
--)

--insert into Departments(Financing, Name)
--values
--(1000, 'Historycal'),
--(1222, 'Physics'),
--(1020, 'Information'),
--(2000, 'Botanics')

--insert into Faculties(Dean, Name)
--values
--('Ivanov', 'History'),
--('Petrov', 'Physics'),
--('Sidorov', 'Inform'),
--('Petrov', 'Botanic')

--insert into Groups(Name, Rating, Year)
--values
--('B1',1,4),
--('A2',2,3),
--('E4',3,2),
--('U5',4,1)

--insert into Teachers(EmploymentDate,IsAssistant,IsProfessor,Name,Position,Premium,Salary,Surname)
--values
--('11-10-1991',1,0,'Ivan','History teacher',22,1000,'Ivanov'),
--('13-10-1992',0,1,'Petro','Physic teacher',23,2000,'Petrov'),
--('21-12-1993',1,0,'Sidor','Informatic teacher',24,1212,'Sidorov'),
--('14-11-1994',0,1,'Pedro','Botanic teacher',25,2121,'Petrov')

--1. Вывести таблицу кафедр, но расположить ее поля в обратном порядке.
--SELECT * FROM Departments ORDER BY ID DESC

--2. Вывести названия групп и их рейтинги с уточнением имен полей именем таблицы
--SELECT Name AS Groups_Name , Rating AS Groups_Rating  FROM Groups

--3. Вывести для преподавателей их фамилию, процент ставки по отношению к надбавке 
--и процент ставки по отношениюк зарплате (сумма ставки и надбавки).
--SELECT Surname, (Premium/Salary)*100 as 'процент ставки по отношению к надбавке', 
--Salary/(Premium+Salary)*100 as'процент ставки по отношениюк зарплате' from Teachers

--4. Вывести таблицу факультетов в виде одного поля в следующем формате: “The dean of faculty [faculty] is [dean].”.--Select 'The dean of faculty '+Name+' is '+Dean from Faculties

--5. Вывести фамилии преподавателей, которые являются профессорами и ставка которых превышает 1050.
--SELECT * FROM Teachers WHERE IsProfessor=1 and Salary>1050

--6. Вывести названия кафедр, фонд финансирования которых меньше 11000 или больше 25000.
--SELECT Name, Financing FROM Departments WHERE Financing < 11000 AND Financing > 25000

--7.Вывести названия факультетов кроме факультета “Computer Science”.
--SELECT Name FROM Faculties WHERE Name!= 'Computer Science'

--8. Вывести фамилии и должности преподавателей, которые не являются профессорами.
--SELECT Surname, Position FROM Teachers WHERE IsProfessor=0

--9. Вывести фамилии, должности, ставки и надбавки ассистентов, у которых надбавка в диапазоне от 160 до 550.
--SELECT Surname, Position, Salary, Premium FROM Teachers WHERE IsAssistant=1 and Premium >= 160 AND Premium <= 550

--10. Вывести фамилии и ставки ассистентов.
--SELECT Surname, Salary FROM Teachers WHERE IsAssistant=1

--11. Вывести фамилии и должности преподавателей, которые были приняты на работу до 01.01.2000.
--SELECT Surname, Position FROM Teachers WHERE EmploymentDate <= '01-01-2000'

--12. Вывести названия кафедр, которые в алфавитном порядке располагаются до кафедры 
--“Software Development”. Выводимое поле должно иметь название “Name of Department”.
--SELECT Name as 'Name of departments ' FROM Departments WHERE Name<'Software Development' ORDER BY Name 

--13. Вывести фамилии ассистентов, имеющих зарплату (сумма ставки и надбавки) не более 1200.
--SELECT Surname FROM Teachers WHERE (Salary + Premium) <= 1200 AND IsAssistant=1

--14. Вывести названия групп 5-го курса, имеющих рейтинг в диапазоне от 2 до 4.
--SELECT Name FROM Groups WHERE Rating >= 2 AND Rating <= 4 AND Year=5

--15. Вывести фамилии ассистентов со ставкой меньше 550 или надбавкой меньше 200.
--SELECT Name FROM Teachers WHERE Salary < 550 OR Premium < 200 AND IsAssistant=1