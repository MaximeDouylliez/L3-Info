package location;

public class ContrainteAge implements Contrainte {
	protected int ageMin;
	public ContrainteAge(int a){ this.age=a;}
public estSatisfaite(Personne p){return p.getAge()>this.ageMin}
}
