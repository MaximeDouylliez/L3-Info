package location;

import Location.Louable;

public abstract class Vehicule extends Louable {
	
	public Vehicule(int tarif){super(tarif); contrainte=new ContraintePermis();}

}
