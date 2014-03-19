/**
 * @author douylliez 
 */

package oie;

import java.util.List;


public class CaseZero implements Cell {

	protected int index;
	
	protected List<Player> listePlayer;
	
	protected int dice;

	/**
	 * Initialisation de la case zero
	 */
	public CaseZero(List<Player> listPlayer){
		this.index = 0;
		this.listePlayer = listPlayer;
	}
	@Override
	public boolean canBeLeft() {
		// TODO Auto-generated method stub
		return true;
	}

	@Override
	public int consequence(int diceThrow) {
		// TODO Auto-generated method stub
		return diceThrow;
	}

		@Override
	public Player getPlayer() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean isBusy() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public void setPlayer(Player player) {
		// TODO Auto-generated method stub

	}

	
	

	public void setIndex(int index) {
		this.index = index;
	}


	@Override
	public int getIndex() {
		return index;
	}

	
	/**
	 * Liste des joueur sur zero, case où plusieur joueur peuvent y etre en meme temps
	 */
	public List<Player> getListPlayer() {
		return this.listePlayer;
	}


	public void setListPlayer(List<Player> listPlayer) {
		this.listePlayer = listPlayer;
	}
	/**
	 * Informe l'utilisateur des joueurs se trouvant sur cette case
	 */
	public String getMessage(int i){
		return this.listePlayer.get(i).toString()+" is in cell "+this.index+", "+this.listePlayer.get(i).toString()
		+" throws "+dice+", reaches cell " +this.consequence(this.diceGet());	
	}
	public String getMessage(){
		return "";
	}
	
	public int diceGet(){
		return this.dice;
	}
	
	/**
	 * Le des
	 */
	public void  setDice(int d){
		this.dice = d;
	}
}
