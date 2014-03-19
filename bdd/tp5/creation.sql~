drop table articles cascade;
drop table fournisseurs cascade;
drop table catalogue ;

CREATE TABLE Articles(
aid int primary key,                     
anom varchar(30), 
acoul varchar(15) 
);

--

CREATE TABLE Fournisseurs(
fid int primary key,
fnom varchar(30),
fad varchar(70)
);

--

CREATE TABLE Catalogue(
fid int references Fournisseurs,   
aid int references Articles,
prix real ,
primary key (fid,aid)
);

