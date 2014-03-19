package ressource;

public class LibererRessource<R extends Ressource> extends ActionRessource<R> {

	public LibererRessource(GestionnaireDeRessource<R> g, RessourceUser<R> u) {
		super(g, u);
	}

	protected void contenuFaire() {
		try {this.gestionnaire.libereRessource(this.utilisateur.getRessource());
			this.etat=true;
			this.utilisateur.resetRessource();
		}
		catch (InvalidRessourceException e) {
			// TODO Auto-generated catch block
			//e.printStackTrace();
			// propager l'exception
		}
	}
}