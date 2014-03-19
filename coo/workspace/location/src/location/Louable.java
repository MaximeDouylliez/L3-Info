package location;

public abstract class Louable {
	
	protected float tarifJournee;
protected Contrainte contrainte= new ContrainteNulle();

public Louable(float tarif);

public estDisponible(){return true};
public estLouable(Personne p){return contrainte.estSatisfaite(p);}
public getTarifJournee();
public setContrainte(Contrainte c);

}
