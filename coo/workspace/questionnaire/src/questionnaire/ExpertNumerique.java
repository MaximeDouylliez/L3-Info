package questionnaire;

public class ExpertNumerique {
	public ExpertNumerique(Expert n){
		super(n);}
	
	protected Answer<?> reponseLocale(String s){
		try{ int i=Integer.parseInt(s);
		return new AnswerNumerique(s);
		}
		catch(Exception e){ return null;}
	}

}
