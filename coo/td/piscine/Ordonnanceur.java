public abstract class Ordonnanceur extends Action{

    protected List<Action> lesActions=new ArrayList<Action>();

    public void add(Action a){
	this.lesActions.add(a);
    }
    public void faire()throws ActionTerminException{
	if(this.lesActions.isEmpty())throw new ActionTermineException();
	super.faire();
    }
}