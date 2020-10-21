--create database [Academy];
--go

use [Academy];
go

--create table [Curators]
--(
--	[Id] int not null identity(1, 1) primary key,
--	[Name] nvarchar(max) not null check ([Name] <> N''),
--	[Surname] nvarchar(max) not null check ([Surname] <> N'')
--);
--go

--create table [Departments]
--(
--	[Id] int not null identity(1, 1) primary key,
--	[Financing] money not null check ([Financing] >= 0.0) default 0.0,
--	[Name] nvarchar(100) not null unique check ([Name] <> N''),
--	[FacultyId] int not null
--);
--go

--create table [Faculties]
--(
--	[Id] int not null identity(1, 1) primary key,
--	[Financing] money not null check ([Financing] >= 0.0) default 0.0,
--	[Name] nvarchar(100) not null unique check ([Name] <> N'')
--);
--go

--create table [Groups]
--(
--	[Id] int not null identity(1, 1) primary key,
--	[Name] nvarchar(100) not null unique check ([Name] <> N''),
--	[Year] int not null check ([Year] between 1 and 5),
--	[DepartmentId] int not null
--);
--go

--create table [GroupsCurators]
--(
--	[Id] int not null identity(1, 1) primary key,
--	[CuratorId] int not null,
--	[GroupId] int not null
--);
--go

--create table [GroupsLectures]
--(
--	[Id] int not null identity(1, 1) primary key,
--	[GroupId] int not null,
--	[LectureId] int not null
--);
--go

--create table [Lectures]
--(
--	[Id] int not null identity(1, 1) primary key,
--	[LectureRoom] nvarchar(max) not null check ([LectureRoom] <> N''),
--	[SubjectId] int not null,
--	[TeacherId] int not null
--);
--go

--create table [Subjects]
--(
--	[Id] int not null identity(1, 1) primary key,
--	[Name] nvarchar(100) not null unique check ([Name] <> N'')
--);
--go

--create table [Teachers]
--(
--	[Id] int not null identity(1, 1) primary key,
--	[Name] nvarchar(max) not null check ([Name] <> N''),
--	[Salary] money not null check ([Salary] > 0.0),
--	[Surname] nvarchar(max) not null check ([Surname] <> N'')
--);
--go

--alter table [Departments]
--add foreign key ([FacultyId]) references [Faculties]([Id]);
--go

--alter table [Groups]
--add foreign key ([DepartmentId]) references [Departments]([Id]);
--go

--alter table [GroupsCurators]
--add foreign key ([CuratorId]) references [Curators]([Id]);
--go

--alter table [GroupsCurators]
--add foreign key ([GroupId]) references [Groups]([Id]);
--go

--alter table [GroupsLectures]
--add foreign key ([GroupId]) references [Groups]([Id]);
--go

--alter table [GroupsLectures]
--add foreign key ([LectureId]) references [Lectures]([Id]);
--go

--alter table [Lectures]
--add foreign key ([SubjectId]) references [Subjects]([Id]);
--go

--alter table [Lectures]
--add foreign key ([TeacherId]) references [Teachers]([Id]);
--go

--insert into Curators(Name, Surname)
--values
--('Samantha', 'Adams')
--('Ivan', 'Petrov'),
--('Petro', 'Sidorov'),
--('Pedro', 'Ivanov'),
--('Sidor', 'Dimidrov'),
--('Nick', 'Mimikov'),
--('John', 'Week')

--insert into Faculties(Financing, Name)
--values
--(10000, 'History'),
--(22222, 'Physics'),
--(12321, 'Inform'),
--(45543, 'Botanic'),
--(77722, 'Programming'),
--(23424, 'Cybernetics'),
--(90000, 'Computer Science')

--insert into Departments(Financing, Name, FacultyId)
--values
--(10000, 'Historycal',1),
--(12220, 'Physics',2),
--(10200, 'Information',3),
--(20000, 'Botanics',4),
--(20000, 'Computer Science',5),
--(20000, 'Cybernetics',6),
--(20000, 'Programming',7)

--insert into Groups(Name, Year, DepartmentId)
--values
--('P101', 1, 8),
--('P202', 2, 9),
--('P303', 3, 10),
--('P404', 4, 8),
--('P105', 1, 9),
--('P107', 1, 11),
--('B103', 1, 12),
--('C104', 1, 13),
--('D105', 1, 14)

--insert into Subjects(Name)
--values
--('Database Theory'),
--('History'),
--('Physic'),
--('Informatic'),
--('Botanics'),
--('Computer Programming'),
--('PHP'),
--('PasKakal'),
--('Delphi'),
--('C++'),
--('Database Practice')

--insert into Teachers(Name, Salary, Surname)
--values
--('Samantha', 7000, 'Adams'),
--('Ivan', 5000, 'Petrov'),
--('Petro', 6000, 'Sidorov'),
--('Pedro', 7000, 'Ivanov'),
--('Sidor', 7000, 'Dimidrov'),
--('Nick', 4500, 'Mimikov'),
--('John', 10000, 'Week'),
--('James', 2000, 'Jonson'),
--('Jacob', 2000, 'Weedly'),
--('Jonior', 4000, 'Nudl'),
--('Victor', 3000, 'Freek'),
--('Mick', 2000, 'Mouse')

--insert into Lectures(LectureRoom, SubjectId, TeacherId)
--values
--('a111',1,1),
--('a221',2,2),
--('a311',3,3),
--('c101',4,4),
--('d400',5,5),
--('B103',6,6),
--('B103',7,7),
--('B104',8,8),
--('B105',9,9),
--('e211',10,10),
--('q121',11,11),
--('d111',2,12)

--insert into GroupsLectures(GroupId,LectureID)
--values
--(2,1),
--(3,2),
--(4,3),
--(5,4),
--(6,5),
--(7,6),
--(8,7),
--(9,8),
--(10,9),
--(10,10),
--(10,11)

--insert into GroupsCurators(CuratorId, GroupId)
--values
--(1,2),
--(2,3),
--(3,4),
--(4,5),
--(5,6),
--(6,7),
--(7,8),
--(2,9),
--(3,10)

--1. Вывести все возможные пары строк преподавателей и групп.
--SELECT GROUPS.ID AS GROUP_ID,
--GROUPS.NAME AS GROUP_NAME, 
--Teachers.Id AS TEACHER_ID, 
--Teachers.Surname AS TEACHER_SURNAME
--FROM GROUPS 
--Cross join Teachers

--2. Вывести названия факультетов, фонд финансирования кафедр которых превышает фонд финансирования факультета.
--select Faculties.Name
--from Departments, Faculties
--WHERE Faculties.ID = Departments.FacultyId
--group by Departments.FacultyId, Faculties.Financing , Faculties.Name
--Having sum(Departments.Financing) > Faculties.Financing

--3. Вывести фамилии кураторов групп и названия групп, которые они курируют.
--select Curators.surname, Groups.Name
--from Curators, Groups, GroupsCurators
--where GroupsCurators.CuratorId=Curators.id and GroupsCurators.GroupId=Groups.ID

--4. Вывести имена и фамилии преподавателей, которые читаютлекции у группы “P107”.
--select Teachers.Name, Teachers.Surname
--from Teachers, GroupsLectures, Groups, lectures
--where Teachers.ID = lectures.TeacherID and GroupsLectures.LectureId=Lectures.id and GroupsLectures.GroupId = groups.id and groups.name='P107'

--5.Вывести фамилии преподавателей и названия факультетовна которых они читают лекции.
--SELECT Teachers.Surname AS TeacherSurname, Faculties.Name AS FacultyName
--FROM Teachers 
--JOIN Lectures ON Teachers.ID=Lectures.TeacherID
--JOIN GroupsLectures  ON Lectures.ID=GroupsLectures.LectureID
--JOIN Groups ON GroupsLectures.GroupID=Groups.ID
--JOIN Departments ON Groups.DepartmentID=Departments.ID
--JOIN Faculties ON Departments.FacultyID=Faculties.ID

--6.Вывести названия кафедр и названия групп, которые к ним относятся.
--SELECT Departments.Name, Groups.Name
--from Departments
--join Groups on departments.id = groups.departmentid

--7.Вывести названия дисциплин, которые читает преподаватель “Samantha Adams”.
--select subjects.name
--from subjects
--join teachers on Teachers.name='Samantha' and Teachers.surname='Adams' 
--join lectures on lectures.teacherId = teachers.id
--where lectures.subjectId=subjects.id

--8.Вывести названия кафедр, на которых читается дисциплина “Database Theory”.
--SELECT Departments.Name
--from Departments
--join groups on groups.departmentid=Departments.id
--join groupslectures on groupslectures.groupid=groups.id
--join lectures on lectures.id=groupslectures.lectureid
--join subjects on subjects.id= lectures.subjectid
--where subjects.name= 'Database Theory'

--9.Вывести названия групп, которые относятся к факультету “Computer Science”.
--SELECT Groups.Name
--from Groups 
--join Departments on groups.departmentid=Departments.id
--join faculties on Departments.Facultyid=faculties.id
--where faculties.name = 'Computer Science'

--10. Вывести названия групп 5-го курса, а также название факультетов, к которым они относятся.
--SELECT Groups.Name, faculties.name
--from Groups
--join Departments on groups.departmentid=Departments.id
--join faculties on Departments.Facultyid=faculties.id
--where groups.year=5

--11. Вывести полные имена преподавателей и лекции, которые
--они читают (названия дисциплин и групп), причем отобрать
--только те лекции, которые читаются в аудитории “B103”.
--select Teachers.Name, Teachers.Surname, subjects.name as 'subject', groups.name as 'group'
--from Teachers
--join lectures on lectures.teacherid=teachers.id and lectures.lectureRoom='B103'
--join groupslectures on groupslectures.lectureID=lectures.id
--join groups on groups.id=groupslectures.groupid
--join subjects on subjects.id=lectures.subjectid