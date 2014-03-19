package courrier;
public abstract class courrier<t>{
    protected Habitant expediteur;
    protected Habitant destinataire;
    protected t contenu;
    protected int cout;

    public double  calcultcout(){}
    public Habitant getExpediteur(){}
    public t getContenu(){}
    public void action(){}