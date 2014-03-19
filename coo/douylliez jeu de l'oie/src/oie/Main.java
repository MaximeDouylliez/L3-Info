/**
 * @author douylliez
 */

package oie;
import java.util.*;


public class Main {

	public static void main(String[] args) {
		
		List<Player> list = new ArrayList<Player>();
		int i=0;
		Scanner tmp = new Scanner(System.in);
		String entree = "";
		String fin = "FIN";
		
		
		System.out.println("Entrez les noms de joueurs, ecrire FIN pour terminer la saisie");
		
		
		while(!entree.equals(fin)){
			System.out.print("J"+ i++ +" : ");
			entree = tmp.next();
			
			
			if(!entree.equals(fin))
				list.add(new Player(entree,null));
		}
		CaseZero casezero = new CaseZero(list);
		
		
		for ( Player p : list){
			p.setCell(casezero);
		}
		
		
		
		if (list.size() == 0){
				System.out.println("Aucun joueur, avec qui jouer ?");
		}
		else{
			Board board = new ClassicBoard(63);
			board.initBoard();
			Game game = new Game(board,casezero.getListPlayer());
			game.play();
		}
	}
}
