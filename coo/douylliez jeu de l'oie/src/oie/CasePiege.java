/**
 * @author douylliez
 */


package oie;


public class CasePiege extends CaseNormale {

		
		/**
		 * Initialisation de la case piege
		 */
		public CasePiege(int index){
			super(index);
		}

		
		/**
		 * check
		 */
		public boolean canBeLeft(){
			return false;	
		}


		
		/**
		 * retour utilisateur
		 */
		public String getMessage(){
			return this.getPlayer().toString()+" is in cell "+this.index+", "+ this.getPlayer().toString()+" cannot play.";	
		}


}
