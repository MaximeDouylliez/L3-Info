package location;

public class ContrainteCaution implements Contrainte {
	
	protected int Montant;
	
public estSatisfaite(Personne p){return p.accepteCaution(montant);}

public ContrainteCaution(int montant)
{ this.montant=montant;}
}
