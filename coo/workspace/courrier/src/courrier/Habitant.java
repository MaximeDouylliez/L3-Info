package courrier;



public class Habitant{
    private float  soldeCompte;
    private Adresse adresse;

    public Habitant{
    }

    public Adresse  getAdresse(){
	return this.adresse;
    }
    public void recoitCourrier(Courrier courrier){
	courrier.action();
    }
}
    public void envoieCourrier(Courrier courrier){
	this.getAdresse().getVille().posteLettre(c);
}
    public void debiter(double montant){}
    public void crediter(double montant){} 