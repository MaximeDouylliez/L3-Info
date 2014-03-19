package piscine;
public class Scheduler extends Ordonnanceur{
    protected void contenuFaire(){
	//	this.lesActions.get(0).faire();
    	
	try{
		Action a =this.lesActions.get(0); 
		a.faire();
	    if(!(a.isTermine()))
		this.lesActions.add(a);
	    this.lesActions.remove(0);
	
	    if(	this.lesActions.isEmpty())
		this.etat=EtatAction.TERMINE;
	    			
	    }
	catch(ActionTermineException e){}
    }
}
    