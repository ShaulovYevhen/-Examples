use [master];
go

if db_id('Academy') is not null
begin
	drop database [Academy];
end
go

create database [Academy];
go

use [Academy];
go

create table [Departments]
(
	[Id] int not null identity(1, 1) primary key,
	[Financing] money not null check ([Financing] >= 0.0) default 0.0,
	[Name] nvarchar(100) not null unique check ([Name] <> N''),
	[FacultyId] int not null
);
go

create table [Faculties]
(
	[Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(100) not null unique check ([Name] <> N'')
);
go

create table [Groups]
(
	[Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(100) not null unique check ([Name] <> N''),
	[Year] int not null check ([Year] between 1 and 5),
	[DepartmentId] int not null
);
go

create table [GroupsLectures]
(
	[Id] int not null identity(1, 1) primary key,
	[DayOfWeek] int not null check ([DayOfWeek] between 1 and 7),
	[GroupId] int not null,
	[LectureId] int not null
);
go

create table [Lectures]
(
	[Id] int not null identity(1, 1) primary key,
	[LectureRoom] nvarchar(max) not null check ([LectureRoom] <> N''),
	[SubjectId] int not null,
	[TeacherId] int not null
);
go

create table [Subjects]
(
	[Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(100) not null unique check ([Name] <> N'')
);
go

create table [Teachers]
(
	[Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(max) not null check ([Name] <> N''),
	[Salary] money not null check ([Salary] > 0.0),
	[Surname] nvarchar(max) not null check ([Surname] <> N'')
);
go

alter table [Departments]
add foreign key ([FacultyId]) references [Faculties]([Id]);
go

alter table [Groups]
add foreign key ([DepartmentId]) references [Departments]([Id]);
go

alter table [GroupsLectures]
add foreign key ([GroupId]) references [Groups]([Id]);
go

alter table [GroupsLectures]
add foreign key ([LectureId]) references [Lectures]([Id]);
go

alter table [Lectures]
add foreign key ([SubjectId]) references [Subjects]([Id]);
go

alter table [Lectures]
add foreign key ([TeacherId]) references [Teachers]([Id]);
go

insert into Faculties(Name)
values
('Computer Science'),
('Physics'),
('Inform'),
('Botanic'),
('Programming'),
('Cybernetics'),
('Software development'),
('Hardware development')

insert into Subjects(Name)
values
('Database Theory'),
('History'),
('Physic'),
('Informatic'),
('Botanics'),
('Computer Programming'),
('PHP'),
('PasKakal'),
('Delphi'),
('C++'),
('Database Practice'),
('Hardware theory'),
('Micro proecting')

insert into Teachers(Name, Salary, Surname)
values
('Samantha', 7000, 'Adams'),
('Dave', 5000, 'McQueen'),
('Petro', 6000, 'Sidorov'),
('Pedro', 7000, 'Ivanov'),
('Sidor', 7000, 'Dimidrov'),
('Nick', 4500, 'Mimikov'),
('John', 10000, 'Week'),
('James', 2000, 'Jonson'),
('Jacob', 2000, 'Weedly'),
('Jonior', 4000, 'Nudl'),
('Victor', 3000, 'Freek'),
('Mick', 2000, 'Mouse'),
('Jack',4700, 'Underhill')

insert into Departments(Financing, Name, FacultyId)
values
(10000,'Historycal',1),
(10001,'Physics',2),
(10002,'Information',3),
(10003,'Botanics',4),
(10004,'Computer Science',5),
(10005,'Cybernetics',6),
(10006,'Programming',7),
(10007,'Etymology',8),
(10008,'Philosophy',1),
(10009,'coding theory',2),
(10010,'Data structures',3),
(10011,'algorithms',4),
(10012,'Computer systems',5),
(10013,'Software Development',6),
(10014,'Computer networks',7),
(10015,'Computer security ',8),
(10016,'Cryptography',1)

insert into Groups
(Name, Year, DepartmentId)
Values
('A101' ,1,1),
('A102' ,2,2),
('A103' ,3,3),
('A104' ,4,4),
('B101' ,1,5),
('B102' ,2,6),
('B103' ,3,7),
('B104' ,4,8),
('C101' ,1,9),
('C102' ,2,10),
('C103' ,3,11),
('C104' ,4,12),
('D101' ,1,13),
('D102' ,2,14),
('D103' ,3,15),
('D104' ,4,16),
('D201' ,1,17),
('D202' ,2,1),
('D203' ,3,2),
('D204' ,4,3)

insert into Lectures
(LectureRoom, SubjectId, TeacherId)
Values
('E11' ,1,1),
('E12' ,2,2),
('E13' ,3,3),
('E14' ,4,4),
('B11' ,5,5),
('B12' ,6,6),
('B13' ,7,7),
('B14' ,8,8),
('C11' ,9,9),
('C12' ,10,10),
('C13' ,11,11),
('C14' ,12,12),
('D201' ,13,13),
('D202' ,1,1),
('D103' ,2,2),
('D104' ,3,3),
('D201' ,4,4),
('D202' ,5,5),
('D201' ,6,6),
('D204' ,4,4)

insert into GroupsLectures
(DayOfWeek,GroupId,LectureId)
values
(1,1,1),
(2,2,2),
(3,3,3),
(4,4,4),
(5,5,5),
(1,6,6),
(2,7,7),
(3,8,8),
(4,9,9),
(5,10,10),
(1,11,11),
(2,12,12),
(3,13,13),
(4,14,14),
(5,15,15),
(1,16,16),
(2,17,17),
(3,18,18),
(4,19,19),
(5,20,20),
(3,1,4),
(4,3,5),
(5,4,6),
(2,5,7),
(3,6,3),
(4,8,3),
(5,9,5),
(1,4,6),
(3,4,7),
(3,1,8)

--1.Вывести количество преподавателей кафедры “Software Development”.
select count(Teachers.Name) as 'Teachers on department Software Development'
from Teachers
join Lectures on Teachers.Id=Lectures.TeacherId
join GroupsLectures on GroupsLectures.LectureId = Lectures.Id 
join Groups on GroupsLectures.GroupId=Groups.Id
join Departments on Groups.DepartmentId=Departments.id and Departments.Name='Software Development'

--2. Вывести количество лекций, которые читает преподаватель “Dave McQueen”.
select count(Lectures.Id) as 'Dave McQueens lectures'
from Lectures
join Teachers on Teachers.Id=Lectures.TeacherId and Teachers.Name='Dave' and Teachers.Surname='McQueen'

--3. Вывести количество занятий, проводимых в аудитории “D201”
select count(Lectures.id) as 'lectures in D201' 
from lectures
join GroupsLectures on GroupsLectures.LectureId = Lectures.Id and Lectures.LectureRoom='D201'

--4. Вывести названия аудиторий и количество лекций, проводимых в них.
select Lectures.LectureRoom, COUNT(Lectures.Id) as 'Lectures count'
from Lectures
join GroupsLectures on GroupsLectures.LectureId=Lectures.Id
Group by LectureRoom

-5. Вывести количество студентов, посещающих лекции преподавателя “Jack Underhill”
select count(Groups.Id) as 'Jack Underhills groups'
from Groups
join GroupsLectures on Groups.Id = GroupsLectures.GroupId
join Lectures on GroupsLectures.LectureId=Lectures.Id
join Teachers on Lectures.TeacherId=Teachers.Id and Teachers.Name='Jack' and Teachers.Surname='Underhill'

--6. Вывести среднюю ставку преподавателей факультета “Computer Science”.
select AVG(Teachers.Salary) as 'average salary at Computer Science' 
from Teachers 
join Lectures on Lectures.TeacherId=Teachers.Id
join GroupsLectures on GroupsLectures.LectureId=Lectures.Id
join Groups on Groups.Id=GroupsLectures.Id
join Departments on Groups.DepartmentId=Departments.Id
join Faculties on Faculties.Id = Departments.FacultyId and Faculties.Name='Computer Science'

--7. Вывести минимальное и максимальное количество студентов среди всех групп. ??? студентов нет, есть только группы

--8. Вывести средний фонд финансирования кафедр.
select avg(Departments.Financing) as 'average financind Departments' 
from Departments

--9. Вывести полные имена преподавателей и количество читаемых ими дисциплин.
select Teachers.Name, Teachers.Surname, COUNT(Subjects.Id) as 'Subjects count'
from Teachers
join Lectures on Teachers.Id=Lectures.TeacherId
join Subjects on Lectures.SubjectId=Subjects.Id
group by Teachers.Name, Teachers.Surname

--10. Вывести количество лекций в каждый день недели.
select count(Lectures.Id) as 'number of lectures', GroupsLectures.DayOfWeek
from Lectures
join GroupsLectures on GroupsLectures.LectureId=Lectures.Id
group by GroupsLectures.DayOfWeek

--11. Вывести номера аудиторий и количество кафедр, чьи лекции в них читаются.
select Lectures.LectureRoom, COUNT(Departments.Id) as 'number of departmens'
from Lectures
join GroupsLectures on GroupsLectures.LectureId=Lectures.Id
join Groups on Groups.Id=GroupsLectures.GroupId
join Departments on Groups.DepartmentId=Departments.Id
group by Lectures.LectureRoom

--12. Вывести названия факультетов и количество дисциплин, которые на них читаются.
select Faculties.Name, count(Subjects.Id) as 'number of subjects'
from Faculties
join Departments on Departments.FacultyId=Faculties.Id
join Groups on Groups.DepartmentId=Departments.Id
join GroupsLectures on GroupsLectures.GroupId=Groups.Id
join Lectures on GroupsLectures.LectureId=Lectures.Id
join Subjects on Subjects.Id=Lectures.SubjectId
group by Faculties.Name

--13. Вывести количество лекций для каждой пары преподаватель-аудитория.
select(Teachers.Name+' '+Teachers.Surname) as Teacher, Lectures.LectureRoom, COUNT(Lectures.Id)
from Teachers
join Lectures on Lectures.TeacherId=Teachers.Id
group by Lectures.LectureRoom, Teachers.Name, Teachers.Surname
