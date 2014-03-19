package location;

public class Chambre extends Louable {
protected int numero;

public Chambre(int numero,int tarif){
	super(tarif);
	contrainte=new ContrainteCaution(tarif);
}
	
	
}
