drop table BandeDessinee cascade;
drop table Auteur cascade;
drop table Blog cascade;
drop table BlogAuteur;


/* serial s'incremente tout seul donc pas besoin de préciser unique*/

create table BandeDessinee(
bdId serial PRIMARY KEY,
titre varchar(20)unique,
nbChapitre int,
nbPage int);

create table Auteur(
nbSecu int PRIMARY KEY UNIQUE NOT NULL,
nom varchar(20),
prenom varchar(20),
dateN date,
lieuN varchar(20));

create table Blog(
idBlog serial PRIMARY KEY,
description varchar(200),
datePrevu date,
datePublication date,
url varchar(100) UNIQUE,
bdId int  REFERENCES BandeDessinee);

create table BlogAuteur(
nbSecu int  REFERENCES Auteur,
idBlog int  REFERENCES Blog,
PRIMARY KEY(nbSecu,idBlog));
