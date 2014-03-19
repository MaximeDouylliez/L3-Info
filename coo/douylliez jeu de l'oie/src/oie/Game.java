/**
 * @author Guillaume Catteaux Florian Laigle
 */

package oie;

import java.util.List;


public class Game {

	/**
	 * Des joueurs
	 */
	protected List<Player> thePlayers;

	/**
	 * Un support de jeu
	 */
	protected Board board;
	
	/**
	 * Un joueur courant
	 */
	protected Player currentPlayer;
	
	/**
	 * Le jeu
	 */
	public Game(Board board,List<Player> thePlayers ){
		this.board = board;
		this.thePlayers = thePlayers;
	}
		
	/**
	 * Ajouter un joueur
	 */
	public void addPlayer(Player p){
		this.thePlayers.add(p);
	}
			
	
	public List<Player> getThePlayers() {
		return thePlayers;
	}

	
	public void setThePlayers(List<Player> thePlayers) {
		this.thePlayers = thePlayers;
	}


	public Board getBoard() {
		return board;
	}

	public void setBoard(Board board) {
		this.board = board;
	}	
	
	
	/**
	 * Jouer
	 */
	public void play(){
		
		int indiceFin,dice;
		boolean fin;
		fin = false;
		Cell currentCell,gagnant;
		int i;
		i = 0;
		while (!fin){
			
			i = (i+1)%this.thePlayers.size();
			this.currentPlayer = this.thePlayers.get(i);
			dice = this.currentPlayer.twoDicesThrow();
			currentCell = this.currentPlayer.getCell();
			
			
			
			if (currentCell.canBeLeft()){
				indiceFin = currentCell.consequence(dice);
				currentCell.setDice(dice);
				gagnant = this.board.getCell(indiceFin);
				fin = (indiceFin == this.board.getNbOfCells());
				
				
				if (this.currentPlayer.getCell() instanceof CaseZero){
					CaseZero casezero = (CaseZero)this.currentPlayer.getCell();
					System.out.println(casezero.getMessage(i));
				}
				else{
					System.out.println(currentCell.getMessage());
				}
		        
				
				
				
		        if (gagnant.isBusy()){
		        	System.out.println(gagnant.getPlayer().toString()+" is sent to cell "+currentCell.getIndex());
					currentCell.setPlayer(gagnant.getPlayer());
					gagnant.getPlayer().setCell(currentCell);
					this.currentPlayer.setCell(gagnant);
					gagnant.setPlayer(this.currentPlayer);
										
				}
				else{
					this.currentPlayer.setCell(gagnant);
					gagnant.setPlayer(currentPlayer);
					currentCell.setPlayer(null);
				}
		        
		        
		        
		        
		        if (fin){
					System.out.println(this.currentPlayer.toString()+"has won              case 63 atteinte partie finie . ");
				}
			}
			else {
				System.out.println(currentCell.getMessage());
			}
		}
	}
	
	
	
}
