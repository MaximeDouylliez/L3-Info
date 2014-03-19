package questionnaire;

public class AnswerFactory {
	protected Expert guichert=new ExpertText(null);
	public Answer<?> produitReponse(String s){
		return guichet.fabriqueReponse(s);
	}
	protected addExpert(Expert ex){
		ex.setSuccesseur(guichet);
		guichet=ex;
	}
	
	private AnswerFactory(){
		this.addExpert(new ExpertNumerique());
		this.addExpert(new ExpertYesNo());
	}
	public static final AnswerFactory USINE= new AnswerfACTORY();

}
