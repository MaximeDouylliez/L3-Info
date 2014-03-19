/**
 * @author douylliez
 */

package oie;


public class CaseTeleportation extends CaseNormale {


	/**
	 * 
	 */
	protected int destination;
	
	/**
	 * Initialisation de la case teleportation vers une destination
	 */
	public CaseTeleportation(int index, int destination){
		super(index);
		this.destination = destination;
	}
	
		
	/**
	 * Consequence de la teleportation
	 */
	public int consequence(int d){
		return this.destination + d;
	}
	
	
	
	
	
	public int getDest() {
		return destination;
	}
	
	

	public void setDest(int dest) {
		this.destination = dest;
	}


		
	/** retour utilisateur
	 */
	public String getMessage(){
		return this.getPlayer().toString()+" is in cell "+this.index+ "," +this.getPlayer().toString()
		+" throws "+ this.diceGet()+", reaches cell " + consequence(this.diceGet());	
	}

}
