package action;


public class Scenario extends Ordonnanceur {
	protected void contenuFaire() {
		try { Action a = this.lesActions.get(0);
			a.faire();
			if (a.estTerminee()) {
				this.lesActions.remove(0);
				if (this.lesActions.isEmpty())
					this.etat=true;
			}
		}
		catch (ActionTermineeException e) {
			// à compléter
		}
	}
}
