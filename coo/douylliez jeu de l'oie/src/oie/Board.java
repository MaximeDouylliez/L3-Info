/**
 * @author douylliez
 */
package oie;

public abstract class Board {

protected int nbOfCells; // nous avons decider de le mettre en non-final, si nous voulons un jeu avec un nombre de case differents que le standart
protected Cell[] theCells;

	/**
	 * Initialise la map
	 */
	public Board(int nbOfCells){
		this.nbOfCells = nbOfCells;
		this.theCells = new Cell[nbOfCells];
	}
	
	/**
	 * creation des cases
	 */
	protected void initBoard(){
		for(int i = 0; i < this.nbOfCells;i++ ){
			switch(i){
				case 8:
				case 17:
				case 26:
				case 35:
				case 44:
				case 53:
					this.theCells[i] = new CaseOie(i+1);
					break;
				case 30:
				case 51:
					this.theCells[i] = new CasePiege(i+1);
					break;
				case 18:
					this.theCells[i] = new CaseAttente(i+1,2);
					break;
				case 5:
					this.theCells[i] = new CaseTeleportation(i+1,12);
					break;	
				case 41:
					this.theCells[i] = new CaseTeleportation(i+1,30);
					break;
				case 57:
					this.theCells[i] = new CaseTeleportation(i+1,1);
					break;
				default:
					this.theCells[i] = new CaseNormale(i+1);
					break;
			}
		}
	}
	
	/**
	 * retourne le nombre de case
	 */
	public int getNbOfCells() {
		return this.nbOfCells;
	}
	
	/**
	 * retourne une case
	 */
	public Cell[] getTheCells() {
		return theCells;
	}

	/**
	 * Selectionne une case 'voisine'
	 */
	public void setTheCells(Cell[] theCells) {
		this.theCells = theCells;
	}
	
	
	/**
	 * retourne une case selon son numero
	 */
	public Cell getCell(int numero){
		return this.theCells[numero-1];
	}
	

	/**
	 *selectionne une case donnee
	 */
	public void setNbOfCells(int nbOfCells) {
		this.nbOfCells = nbOfCells;
	}

	
		
	
}