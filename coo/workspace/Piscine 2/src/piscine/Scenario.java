package piscine;
public class Scenario extends Ordonnanceur{
    protected void contenuFaire(){
	//	this.lesActions.get(0).faire();
    	
	try{
		Action a =this.lesActions.get(0); 
		a.faire();
	    if(a.isTermine()){
		this.lesActions.remove(0);
	    if(	this.lesActions.isEmpty())
		this.etat=EtatAction.TERMINE;
	    }			
	    }
	catch(ActionTermineException e){}
    }
    }
    