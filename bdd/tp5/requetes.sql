/*Maxime douylliez tp5*/

/*requete1:*/
select acoul  as coulrare from Articles group by acoul having count(acoul)=1;

/*requete2:*/
select aid as redNotGreen from Articles where acoul='rouge' EXCEPT select aid from Articles where acoul='vert';

/*requete3:*/
select aid as deuxFournMin from Articles natural join Catalogue group by aid having count(aid)>1;

/*requete4:*/
select fid  as celuiquivendtout from Catalogue group by fid having count(*) =(select count(*) from Articles);

/*requete5:*/
select anom as redOnly from Articles where acoul='rouge' EXCEPT select anom from Articles where acoul!='rouge';

/*requette6:*/
select anom,acoul,count(*) as nbFournisseur From Articles natural join Catalogue group by anom,acoul order by nbFournisseur;

/*requette7:*/
select acoul,SUM(prix)/count(*)as PrixMoyen from (select * from Catalogue except select * from Catalogue where aid=(select aid from Articles where anom='Ferrari F430')) as goal natural join Articles group by acoul having max(aid)!=min(aid) ;

/*requete8:*/
select fnom as cher from Fournisseurs natural join Catalogue order by  prix desc limit 1;

/*requete9:*/
select aid as deuxFournMinEncore from Catalogue natural join Fournisseurs group by aid having count(*)>1 order by aid asc;

/*requete10:*/
select fid from Articles natural join Catalogue group by fid,acoul having count(acoul='rouge')=(select count(*) from Articles where acoul = 'rouge');

/*requete11:*/
select fid,anom from Articles natural join Catalogue group by fid,anom having count(*)>1;

/*requete12:*/
select anom,max(prix),min(prix) from Articles natural join Catalogue  group by aid having count(*)>1;

/*requete13:*/
select count(*) as Nombre_Article from Articles natural join Catalogue group by fid order by count(*) desc limit 1;


/*requete14:*/
select fnom from Fournisseurs natural join Catalogue group by fnom having count(*)=(select count(*) as Nombre_Article from Articles natural join Catalogue group by fid order by count(*) desc limit 1);

/*requete15:*/
select anom from Catalogue natural join Articles group by anom having max(fid)=min(fid);

/*requete16:*/
select fnom from (select fid from Fournisseurs except select fid from Catalogue) as foo natural join Fournisseurs;


/*requete17:*/
select acoul from (select aid from Articles except select aid from Catalogue)as fo natural join Articles;


/*requete18:*/
select aid from Catalogue where prix>100 EXCEPT select aid from Catalogue where prix<100;


/*requete19:*/
select anom from(select aid from Catalogue natural join Fournisseurs where fnom ='kiventout' except select aid from Catalogue natural join Fournisseurs where fnom!='kiventout')as f natural join Articles;


/*requete20:*/
select aid from Catalogue natural join Fournisseurs where fad like '%USA' except Select aid from Catalogue natural join Fournisseurs where fad  not like '%USA';
