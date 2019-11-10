CREATE TABLE [dbo].[newHomeworks]
(
	[ID]		INT IDENTITY (1,1)	NOT NULL,
	[HomeworkPriority] NVARCHAR(64)		NOT NULL,
	[DueDate]   DATE			NOT NULL,
	[DueTime]	TIME		        NOT NULL,
	[Department] NVARCHAR(64)			NOT NULL,
	[Course]    INT					NOT NULL,
	[HomeworkTitle] NVARCHAR(max)		NOT NULL,
	[Notes]     NVARCHAR(max)			NOT NULL, 
	CONSTRAINT [PK_dbo.newHomeworks] PRIMARY KEY CLUSTERED ([ID] ASC)
)

INSERT INTO [dbo].[newHomeworks] (HomeworkPriority, DueDate, DueTime, Department, Course, HomeworkTitle, Notes) VALUES
	('prefer','11-01-2019','23:59','Math','354','Complete Graph', 'Graded'),
	('prefer','12-31-2019','23:59','CS','121','Photoshop','unGraded'),
	('later','09-15-2018','23:59','Art','231','Oil Painting','Graded'),
	('later','10-01-2018','23:59','Music','110','Broadway Music','unGraded'),
	('later','08-08-2019','23:59','Education','380','Education Setting','Graded')
GO