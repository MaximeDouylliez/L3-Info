/* insert qui marche */

insert into BandeDessinee values
(default,a,10,100),
(default,b,3,200);

insert into Auteur values
(1,'sartre','jean','1000-01-01','bidonville'),
(2,'giono','marc','2000-12-12','provence');

insert into Blog values
(default,'cool','1030-01-01','1030-01-01','www.babla.com',1);

insert into BlogAuteur values
(1,1);

/* insert qui violent les contraintes*/

/* deux titres identiques*/
insert into BandeDessinee values
(default,'a',10,100),
(default,'a',3,200);

/* meme numero de secu*/
insert into Auteur values
(1,'sartre','jean','1000-01-01','bidonville'),
(1,'giono','marc','2000-12-12','provence');

/* meme url*/
insert into Blog values
(default,'cool','1030-01-01','1030-01-01','www.babla.com',1);
(default,'cool la vie','2030-01-01','2031-01-01','www.babla.com',2);
