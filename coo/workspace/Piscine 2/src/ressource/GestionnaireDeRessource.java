package ressource;

import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

public abstract class GestionnaireDeRessource<R extends Ressource> {
	protected List<R> disponibles = new ArrayList<R>();
	protected List<R> occupees = new ArrayList <R>();
	
	public GestionnaireDeRessource (int n) {
		for (int i = 0; i < n; i++) 
			this.disponibles.add(this.createRessource());
	}
	
	protected abstract R createRessource();
	
	public R fournitRessource() throws NoSuchElementException {
		if (disponibles.isEmpty())
				throw new NoSuchElementException();
		R valeur = disponibles.get(0);
		disponibles.remove(0);
		occupees.add(valeur);
		return valeur;
	}
	
	public void libereRessource(R r) throws RessourceInvalidException {
		if (!this.occupees.contains(r))
			throw new RessourceInvalidException();
		this.occupees.remove(r);
		this.disponibles.add(r);
	}
}
