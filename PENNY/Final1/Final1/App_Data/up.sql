CREATE TABLE [dbo].[Encodings]
(
     
    [ID] INT IDENTITY (1,1) NOT NULL,
	[Codec] NVARCHAR (50)	NOT NULL,

CONSTRAINT [PK_dbo.Encodings] PRIMARY KEY CLUSTERED ([ID] ASC),
);


CREATE TABLE [dbo].[Tags]
(

    [ID] INT IDENTITY (1,1) NOT NULL,
	[TagName] NVARCHAR (50)	NOT NULL,
	
	CONSTRAINT [PK_dbo.Tags] PRIMARY KEY CLUSTERED ([ID] ASC),
);

CREATE TABLE [dbo].[Videos]
(
     [ID] INT IDENTITY (1,1) NOT NULL,
	 [Title] NVARCHAR (50)	NOT NULL,
	 [MyDescription] VARCHAR (3000)	NOT NULL,
	 [FrameRate] INT NOT NULL,
	 [EncodingID] INT    NOT NULL,

CONSTRAINT [PK_dbo.Videos] PRIMARY KEY CLUSTERED ([ID] ASC),
CONSTRAINT [FK_dbo.Videos_dbo.Encodings_ID] FOREIGN KEY ([EncodingID]) REFERENCES [dbo].[Encodings] ([ID])

);

CREATE TABLE [dbo].[VideoTags]	
(

[ID] INT IDENTITY (1,1) NOT NULL,
[VideoID] INT  NOT NULL,
[TagID] INT  NOT NULL,

CONSTRAINT [PK_dbo.VideoTags] PRIMARY KEY CLUSTERED ([ID] ASC),
CONSTRAINT [FK_dbo.VideoTags_dbo.Videos_ID] FOREIGN KEY ([VideoID]) REFERENCES [dbo].[Videos] ([ID]),
CONSTRAINT [FK_dbo.VideoTags_dbo.Tags_ID] FOREIGN KEY ([TagID]) REFERENCES [dbo].[Tags] ([ID])

);



	


	




