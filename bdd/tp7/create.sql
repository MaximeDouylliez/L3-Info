douylliez maxime

drop table Artiste cascade;
drop table Spectacle cascade;
drop table Interpretation;



create table Artiste(Nom varchar(50) PRIMARY KEY,Datenaissance DATE,Lieunaissance varchar(50));

create table Spectacle (Cod serial PRIMARY KEY, Titre varchar(50),An DATE,Type varchar(50),Realisateur varchar(50) REFERENCES Artiste);

create table Interpretation(CodSpect serial REFERENCES Spectacle,Acteur varchar(50) REFERENCES Artiste,Role varchar(50),Protagoniste boolean,PRIMARY KEY (CodSpect,Acteur));
