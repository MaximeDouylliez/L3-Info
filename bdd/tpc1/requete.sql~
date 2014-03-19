/* q6*/
select sum(nbPage) from( select titre,nbPage from BandeDessinee natural join Blog natural join BlogAuteur natural join Auteur where lieuN like 'France') as bdFrance;

/* q7*/
select bdId from BandeDessinee except select bdId from BandeDessinee natural join Blog natural join BlogAuteur natural join Auteur where( nom not like 'Liberation' or datePublication not like'2012-**-**');
