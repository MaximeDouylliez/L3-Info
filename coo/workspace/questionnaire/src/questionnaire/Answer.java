package questionnaire;

public class Answer {
	protected T bonnereponse;
	public  Answer(T reponse);
	public boolean accept(String s);
	public T getValue();
	public boolean isCorrect(String s);

}
