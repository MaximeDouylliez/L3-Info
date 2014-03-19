/**
 * @author Guillaume Catteaux Florian Laigle
 */

package oie;

/**
 * Interface for the cells of the game. 
 * Note that there can be only one player by cell, 
 * the starting cell (index 0) excepted.
 */
public interface Cell {
	/**
	 * @return true if and only if the player in this cell can freely
	 * leaves the cell, else he must wait for another player to reach this cell 
	 * or wait a given number of turns
	 */
	public boolean canBeLeft();

	/** returns the index of this cell */
	public int getIndex();

	/**
	 * returns the index of the cell really reached by a player when he reaches this cell
	 * @param diceThrow the result of the dices when the player reaches this cell
	 * @return the index of the cell effectively reached when a player reaches this cell after the
	 *         given throw of dices
	 */
	public int consequence(int diceThrow);

	/** returns <tt>true</tt> iff a player is in this cell */
	public boolean isBusy();

	/** sets a player in this cell */
	public void setPlayer(Player player);

	/** gets the player in this cell <tt>null</tt> if none */
	public Player getPlayer();

		
	/**
	 * Prend un message
	 */
	public abstract String getMessage();


	/**
	 * Tirage du des
	 */
	public abstract int diceGet();

				
	/**
	 * selectionne un des
	 */
	public abstract void setDice(int d);
				
			
		
}// Cell
