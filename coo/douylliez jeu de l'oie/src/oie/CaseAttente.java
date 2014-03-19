/**
 * @author douylliez
 */

package oie;


public class CaseAttente extends CaseNormale {

	
	protected int nbToursAttente;
	
	protected int nbToursAttendu;

	
	/**
	 * initialise la case attente
	 */
	public CaseAttente(int index, int nbToursAttente){
		super(index);
		this.nbToursAttente = nbToursAttente;
		this.nbToursAttendu = 0;
	}
	
	/**
	 *retourne le nombre de tours a attendre
	 */
	public int getNbToursAttente() {
		return nbToursAttente;
	}

	/**
	 *definit le nombre de tours d'attente
	 */
	public void setNbToursAttente(int nbToursAttente) {
		this.nbToursAttente = nbToursAttente;
	}

	
	/**
	 *retourn le nombre de tours 
	 */
	public int getNbToursAttendu() {
		return nbToursAttendu;
	}
	/**
	 * modifie le nombre de tours attendu
	 */
	public void setNbToursAttendu(int nbToursAttendu) {
		this.nbToursAttendu = nbToursAttendu;
	}
	/**
	 * check
	 */
	public boolean canBeLeft(){
		return (this.nbToursAttente == this.nbToursAttendu++);	
	}
	/**
	 * initialise la punition de tour
	 */
	public void setPlayer(Player player){
		super.setPlayer(player);
		this.nbToursAttendu = 0;
	}	
	/**
	 * et on lui applique une consequence du a cette case
	 */
	public int consequence(int diceThrow){
		return super.consequence(diceThrow);
	}

	
	/**
	 * Message pour l utilisateur afin de lui prevenir le nombre de tour restant a attendre
	 */
	public String getMessage(){
		if (this.canBeLeft()){
			return super.getMessage();
		}
		else{
			return this.getPlayer().toString()+" is in cell "+this.getIndex()+", "+this.getPlayer().toString()
			+" ne peut pas jouer, "+this.getPlayer().toString()+" doit attendre "+(this.nbToursAttente-this.nbToursAttendu+2)+" tours";
		}
		
	}
}
