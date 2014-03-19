package action;

public abstract class Action {
	protected boolean etat = false;
	
	public void faire() throws ActionTermineeException {
		if (this.etat)
			throw new ActionTermineeException();
		this.contenuFaire();
	}
	
	protected abstract void contenuFaire();
	
	public boolean estTerminee() {
			return this.etat;
	}
}
