package ressource;

public class GestionnaireDeCabines extends GestionnaireDeRessource<Cabine> {

	public GestionnaireDeCabines(int n) {
		super(n);
	}

	protected Cabine createRessource() {
		return new Cabine();
	}

}
