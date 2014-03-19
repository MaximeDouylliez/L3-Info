package ressource;

public class GestionnaireDePaniers extends GestionnaireDeRessource<Panier> {

	public GestionnaireDePaniers(int n) {
		super(n);
	}

	protected Panier createRessource() {
		return new Panier();
	}
	
}
