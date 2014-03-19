package location;

public class Video extends Louable {
protected float duree;
protected String titre;

public Video(float d,String t,int tarif){
	super(tarif);
	duree=d;
	titre=t;
}

}

