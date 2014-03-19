package action;

import java.util.ArrayList;
import java.util.List;


public abstract class Ordonnanceur extends Action {
	protected List<Action> lesActions = new ArrayList<Action>();
	
	public void add(Action a) {
		this.lesActions.add(a);
	}
	
	public void faire() throws ActionTermineeException {
		if (this.lesActions.isEmpty())
			throw new ActionTermineeException();
		super.faire();
	}
	@Override
	protected void contenuFaire() {
		// TODO Auto-generated method stub

	}

}
