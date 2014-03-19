package ressource;

import java.util.NoSuchElementException;

public class PrendreRessources <R extends Ressource> extends ActionRessource<R> {
	
	public PrendreRessources(GestionnaireDeRessource<R> g, RessourceUser<R> u) {
		super(g, u);
		
	}

	protected void contenuFaire() {
		try { R valeur = this.gestionnaire.fournitRessource();
			this.utilisateur.setRessource(valeur);
			this.etat=true;
		}
		catch (NoSuchElementException e) {
			//à compléter
		}
		
	}
}
