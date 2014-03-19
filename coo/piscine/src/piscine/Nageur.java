package piscine;

import action.*;
import ressource.*;


public class Nageur extends Scenario{
	private String nom;
	private GestionnaireDePaniers panier;
	private GestionnaireDeCabines cabine;
	private RessourceUser<Panier> panierUser;
	private RessourceUser<Cabine> cabineUser;
	private int deshabillage;
	private int baignade;
	private int rhabillage;
	
	public Nageur (String nom, GestionnaireDePaniers panier, GestionnaireDeCabines cabine, int d, int b, int r) {
		this.panierUser = new RessourceUser<Panier>();
		this.cabineUser = new RessourceUser<Cabine>();
		this.nom = nom;
		this.panier = panier;
		this.cabine = cabine;
		this.deshabillage = d;
		this.baignade = b;
		this.rhabillage = r;
	}
	
	protected void contenuFaire() {
		this.add((new PrendreRessources<Panier> (panier, panierUser)));
		this.add((new PrendreRessources<Cabine> (cabine, cabineUser)));
		this.add(new Attente(this.deshabillage));
		this.add(new LibererRessource<Cabine> (cabine, cabineUser));
		this.add(new Attente(this.baignade));
		this.add((new PrendreRessources<Cabine> (cabine, cabineUser)));
		this.add(new Attente(this.rhabillage));
		this.add(new LibererRessource<Cabine> (cabine, cabineUser));
		this.add(new LibererRessource<Panier> (panier, panierUser));
	}
}
