/*Maxime douylliez*/

drop table Fournisseur cascade;
drop table Piece cascade;
drop table Machine cascade;
drop table Composition cascade;
drop table Commande cascade;
drop view blop;


create table Fournisseur(
nomFournisseur varchar(20) PRIMARY KEY,
adresse varchar(20) DEFAULT 'inutile',
ville varchar(20),
tel int DEFAULT 0,
fax int DEFAULT 0
);

create table Piece(
idPiece serial PRIMARY KEY,
nomPiece varchar(20),
stock int default 5,
nomFournisseur varchar(20) REFERENCES Fournisseur
);

create table Machine(
nomMachine varchar(20)PRIMARY KEY,
prix int,
description varchar(100)
);

create table Composition(
nomMachine varchar(20) REFERENCES Machine,
idPiece int REFERENCES Piece,
qtePiece int,
PRIMARY KEY(nomMachine,idPiece)
);

create table Commande(
idCommande serial PRIMARY KEY,
dateCommande date,
machine varchar(20) REFERENCES Machine,
qteMachine int,
nomClient varchar(20)
);


insert into Fournisseur  values
('Recharges Agricoles',default,'Boulogne',default,default),
('MultiRoues',default,'Tourcoing',default,default),
('Pouce Vert',default,'Lille',default,default);

insert into Piece values
(default,'arbre' ,default,'Recharges Agricoles' ),
(default,'deroulement' ,default,'MultiRoues' ),
(default,'embrayage' ,default,'Recharges Agricoles' ),
(default,'roues' ,default,'MultiRoues' ),
(default,'structure primaire' ,default,NULL ),
(default,'van' ,default,NULL),
(default,'batteur' ,default,NULL),
(default,'ascenceur' ,default,'Pouce Vert' );

insert into Machine values
('Presse',35000,'Plus tu te presse, plus t es préssé choupinou'),
('Moissoneuse-batteuse',50000,'Et si je veux juste la batteuse Captain c est possible ?');

insert into Composition values
('Presse',1 ,1 ),
('Presse',2 ,10 ),
('Presse',3 ,4 ),
('Presse',4 ,4 ),
('Presse',5 ,1 ),
('Moissoneuse-batteuse',6 ,1 ),
('Moissoneuse-batteuse',7 ,1 ),
('Moissoneuse-batteuse',8 ,1 ),
('Moissoneuse-batteuse',4 ,4 ),
('Moissoneuse-batteuse',5 ,1 );

insert into Commande values
(default,'2009-03-15','Presse',15, 'Mécanique Lucien'),
(default,'2009-03-30','Presse',50, 'Saponnier'),
(default,'2009-04-30','Presse',10, 'Chicorée'),
(default,'2009-04-30','Moissoneuse-batteuse',30, 'Chicorée'),
(default,'2009-05-20','Moissoneuse-batteuse',1, 'Gremise');


/*requette 1:*/
select nomMachine,prix from Machine;
/*requette 2:*/
select nomFournisseur,ville from Piece natural join Fournisseur where nomPiece='roues';
/*requette 3:*/
select nomPiece as Piece_composant_la_presse,qtePiece as Qte from Piece natural join Composition where nomMachine='Presse';
/*requette 4:*/
select sum(qtePiece) from Composition where nomMachine='Presse';
/*requette 5:*/
select nomPiece from Composition natural join Piece where nomMachine='Presse' INTERSECT select nomPiece from Composition natural join Piece where nomMachine='Moissoneuse-batteuse';
/*requette 6:*/
/*cette requette ne renvoit pas le bon resultat...Van n'est pas reférencé dans deux table et le join ne marche pas pour cette valeur*/
select nomPiece as piece,qtePiece as quantité_nessessaire,nomFournisseur,ville from Fournisseur natural join Piece natural join Composition natural join Machine  where nomMachine='Moissoneuse-batteuse';
/*requette 7:*/
create view blop as select machine,qteMachine from Commande where dateCommande< '2009-05-01';
select machine,sum(qteMachine) from blop group by machine;
