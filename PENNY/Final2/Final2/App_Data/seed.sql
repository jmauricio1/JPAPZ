INSERT INTO [dbo].[Countries](Nationality)
	VALUES
	('Russia'),
	('Italy'),
	('USA'),
	('Japan');

INSERT INTO [dbo].[Missions](Designation, TheDescription)
	VALUES
	('Expedition 53', 'Description One'),
	('Expedition 52', 'Description Two'),
	('STS-112', 'Description Three');


INSERT INTO [dbo].[Astronauts](AstronautName, Birthday, CountryID)
	VALUES
	('Randy Bresnik',    '1967-09-11', 3),
('Sergey Ryazansky', '1974-11-13', 1),
('Paolo Nespoli',    '1957-05-06', 2),
('Fyodor Yurchikhin', '1959-01-03', 1);

INSERT INTO [dbo].[Crews](Position, AstronautID, MissionID)
	VALUES
	('Mission Specialist 4', 4, 3),
	('Commander', 1, 1),
	('Flight Engineer 1', 2, 1),
	('Flight Enginner 5', 3, 2);
