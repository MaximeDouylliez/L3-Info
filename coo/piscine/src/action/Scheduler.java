package action;


public class Scheduler extends Ordonnanceur {
	protected void contenuFaire() {
		try { Action a = this.lesActions.get(0);
			if (a.estTerminee()) {
				this.lesActions.remove(0);
				if (this.lesActions.isEmpty())
					this.etat=true;
			}
			else {
				this.lesActions.add(a);
			}
		}
		catch (Exception e) {
			// à compléter
		}
	}
}
