/*Maxime douylliez tp5*/

/*requete1:*/
select a.acoul as coulrare from Articles a where not exists(select acoul from Articles where acoul=a.acoul group by acoul having count(*)!=1);

/*requete2:*/
select a.aid as redNotGreen from Articles a where acoul='rouge' and not exists (select aid from Articles where aid=a.aid and acoul='vert');

/*requete3:*/
select a.aid as deuxFournMin from Articles a where exists (select aid from Catalogue where aid=a.aid group by aid having max(fid)!=min(fid) );

/*requete4:*/
select c.fid  as celuiquivendtout from Catalogue c  natural join Articles group by fid having not exists(select aid from Articles where aid!=all(select aid from Catalogue where fid=c.fid));

/*requete5:*/
select a.anom as redOnly from Articles a where acoul='rouge' and not exists(select anom from Articles where anom=a.anom and acoul!='rouge');

/*requete8:*/
select f.fnom as cher from Fournisseurs f natural join Catalogue where not exists(select fnom from Catalogue natural join Fournisseurs where f.fnom like fnom group by fnom having max(prix) <(select max(prix) from Catalogue natural join Fournisseurs where f.fnom not like fnom));

/*requete9:*/
select a.aid as deuxFournMinEncore from Articles a where exists (select aid from Catalogue where aid=a.aid group by aid having max(fid)!=min(fid) )order by aid asc;

/*requete10:*/
select f.fnom from fournisseurs f where not exists ( select * from articles a where a.aid != all(select aid from catalogue c where c.fid = f.fid) and a.acoul = 'rouge')

/*requete11:*/
select distinct f.fnom, a1.anom  from fournisseurs f join catalogue c1 on (f.fid = c1.fid) join articles a1 on (c1.aid = a1.aid) where exists (	select * from articles a2 natural join catalogue c2 where a1.anom = a2.anom and c2.fid = f.fid and a1.acoul != a2.acoul)

/*requete12:*/
select anom,max(prix),min(prix) from Articles natural join Catalogue  group by aid having count(*)>1;

/*requete15:*/
/*requete16:*/
/*requete17:*/
/*requete18:*/
/*requete19:*/
/*requete20:*/

