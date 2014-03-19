public class LettreChange  extend courrier{
    protected double cout;
    protected int pourcentage;


    public double calculCout(){ return cout+pourcentage*getContenu();}
    public void action(){
	super.action();
	this.destinataire.envoiCourrier(new LettreSimple(expediteur,destinataire,'merci'+this.toString())new Merci(expediteur,destinataire,this));