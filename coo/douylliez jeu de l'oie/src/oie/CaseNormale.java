/**
 * @author douylliez
 */

package oie;

public class CaseNormale implements Cell {
	
	protected Player player;
	
	protected int index;
	
	protected int dice;

	/**
	 * Constructeur de la case normal
	 */
	public CaseNormale(int index){
		this.index = index;
		this.player = null;
	}
	
	@Override
	/**
	 * check
	 */
	public boolean canBeLeft() {
		return true;
	}

	@Override
	/**
	 * Consequence du des selon la case, si il depasse 63, il doit donc reculer
	 */
	public int consequence(int diceThrow) {
		// TODO Auto-generated method stub
		if ((this.index + diceThrow) <= 63){
			return (this.index + diceThrow);
		}
		else{
			return (63 -(this.index + diceThrow -63));
		}
	}

	@Override
	/**
	 *Retourne l'index de la case
	 */
	public int getIndex() {
		return this.index;
	}

	/**
	 *Retourne le joueur qui est en cours de jeu
	 */
	@Override
	public Player getPlayer() {
		return this.player;
	}
	/**
	 * check
	 */
	@Override
	public boolean isBusy() {
		// TODO Auto-generated method stub
		return (this.player != null);
	}

	/**
	 *Selectionne le joueur
	 */
	@Override
	public void setPlayer(Player player) {
		this.player = player;
	}


	/**
	 * lui donne un Index
	 */
	public void setIndex(int index) {
		this.index = index;
	}

		
	/**
	 * retour utilisateur
	 */
	public String getMessage(){
		return this.getPlayer().toString()+" is in cell "+this.index+", "+this.getPlayer().toString()
		+" throws "+ this.diceGet() +", reaches cell "
		+this.consequence(this.diceGet());	
	}
	
	public int diceGet(){
		return this.dice;
	}
	
	public void  setDice(int d){
		this.dice = d;
	}
}
