
/**
 * @author douylliez
 */

package oie;

public class CaseOie extends CaseNormale {
	
	/**
	 * initialisation de la case oie
	 */
	public CaseOie(int index){
		super(index);
	}
	
		
	/**
	 */
	public int consequence(int d){
		return super.consequence(2*d);
	}
	/**
	 * retour utilisateur
	 */
	public String getMessage(){
		return this.getPlayer().toString()+" is in cell "+this.index+", "+ this.getPlayer().toString()
			+" throws "+ this.diceGet() +", reaches goose "+super.consequence(this.diceGet()) + " and jumps to "+this.consequence(this.diceGet());
	}

}
