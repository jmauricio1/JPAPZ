CREATE TABLE [dbo].[Countries]
(
	[ID]			INT IDENTITY (1,1) NOT NULL,
	[Nationality]			NVARCHAR(50)	   NOT NULL,			  
	CONSTRAINT [PK_dbo.Countries] PRIMARY KEY CLUSTERED ([ID] ASC)
);

CREATE TABLE [dbo].[Missions]
(
	[ID]				INT IDENTITY (1,1)	NOT NULL,
	[Designation]		NVARCHAR (50)		NOT NULL,
	[TheDescription]		NVARCHAR (50)		NOT NULL,
	CONSTRAINT [PK_dbo.Missions] PRIMARY KEY CLUSTERED ([ID] ASC),
);


CREATE TABLE [dbo].[Astronauts]
(
	[ID]			INT IDENTITY (1,1)	NOT NULL,
	[AstronautName]			NVARCHAR (50)		NOT NULL,
	[Birthday]		NVARCHAR (50)		NOT NULL,
	[CountryID]		INT					NOT NULL,
	CONSTRAINT [PK_dbo.Astronauts] PRIMARY KEY CLUSTERED ([ID] ASC),
	CONSTRAINT [FK_dbo.Astronaut_dbo.Countries_ID] FOREIGN KEY ([CountryID]) REFERENCES [dbo].[Countries] ([ID])
);

CREATE TABLE [dbo].[Crews]
(
	[ID]				INT IDENTITY (1,1)	NOT NULL,
	[Position]			NVARCHAR (50)		NOT NULL,		
	[AstronautID]		INT					NOT NULL,
	[MissionID]			INT					NOT NULL,					
	CONSTRAINT [PK_dbo.Crews] PRIMARY KEY CLUSTERED ([ID] ASC),
	CONSTRAINT [FK_dbo.Crews_dbo.Astronauts_ID] FOREIGN KEY ([AstronautID]) REFERENCES [dbo].[Astronauts] ([ID]),
	CONSTRAINT [FK_dbo.Crews_dbo.Missions_ID] FOREIGN KEY ([MissionID]) REFERENCES [dbo].[Missions] ([ID])
);