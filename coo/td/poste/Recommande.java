public class Recommande{
    protected int pourcentage;
    public  double calculCout(){
	pourcentage*getContenu().calculCout();
    }
    public void action(){
	getContenu.action();
	this.destinataire.envoieCourrier(new AccuseReception(expediteur,destinataire,this));
    }