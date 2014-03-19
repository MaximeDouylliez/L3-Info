package action;

public class Attente extends Action {
	private int temps;
	
	public Attente(int d) {
		super();
		this.temps = d;
	}
	
	protected void contenuFaire() {
		this.temps--;
		if (this.temps==0)
			this.etat = true;
	}
}
