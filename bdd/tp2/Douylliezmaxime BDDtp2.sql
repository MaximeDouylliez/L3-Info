Create TYPE TypeVehicule as ENUM ('voiture','moto','camion','avion','helicoptere','velo','kart','motocyclette');

Create table Vehicule (
idImatriculation serial PRIMARY KEY,
marque varchar(15),
type TypeVehicule not null);

create table Conducteur (
idConducteur serial PRIMARY KEY,
numSecu int UNIQUE,
nom varchar(15),
prenom varchar(15));

create table Voyage (
idVoyage serial PRIMARY KEY,
description varchar(50),
villeDepart varchar (10),
dateDepart date,
villeArrive varchar (10),
dateDArrive date,
idImatriculation int REFERENCES Vehicule on update cascade);

create table VoyageConducteur(
idConducteur int REFERENCES Conducteur on update cascade,
idVoyage int REFERENCES Voyage on update cascade,
PRIMARY KEY(idConducteur,idVoyage))


