package ressource;

import action.Action;

public abstract class ActionRessource<R extends Ressource> extends Action {
	protected GestionnaireDeRessource<R> gestionnaire;
	protected RessourceUser<R> utilisateur;
	
	public ActionRessource (GestionnaireDeRessource<R> g, RessourceUser<R> u) {
		this.gestionnaire = g;
		this.utilisateur = u;
	}
	@Override
	protected void contenuFaire() {
		// TODO Auto-generated method stub

	}

}
