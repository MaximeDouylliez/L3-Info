public class Attente extends Action{
    protected int delai;
    public Attente(int d){
	super();
	this.delai=d;
    }
    protected void contenuFaire(){
	this.delai--;
	if(this.delai==0)this.etat=EtatAction.TERMINE
			     }
}