
INSERT INTO [dbo].[Encodings](Codec)
	VALUES
	('MP4'),
    ('OGG'),
	('WEBM'),
    ('H.264');

INSERT INTO [dbo].[Tags](TagName)
	VALUES
	('music'),
     ('pixar'),
     ('baby'),
   ('fortnite'),
    ('aimbot'),
    ('animated');

	INSERT INTO [dbo].[Videos](Title, MyDescription, FrameRate, EncodingID )
	VALUES
	('Ariana Grande - thank u, next',                       'thank u, next (Official Video)',   24, 1),
    ('Incredible 2 - Edna & Jack-Jack Deleted Scenes',      'Thanks for watching my channel',   60, 4),
    ('Using Aimbot In A 3v1 Against Playground Squeakers',  'Thank you to Uyrifx for the amazing intro! His instagram name is @uyrifx if you want an amazing intro like ours (good price)! He has done great work, even some intros for Fortnite Poggers!', 120, 4);


	INSERT INTO [dbo].[VideoTags](VideoID, TagID)
	VALUES
   (2,2),
   (2,3),
   (1,1),
   (3,4),
   (1,6);
	GO
