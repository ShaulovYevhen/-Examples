USE [first_db]
GO
/****** Object:  Table [dbo].[Films]    Script Date: 26.09.2020 14:50:56 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Films](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[Director] [nvarchar](50) NULL,
	[Genre] [nvarchar](50) NULL,
	[Price] [money] NOT NULL
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Films] ON 

INSERT [dbo].[Films] ([ID], [Name], [Director], [Genre], [Price]) VALUES (1, N'Terminator', N'Pedro', N'Fighter', 100.0000)
INSERT [dbo].[Films] ([ID], [Name], [Director], [Genre], [Price]) VALUES (2, N'Mortal Combat', N'Ivanov', N'Drama', 123.0000)
INSERT [dbo].[Films] ([ID], [Name], [Director], [Genre], [Price]) VALUES (3, N'Film', NULL, NULL, 111.0000)
SET IDENTITY_INSERT [dbo].[Films] OFF
GO
