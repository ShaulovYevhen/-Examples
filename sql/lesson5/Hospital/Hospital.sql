use [master];
go

if db_id('Hospital') is not null
begin
	drop database [Hospital];
end
go

create database [Hospital];
go

use [Hospital];
go

create table [Departments]
(
	[Id] int not null identity(1, 1) primary key,
	[Building] int not null check ([Building] between 1 and 5),
	[Name] nvarchar(100) not null unique check ([Name] <> N'')
);
go

create table [Doctors]
(
	[Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(max) not null check ([Name] <> N''),
	[Premium] money not null check ([Premium] >= 0.0) default 0.0,
	[Salary] money not null check ([Salary] > 0.0),
	[Surname] nvarchar(max) not null check ([Surname] <> N'')
);
go

create table [DoctorsExaminations]
(
	[Id] int not null identity(1, 1) primary key,
	[EndTime] time not null,
	[StartTime] time not null check ([StartTime] between '08:00' and '18:00'),
	[DoctorId] int not null,
	[ExaminationId] int not null,
	[WardId] int not null,
	check ([StartTime] < [EndTime])
);
go

create table [Donations]
(
	[Id] int not null identity(1, 1) primary key,
	[Amount] money not null check ([Amount] > 0.0),
	[Date] date not null check ([Date] <= getdate()) default getdate(),
	[DepartmentId] int not null,
	[SponsorId] int not null
);
go

create table [Examinations]
(
	[Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(100) not null unique check ([Name] <> N'')
);
go

create table [Sponsors]
(
	[Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(100) not null unique check ([Name] <> N'')
);
go

create table [Wards]
(
	[Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(20) not null unique check ([Name] <> N''),
	[Places] int not null check ([Places] >= 1),
	[DepartmentId] int not null
);
go

alter table [DoctorsExaminations]
add foreign key ([DoctorId]) references [Doctors]([Id]);
go

alter table [DoctorsExaminations]
add foreign key ([ExaminationId]) references [Examinations]([Id]);
go

alter table [DoctorsExaminations]
add foreign key ([WardId]) references [Wards]([Id]);
go

alter table [Donations]
add foreign key ([DepartmentId]) references [Departments]([Id]);
go

alter table [Donations]
add foreign key ([SponsorId]) references [Sponsors]([Id]);
go

alter table [Wards]
add foreign key ([DepartmentId]) references [Departments]([Id]);
go

INSERT INTO Departments
(Building, Name)
values
(1,'Cardiology'),
(1,'Gastroenterology'),
(1,'General Surgery'),
(2,'Surgery'),
(2,'Microbiology'),
(2,'Biology'),
(3,'Cardiotherapy'),
(3,'Neurology'),
(4,'Virusology'),
(5,'Oncology'),
(5,'Stomatology')
go

INSERT INTO Doctors
(Name, Premium, Salary, Surname)
values
('Thomas', 200, 50000, 'Gerada'),
('Anthony', 100, 30000, 'Davis'),
('Joshua', 300, 30000, 'Bell'),
('Sara', 400, 30000, 'Lee'),
('Junior', 500, 30000, 'Jong'),
('Mikki', 300, 31000, 'Rurg'),
('Kain', 500, 42000, 'Velaskas'),
('Shon', 700, 19000, 'Konor'),
('Helen', 800, 20000, 'Lilit'),
('Nicolas', 100, 30000, 'Green'),
('Dave', 200, 40000, 'Ouwell'),
('Don', 900, 55000, 'King'),
('Albert', 500, 15000, 'Shtein')
go

INSERT INTO Sponsors
(Name)
Values
('Pepsi'),
('Coca-Cola'),
('Rolex'),
('Marriott'),
('Wells Fargo'),
('Bank of America'),
('WalMart'),
('McDonalds'),
('Kind Snacks'),
('Starbucks'),
('Lagunitas'),
('Allstate'),
('Boeing'),
('Toyota')
go

INSERT INTO Examinations
(name)
values
('Screening for High Cholesterol'),
('Screening for High Blood Pressure'),
('Screening for Heart Disease'),
('Screening for Diabetes'),
('Screening for Skin Cancer'),
('Screening for Colorectal Cancer'),
('Screening for Abdominal Aortic Aneurysm'),
('Screening for Alzheimers Disease'),
('Screening for ACID'),
('Physical Examination'),
('Annual Examination'),
('Endoscopy'),
('Bronchoscopy'),
('Analysis of Body Fluids')
go

INSERT INTO Wards
(name, places, DepartmentId)
values
('L21',2,1),
('L11',1,2),
('L31',3,3),
('D41',4,4),
('D42',4,5),
('D43',4,6),
('D44',4,7),
('L1',1,8),
('E21',2,9),
('L12',1,10),
('H11',2,11),
('L22',2,1),
('L41',1,2),
('F72',2,1),
('F73',2,2),
('A13',3,3),
('A14',4,4),
('S51',5,5),
('S31',3,6),
('S32',3,7),
('S33',3,8),
('S34',3,9),
('S35',3,10),
('DK21',2,11),
('DK22',2,1),
('DK23',2,2)

INSERT INTO Donations
(Amount, Date, DepartmentId, SponsorId)
values
(1000, '11.10.2020',1,1),
(2000, '01.10.2020',2,2),
(4000, '12.10.2020',3,3),
(2000, '01.01.2020',4,4),
(5000, '13.10.2020',5,5),
(6000, '14.10.2020',6,6),
(11000, '15.10.2020',7,7),
(9000, '16.10.2020',8,8),
(2000, '17.10.2020',9,9),
(13000, '18.10.2020',10,10),
(14000, '19.10.2020',11,11),
(41000, '20.10.2020',1,12),
(1000, '21.10.2020',2,13),
(21000, '11.07.2020',3,14)

INSERT INTO DoctorsExaminations
(EndTime, StartTime, DoctorId, ExaminationId, WardId)
values
('15:00','12:00',1,1,1),
('16:00','13:00',2,2,2),
('14:00','11:00',3,3,3),
('13:00','10:00',4,4,4),
('10:00','07:00',5,5,5),
('20:00','18:00',6,6,6),
('15:00','12:00',7,7,7),
('16:00','13:00',8,8,8),
('17:00','14:00',9,9,9),
('18:00','15:00',10,10,10),
('19:00','16:00',11,11,11),
('20:00','17:00',12,12,12),
('21:00','18:00',13,13,13),
('22:00','19:00',1,14,14),
('13:00','10:00',2,2,15),
('10:00','07:00',3,3,16),
('11:00','08:00',4,4,17),
('12:00','09:00',5,5,18),
('13:00','10:00',6,6,19),
('14:00','11:00',7,7,20),
('15:00','12:00',8,1,21),
('16:00','13:00',9,8,21),
('17:00','14:00',10,9,23),
('18:00','15:00',11,10,24),
('19:00','16:00',12,11,25),
('20:00','17:00',13,12,26)

--1. ¬ывести названи€ отделений, что наход€тс€ в том же корпусе, что и отделение УCardiologyФ.
select Departments.Name
from Departments 
where Departments.Building = all(SELECT Departments.Building FROM Departments WHERE Departments.Name='Cardiology')

--2. ¬ывести названи€ отделений, что наход€тс€ в том же корпусе, что и отделени€ УGastroenterologyФ и УGeneral SurgeryФ.
select Departments.Name
from Departments 
where Departments.Building = all(SELECT Departments.Building FROM Departments WHERE (Departments.Name='Gastroenterology' or Departments.Name='General Surgery'))

--3. ¬ывести название отделени€, которое получило меньше всего пожертвований
select Distinct Departments.Name
from Departments
join Donations on Departments.Id=Donations.DepartmentId
where Donations.Amount = (SELECT min(Donations.Amount) from Donations)

--4. ¬ывести фамилии врачей, ставка которых больше, чем у врача УThomas GeradaФ.
select Doctors.Surname
from Doctors
where Doctors.Salary > (select Doctors.Salary from Doctors where Doctors.Name='Thomas' and Doctors.Surname='Gerada')

--5. ¬ывести названи€ палат, вместимость которых больше, чем средн€€ вместимость в палатах отделени€ УMicrobiologyФ
select Wards.Name
from Wards
where Wards.Places > 
(
select avg(Wards.Places) 
from Wards 
join Departments on Departments.Id=Wards.DepartmentId and Departments.Name='Microbiology'
)

--6. ¬ывести полные имена врачей, зарплаты которых (сумма ставки и надбавки) превышают более чем на 100 зарплату врача УAnthony DavisФ
select Doctors.Name, Doctors.Surname
from Doctors
where (Doctors.Premium+Doctors.Salary)>
(
select (Doctors.Premium+Doctors.Salary+100)
from Doctors
where Doctors.Name='Anthony' and Doctors.Surname='Davis'
)

--7.¬ывести названи€ отделений, в которых проводит обследовани€ врач УJoshua BellФ
select distinct Departments.Name
from Departments
join Wards on Departments.Id=Wards.DepartmentId
join DoctorsExaminations on Wards.Id=DoctorsExaminations.WardId
join Doctors on DoctorsExaminations.DoctorId=Doctors.Id and Doctors.Name='Joshua' and Doctors.Surname='Bell'

--8. ¬ывести названи€ спонсоров, которые не делали пожертвовани€ отделени€м УNeurologyФ и УOncologyФ.
select distinct Sponsors.Name
from Sponsors
join Donations on Sponsors.Id=Donations.SponsorId
join Departments on Donations.DepartmentId=Departments.Id and Departments.Name!='Neurology'and Departments.Name!='Oncology'

--9. ¬ывести фамилии врачей, которые провод€т обследовани€ в период с 12:00 до 15:00.
select distinct Doctors.Surname
from Doctors
join DoctorsExaminations on Doctors.Id=DoctorsExaminations.DoctorId and DoctorsExaminations.StartTime='12:00' and DoctorsExaminations.EndTime='15:00'