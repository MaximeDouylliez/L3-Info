package location;

public class ContrainteMultiple implements Contrainte {
	protected List<Contrainte> lesContraintes;
	
	public COntrainteMultiples(List<Contrainte>l){this.lesContraintes=l;}
	
	public estSatisfaite(Personne p){
		for(Contrainte c:lesContraintes){
		if(!c.estSatisfaite(p) return false;}
	return true;
	}

	public addContrainte(Contrainte c){lesContrainte.add(c);}
	
}
