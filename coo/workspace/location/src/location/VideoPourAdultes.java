package location;

public class VideoPourAdultes extends Video {
	public VideoPourAdulte(float d, String t, int tarif){
		super(d,t,tarif);
		setContrainte(new ContrainteAge(18));
	}

}
